#include <algorithm>
#include <list>
#include "executable.h"

TEST(operator_move) {
    Typegen t;

    for(size_t i = 0; i < TEST_ITER; i++) {
        Memhook mh_mem_loss;

        {
            const size_t n = i == 0 ? 0 : t.range(0x999ULL);
            const size_t prev_n = t.range(0x999ULL);

            List<int> ll(n);
            std::list<int> gt_ll(n);

            t.fill(gt_ll.begin(), gt_ll.end());
            std::copy(gt_ll.cbegin(), gt_ll.cend(), ll.begin());

            List<int> ll_cpy(prev_n);
            t.fill(ll_cpy.begin(), ll_cpy.end());

            Memhook mh;
            ll_cpy = std::move(ll);
            
            // List object should be in an "empty" state
            ASSERT_EQ(0ULL, ll.size());
            ASSERT_TRUE(ll.begin() == ll.end());

            // Ensure pointers are wired correctly
            // Should handle empty case & stack nodes properly
            ASSERT_FALSE(--(++ll.begin()) == ll_cpy.begin());
            ASSERT_FALSE(++(--ll.end()) == ll_cpy.end());
            ASSERT_FALSE(ll.end() == ll_cpy.begin());

            ASSERT_EQ(gt_ll.size(), ll_cpy.size());

            // No new allocs and previous memory should have been freed
            ASSERT_EQ(0ULL, mh.n_allocs());
            ASSERT_EQ(prev_n, mh.n_frees());

            {
                // Check consistancy of copy
                auto it = ll_cpy.cbegin();
                auto gt_it = gt_ll.cbegin();

                while(gt_it != gt_ll.cend())
                    ASSERT_EQ(*gt_it++, *it++);
                
                while(gt_it != gt_ll.cbegin())
                    ASSERT_EQ(*--gt_it, *--it);
            }

            // Try to mutilate object, should be protected
            Memhook mutilate_mh;
            ll_cpy = std::move(ll_cpy);
            ASSERT_EQ(0ULL, mutilate_mh.n_allocs());
            ASSERT_EQ(0ULL, mutilate_mh.n_frees());

            {
                // Check consistancy of copy
                auto it = ll_cpy.cbegin();
                auto gt_it = gt_ll.cbegin();

                while(gt_it != gt_ll.cend())
                    ASSERT_EQ(*gt_it++, *it++);
                
                while(gt_it != gt_ll.cbegin())
                    ASSERT_EQ(*--gt_it, *--it);
            }
        }
    
        // No memory should be lost
        ASSERT_EQ(mh_mem_loss.n_frees(), mh_mem_loss.n_allocs());
    }
}
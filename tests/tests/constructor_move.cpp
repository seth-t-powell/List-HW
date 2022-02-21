#include <algorithm>
#include <list>
#include "executable.h"

TEST(constructor_move) {
    Typegen t;

    for(size_t i = 0; i < TEST_ITER; i++) {
        Memhook mh_mem_loss;

        {
            const size_t n = i == 0 ? 0 : t.range(0x999ULL);
            List<int> ll(n);
            std::list<int> gt_ll(n);

            t.fill(gt_ll.begin(), gt_ll.end());
            std::copy(gt_ll.cbegin(), gt_ll.cend(), ll.begin());

            Memhook mh;
            List<int> ll_cpy = std::move(ll);
            
            ASSERT_EQ(0ULL, ll.size());
            ASSERT_TRUE(ll.begin() == ll.end());
            
            // Ensure pointers are wired correctly
            // Should handle empty case & stack nodes properly
            ASSERT_FALSE(--(++ll.begin()) == ll_cpy.begin());
            ASSERT_FALSE(++(--ll.end()) == ll_cpy.end());
            ASSERT_FALSE(ll.end() == ll_cpy.begin());

            ASSERT_EQ(0ULL, mh.n_allocs());
            ASSERT_EQ(0ULL, mh.n_frees());

            // Check consistancy
            ASSERT_EQ(gt_ll.size(), ll_cpy.size());

            auto it = ll_cpy.cbegin();
            auto gt_it = gt_ll.cbegin();

            while(gt_it != gt_ll.cend())
                ASSERT_EQ(*gt_it++, *it++);
            
            while(gt_it != gt_ll.cbegin())
                ASSERT_EQ(*--gt_it, *--it);
        }

        // No memory should be lost
        ASSERT_EQ(mh_mem_loss.n_frees(), mh_mem_loss.n_allocs());
    }
}
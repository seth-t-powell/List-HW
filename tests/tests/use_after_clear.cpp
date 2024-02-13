#include "executable.h"
#include "box.h"
#include <list>

TEST(use_after_clear) {
    Typegen t;
    for(size_t i = 0; i < TEST_ITER; i++) {
        size_t sz = i == 0 ? 0 : t.range<size_t>(100);
        
        const int value = t.get<int>();

        List<int> * ll = new List<int>(sz, value);

        ll->clear();

        std::list<int> shadow;

        for (size_t j = 0; j < 20; ++j) {
            int next_push = t.get<int>();
            if (i & 1) {
                ll->push_front(next_push);
                shadow.push_front(next_push);
            } else {
                ll->push_back(next_push);
                shadow.push_back(next_push);
            }
        }


        for (size_t j = 0; j < 20; ++j) {
            int next_push = t.get<int>();
            if (i & 1) {
                ll->push_back(next_push);
                shadow.push_back(next_push);
            } else {
                ll->push_front(next_push);
                shadow.push_front(next_push);
            }
        }

        // Verify that list contents are correct

        ASSERT_EQ(ll->size(), shadow.size());

        auto test_it = ll->begin();
        auto std_it = shadow.begin();
        for (; test_it != ll->end() && std_it != shadow.end(); ++test_it, ++std_it) {
            ASSERT_EQ_(*std_it, *test_it, "Inconsistency iterating forward.");
        }

        // If only one iterator has reached the end
        bool iters_different = (test_it == ll->end()) ^ (std_it == shadow.end());
        ASSERT_TRUE(!iters_different);

        for (; --test_it, --std_it, true;) {
            ASSERT_EQ_(*std_it, *test_it, "Inconsistency iterating backward.");
            if (test_it == ll->begin() || std_it == shadow.begin()) {
                break;
            }
        }

        iters_different = (test_it == ll->begin()) ^ (std_it == shadow.begin());
        ASSERT_TRUE(!iters_different);

        delete ll;
    }
}

#include "executable.h"
#include "box.h"

TEST(clear_and_empty) {
    Typegen t;
    for(size_t i = 0; i < TEST_ITER; i++) {
        size_t sz = t.range<size_t>(100);

        Memhook mh;

        const int value = t.get<int>();

        List<int> * ll = new List<int>(sz, value);

        // Each node should be allocated individually
        ASSERT_EQ(sz + 1, mh.n_allocs());
        ASSERT_EQ(sz, ll->size());
        ASSERT_FALSE(ll->empty());

        ll->clear();

        ASSERT_EQ(sz, mh.n_frees());
        ASSERT_EQ(0ULL, ll->size());
        ASSERT_TRUE(ll->empty());

        delete ll;
    }
}

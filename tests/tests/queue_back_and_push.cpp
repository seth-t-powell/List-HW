#include "executable.h"
#include "Queue"
#include <queue>

TEST(queue_front) {
    Typegen t;

    for (size_t i = 0; i < TEST_ITER; i++) {
        const size_t n = t.range(0x999ULL);
        std::queue<int> gt;
        Queue<int> q;

        Memhook mh;

        for (size_t i = 0; i < n; i++) {
            const int val = t.get<int>();
            gt.push(val);
            q.push(val);
            ASSERT_TRUE(gt.back(), q.back());
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());
        
    }

    for (size_t i = 0; i < TEST_ITER; i++) {
        const size_t n = t.range(0x999ULL);
        std::queue<int> gt;
        Queue<int> q;
        const Queue<int>& qr = q;

        Memhook mh;

        for (size_t i = 0; i < n; i++) {
            const int val = t.get<int>();
            gt.push(val);
            q.push(val);
            ASSERT_TRUE(gt.back(), qr.back());
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());
        
    }
}
#include "executable.h"
#include "Queue.h"
#include <queue>

TEST(queue_back_and_push) {
    Typegen t;

    for (size_t i = 0; i < TEST_ITER; i++) {
        const size_t n = t.range(0x999ULL);
        std::vector<int> gt(n);
        t.fill(gt.begin(), gt.end());
        Queue<int> q;

        Memhook mh;

        for (size_t i = 0; i < n; i++) {
            q.push(gt[i]);
            ASSERT_EQ(gt[i], q.back());
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());
        
    }

    for (size_t i = 0; i < TEST_ITER; i++) {
        const size_t n = t.range(0x999ULL);
        std::vector<int> gt(n);
        t.fill(gt.begin(), gt.end());
        Queue<int> q;
        const Queue<int>& qr = q;

        Memhook mh;

        for (size_t i = 0; i < n; i++) {
            q.push(gt[i]);
            // Uses const reference back
            ASSERT_EQ(gt[i], qr.back());
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());
        
    }
}
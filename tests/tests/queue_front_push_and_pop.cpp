#include "executable.h"
#include "Queue"
#include <queue>

TEST(queue_front_push_and_pop) {
    Typegen t;

    for (size_t i = 0; i < TEST_ITER; i++) {
        const size_t n = t.range(0x999ULL);
        std::queue<int> gt;
        Queue<int> q;

        Memhook mh;

        // Populate both queues by pushing elements to them
        for (size_t i = 0; i < n; i++) {
            const int val = t.get<int>();
            // Uses copy push
            gt.push(val);
            q.push(val);
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());

        while (!gt.empty()) {
            // Compare the fronts each time, then pop
            ASSERT_EQ(gt.front(), q.front());
            gt.pop();
            q.pop();
            ASSERT_EQ(gt.size(), q.size());
        }

        ASSERT_EQ(n, mh.n_frees());
        ASSERT_EQ(0ULL, q.size());
        
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
        }

        ASSERT_EQ(n, mh.n_allocs());
        ASSERT_EQ(n, q.size());

        while (!gt.empty()) {
            // Uses const reference front to compare
            ASSERT_EQ(gt.front(), qr.front());
            gt.pop();
            q.pop();
            ASSERT_EQ(gt.size(), q.size());
        }

        ASSERT_EQ(n, mh.n_frees());
        ASSERT_EQ(0ULL, q.size());
        
    }
}
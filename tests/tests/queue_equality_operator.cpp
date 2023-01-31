#include "executable.h"
#include "Queue.h"

#include <vector>

TEST(queue_equality_operator) {
    Typegen t;

    for (size_t i = 0; i < TEST_ITER; i++) {

        const size_t n = t.range(10, 0x999ULL);
        std::vector<int> gt_1(n);
        t.fill(gt_1.begin(), gt_1.end());

        // Checking two equivalent queues
        Queue<int> q1;
        Queue<int> q2;

        {
            Memhook mh;

            for (size_t j = 0; j < n; j++) {
                q1.push(gt_1[i]);
                q2.push(gt_1[i]);
            }

            ASSERT_EQ(gt_1.size(), q1.size());
            ASSERT_EQ(gt_1.size(), q2.size())
            ASSERT_EQ(2 * n, mh.n_allocs());
        }

        ASSERT_TRUE(q1 == q2);

        std::vector<int> gt_2(n);
        t.fill(gt_2.begin(), gt_2.end());

        Queue<int> q3;

        {
            Memhook mh;

            for (size_t j = 0; j < n; j++) {
                q3.push(gt_2[i]);
            }

            ASSERT_EQ(gt_2.size(), q3.size());
            ASSERT_EQ(n, mh.n_allocs());
        }

        ASSERT_FALSE(q1 == q3);
        ASSERT_FALSE(q3 == q2);

        // Comparisons between queues of different sizes should be false
        const size_t n_smaller = t.range(0, n - 1);
        std::vector<int> gt_3(n_smaller);
        t.fill(gt_3.begin(), gt_3.end());

        Queue<int> q4;

        {
            Memhook mh;

            for (size_t j = 0; j < n_smaller; j++) {
                q4.push(gt_3[i]);
            }

            ASSERT_EQ(gt_3.size(), q4.size());
            ASSERT_EQ(n, mh.n_allocs());
        }

        ASSERT_FALSE(q1 == q4);
        ASSERT_FALSE(q4 == q3);

    }
}
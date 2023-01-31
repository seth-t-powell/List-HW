#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

template <typename T, typename Container = List<T>>
class Queue {
    public:
        // Aliases for accessing data types outside of the class
        using container_type  = Container;
        using value_type      = typename Container::value_type;
        using size_type       = typename Container::size_type;
        using reference       = typename Container::reference;
        using const_reference = typename Container::const_reference;

    private:
        Container c;

    public:
        // The constructors, destructor, and assignment operators are done for you
        Queue() = default;
        Queue(const Queue& other) = default;
        Queue(Queue&& other) = default;
        ~Queue() = default;
        Queue& operator=(const Queue& other) = default;
        Queue& operator=(Queue&& other) = default;

        reference front() { /* TODO */ }
        const_reference front() const { /* TODO */ }
        reference back() { /* TODO */ }
        const_reference back() const { /* TODO */ }

        bool empty() const { /* TODO */ }
        size_type size() const { /* TODO */ }

        void push(const value_type& value) { /* TODO */ }
        void push(value_type&& value) { /* TODO */ }
        void pop() { /* TODO */ }
        void swap(Queue& other) noexcept { /* TODO */ }
};

template <typename T, typename Container>
bool operator==(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) { /* TODO */ }

#endif
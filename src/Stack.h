#include "List.h"

template <typename T, typename Container = List<T>>
class Stack {
    public:
        // Aliases for accessing data types outside of the class
        using container_type  = Container;
        using value_type      = Container::value_type;
        using size_type       = Container::size_type;
        using reference       = Container::reference;
        using const_reference = Container::const_reference;

    private:
        Container c;

    public:
        // The constructors, destructor, and assignment operators are done for you
        Stack() = default;
        Stack(const Stack& other) = default;
        Stack(Stack&& other) = default;
        ~Stack() = default;
        Stack& operator=(const Stack& other) = default;
        Stack& operator=(Stack&& other) = default;

        reference top() { /* TODO */ }
        const_reference top() const { /* TODO */ }

        bool empty() const { /* TODO */ }
        size_type size() const { /* TODO */ }

        void push(const value_type& value) { /* TODO */ }
        void push(value_type&& value) { /* TODO */ }
        void pop() { /* TODO */ }
        void swap(Stack& other) noexcept { /* TODO */ }
};

template <typename T, typename Container>
bool operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) { /* TODO */ }
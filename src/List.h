#pragma once

#include <cstddef> // size_t
#include <iterator> // std::bidirectional_iterator_tag
#include <list> // std::bidirectional_iterator_tag

template <class T>
class List {
    private:
    struct Node {
        T data;
        Node *next, *prev;
        explicit Node(const T& data = T{}, Node* prev = nullptr, Node* next = nullptr)
        : data{data}, prev{prev}, next{next}
        {
        }
    };

    template <typename pointer_type, typename reference_type>
    class basic_iterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = pointer_type;
        using reference         = reference_type;
    private:
        using Node = typename List<value_type>::Node;

        Node* node;
    public:
        basic_iterator() = default;
        basic_iterator(const basic_iterator&) = default;
        basic_iterator(basic_iterator&&) = default;
        ~basic_iterator() = default;
        basic_iterator& operator=(const basic_iterator&) = default;
        basic_iterator& operator=(basic_iterator&&) = default;

        explicit basic_iterator(Node* ptr) noexcept;

        reference operator*() const;
        pointer operator->() const;

        // Prefix Increment: ++a
        basic_iterator& operator++();
        // Postfix Increment: a++
        basic_iterator operator++(int);
        // Prefix Decrement: --a
        basic_iterator& operator--();
        // Postfix Decrement: a--
        basic_iterator operator--(int);

        bool operator==(const basic_iterator& other) const noexcept;
        bool operator!=(const basic_iterator& other) const noexcept;
    };

public:
    using value_type      = T;
    using size_type       = size_t;
    using difference_type = ptrdiff_t;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;
    using iterator        = basic_iterator<pointer, reference>;
    using const_iterator  = basic_iterator<const_pointer, const_reference>;

private:
    Node head, tail;

public:
    List();
    List( size_type count, const T& value );
    explicit List( size_type count );
    List( const List& other );
    List( List&& other );
    ~List();
    List& operator=( const List& other );
    List& operator=( List&& other ) noexcept;

    reference front();
    const_reference front() const;
	
    reference back();
    const_reference back() const;
	
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;

    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

    bool empty() const noexcept;

    size_type size() const noexcept;

    void clear() noexcept;

    iterator insert( const_iterator pos, const T& value );
    iterator insert( const_iterator pos, T&& value );

    iterator erase( const_iterator pos );

    void push_back( const T& value );
    void push_back( T&& value );

    void pop_back();
	
    void push_front( const T& value );
	void push_front( T&& value );

    void pop_front();
};

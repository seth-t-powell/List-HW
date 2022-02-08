#pragma once

#include <cstddef> // size_t
#include <iterator> // std::bidirectional_iterator_tag

template <class T>
class List {
    private:
    struct Node {
        T data;
        Node *next, *prev;
        explicit Node(Node* prev = nullptr, Node* next = nullptr)
        : data{}, next{next}, prev{prev} {}
        explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : data{data}, next{next}, prev{prev} {}
        explicit Node(T&& data, Node* prev = nullptr, Node* next = nullptr)
        : data{std::move(data)}, next{next}, prev{prev} {}
    };

    template <typename pointer_type, typename reference_type, typename node_type>
    class basic_iterator {
        // FIXME: Awful solution to get access to Node within List but not externally. Works but makes me regret every line of code I've written.
        template <typename P, typename R, typename N>
        friend typename List<T>::Node* getNode(const basic_iterator<P, R, N>&);
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using value_type        = T;
        using difference_type   = ptrdiff_t;
        using pointer           = pointer_type;
        using reference         = reference_type;
    private:
        using Node = node_type;

        Node* node;
    public:
        basic_iterator() = default;
        basic_iterator(const basic_iterator&) = default;
        basic_iterator(basic_iterator&&) = default;
        ~basic_iterator() = default;
        basic_iterator& operator=(const basic_iterator&) = default;
        basic_iterator& operator=(basic_iterator&&) = default;

        explicit basic_iterator(Node* ptr) noexcept {
            // TODO - Don't forget the list initialier
        }

        reference operator*() const {
            // TODO
        }
        pointer operator->() const {
            // TODO
        }

        // Prefix Increment: ++a
        basic_iterator& operator++() {
            // TODO
        }
        // Postfix Increment: a++
        basic_iterator operator++(int) {
            // TODO
        }
        // Prefix Decrement: --a
        basic_iterator& operator--() {
            // TODO
        }
        // Postfix Decrement: a--
        basic_iterator operator--(int) {
            // TODO
        }

        bool operator==(const basic_iterator& other) const noexcept {
            // TODO
        }
        bool operator!=(const basic_iterator& other) const noexcept {
            // TODO
        }
    };

    template <typename P, typename R, typename N>
    friend typename List<T>::Node* getNode(const basic_iterator<P, R, N>& it) { return const_cast<typename List<T>::Node*>(it.node); }

public:
    using value_type      = T;
    using size_type       = size_t;
    using difference_type = ptrdiff_t;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;
    using iterator        = basic_iterator<pointer, reference, Node>;
    using const_iterator  = basic_iterator<const_pointer, const_reference, const Node>;

private:
    Node head, tail;
    size_type _size;

public:
    List() {
        // TODO - Don't forget the list initialier
    }
    List( size_type count, const T& value ) {
        // TODO - Don't forget the list initialier
    }
    explicit List( size_type count ) {
        // TODO - Don't forget the list initialier
    }
    List( const List& other ) {
        // TODO - Don't forget the list initialier
    }
    List( List&& other ) {
        // TODO - Don't forget the list initialier
    }
    ~List() {
        // TODO
    }
    List& operator=( const List& other ) {
        // TODO
    }
    List& operator=( List&& other ) noexcept {
        // TODO
    }

    reference front() {
        // TODO
    }
    const_reference front() const {
        // TODO
    }
	
    reference back() {
        // TODO
    }
    const_reference back() const {
        // TODO
    }
	
    iterator begin() noexcept {
        // TODO
    }
    const_iterator begin() const noexcept {
        // TODO
    }
    const_iterator cbegin() const noexcept {
        // TODO
    }

    iterator end() noexcept {
        // TODO
    }
    const_iterator end() const noexcept {
        // TODO
    }
    const_iterator cend() const noexcept {
        // TODO
    }

    bool empty() const noexcept {
        // TODO
    }

    size_type size() const noexcept {
        // TODO
    }

    void clear() noexcept {
        // TODO
    }

    iterator insert( const_iterator pos, const T& value ) {
        // TODO
    }
    iterator insert( const_iterator pos, T&& value ) {
        // TODO
    }

    iterator erase( const_iterator pos ) {
        // TODO
    }

    void push_back( const T& value ) {
        // TODO
    }
    void push_back( T&& value ) {
        // TODO
    }

    void pop_back() {
        // TODO
    }
	
    void push_front( const T& value ) {
        // TODO
    }
	void push_front( T&& value ) {
        // TODO
    }

    void pop_front() {
        // TODO
    }
};

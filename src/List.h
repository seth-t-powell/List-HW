#pragma once

#include <cstddef> // size_t
#include <iterator> // std::bidirectional_iterator_tag
#include <type_traits> // std::is_same, std::enable_if

template <class T>
class List {
    private:
    struct Node {
        Node *next, *prev;
        T data;
        explicit Node(Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev} {}
        explicit Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev}, data{data} {}
        explicit Node(T&& data, Node* prev = nullptr, Node* next = nullptr)
        : next{next}, prev{prev}, data{std::move(data)} {}
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
        friend class List<value_type>;
        using Node = typename List<value_type>::Node;

        Node* node;

        explicit basic_iterator(Node* ptr) noexcept : node{ptr} {}
        explicit basic_iterator(const Node* ptr) noexcept : node{const_cast<Node*>(ptr)} {}

    public:
        basic_iterator() {this->node = nullptr;};
        basic_iterator(const basic_iterator&) = default;
        basic_iterator(basic_iterator&&) = default;
        ~basic_iterator() = default;
        basic_iterator& operator=(const basic_iterator&) = default;
        basic_iterator& operator=(basic_iterator&&) = default;

        reference operator*() const {
            return this->node->data;
        }
        pointer operator->() const {
            //return &(this->node->data);
        }

        // Prefix Increment: ++a
        basic_iterator& operator++() {
            //prefix:
            //this->node = this->node->next;
            return *this;
        }
        // Postfix Increment: a++
        basic_iterator operator++(int) {
            //make a copy basic iterator:
            basic_iterator temp = *this;
            //this->node = this->node->next;
            return temp;
        }
        // Prefix Decrement: --a
        basic_iterator& operator--() {

            this->node = this->node->prev;
            return *this;
        }
        // Postfix Decrement: a--
        basic_iterator operator--(int) {
            basic_iterator temp = *this;
            //this->node = this->node->prev;
            return temp;
        }

        bool operator==(const basic_iterator& other) const noexcept {
            if(&this->node == &other.node){
                return true;
            }
            return false;
            
        }
        bool operator!=(const basic_iterator& other) const noexcept {
            if(&this->node != &other.node){
                return true;
            }
            return false;
        }
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
    size_type _size;

public:
    List() : head(Node()), tail(Node()), _size(0) {

    }
    List( size_type count, const T& value ) : head(Node()), tail(Node()), _size(count) {
        //need to create new nodes:
        Node* A = new Node(value, &head, &tail);
        head.next = A;
        tail.prev = A;
        for(int i = 1; i < _size; i++){
            Node* B = new Node(value, tail.prev, &tail);
            tail.prev = B;
        }
        
    }
    explicit List( size_type count ) {
        // TODO - Don't forget initialize the list beforehand
    }
    List( const List& other ) {
        // TODO - Don't forget initialize the list beforehand
    }
    List( List&& other ) {
        // TODO - Don't forget initialize the list beforehand
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
        return const_iterator(head.next);
    }

    iterator end() noexcept {
        // TODO
    }
    const_iterator end() const noexcept {
        // TODO
    }
    const_iterator cend() const noexcept {
        return const_iterator(tail.prev);
    }

    bool empty() const noexcept {
        // TODO
    }

    size_type size() const noexcept {
        return _size;
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

    /*
      You do not need to modify these methods!
      
      These method provide the non-const complement 
      for the const_iterator methods provided above.
    */
    iterator insert( iterator pos, const T & value) { 
        return insert((const_iterator &) (pos), value);
    }

    iterator insert( iterator pos, T && value ) {
        return insert((const_iterator &) (pos), std::move(value));
    }

    iterator erase( iterator pos ) {
        return erase((const_iterator&)(pos));
    }
};


/*
    You do not need to modify these methods!

    These method provide a overload to compare const and 
    non-const iterators safely.
*/
 
namespace {
    template<typename Iter, typename ConstIter, typename T>
    using enable_for_list_iters = typename std::enable_if<
        std::is_same<
            typename List<typename std::iterator_traits<Iter>::value_type>::iterator, 
            Iter
        >{} && std::is_same<
            typename List<typename std::iterator_traits<Iter>::value_type>::const_iterator,
            ConstIter
        >{}, T>::type;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator==(const Iterator & lhs, const ConstIter & rhs) {
    return (const ConstIter &)(lhs) == rhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator==(const ConstIter & lhs, const Iterator & rhs) {
    return (const ConstIter &)(rhs) == lhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator!=(const Iterator & lhs, const ConstIter & rhs) {
    return (const ConstIter &)(lhs) != rhs;
}

template<typename Iterator, typename ConstIter>
enable_for_list_iters<Iterator, ConstIter, bool> operator!=(const ConstIter & lhs, const Iterator & rhs) {
    return (const ConstIter &)(rhs) != lhs;
}
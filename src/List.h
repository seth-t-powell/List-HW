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
            return (this->node->data);
        }
        pointer operator->() const {
            return &(this->node->data);
        }

        // Prefix Increment: ++a
        basic_iterator& operator++() {
            if(node->next == nullptr){
                return *this;
            }
            node = node->next;
            return *this;
        }
        // Postfix Increment: a++
        basic_iterator operator++(int) {
            basic_iterator temp = *this;
            ++(*this);
            return temp;
        }
        // Prefix Decrement: --a
        basic_iterator& operator--() {
            if(node->prev == nullptr){
                return *this;
            }
            node = node->prev;
            return *this;
        }
        // Postfix Decrement: a--
        basic_iterator operator--(int) {
            basic_iterator temp = *this;
            --(*this);
            return temp;
        }

        bool operator==(const basic_iterator& other) const noexcept {
            if(node == other.node){
                return true;
            }
            return false;
            
        }
        bool operator!=(const basic_iterator& other) const noexcept {
            if(node != other.node){
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
        head.next = &tail;
        tail.prev = &head;

    }
    List( size_type count, const T& value ) : head(Node()), tail(Node()), _size(count) {
        //perform count pushbacks:
        if(_size != 0){
            Node* A = new Node(value, &head, &tail);
            head.next = A;
            tail.prev = A;
            for(size_t i = 1; i < _size; i++){
                Node* current = new Node(value, tail.prev, &tail);
                tail.prev->next = current;
                tail.prev = current;
            }
        }
        else{
            head.next = &tail;
            tail.prev = &head;
        }
    }
    explicit List( size_type count ) : head(Node()), tail(Node()), _size(count) {
        //perform count pushbacks:
        if(_size != 0){
            Node* A = new Node(T(), &head, &tail);
            head.next = A;
            tail.prev = A;
            for(size_t i = 1; i < _size; i++){
                Node* current = new Node(T(), tail.prev, &tail);
                tail.prev->next = current;
                tail.prev = current;
            }
        }
        else{
            head.next = &tail;
            tail.next = &head;
        }

    }
    List( const List& other ) : head(Node()), tail(Node()), _size(other._size) {
            head.next = &tail;
            tail.prev = &head;
            //need to use copy semantics:
            for(basic_iterator i = other.begin(); i != other.end(); i++){
                //get the data at others node:
                T info = *i;
                Node* A = new Node(info, tail.prev, &tail);
                tail.prev->next = A;
                tail.prev = A;
                
            }
        
    }
    //move constructor:
    List( List&& other) : head(Node()), tail(Node()), _size(other._size) {
        //go through the for loop:
        Node* current = other.head.next;
        head.next = &tail;
        tail.prev = &head;
        for(int i = 0; i < _size; i++){
            Node* tmp = current->next;
            current->next = &tail;
            current->prev = tail.prev;
            tail.prev->next = current;
            tail.prev = current;
            current = tmp;
        }
        other._size = 0;
        other.head.next = &other.tail;
        other.tail.prev = &other.head;

    }
    ~List() {
        for(int i = 0; i < _size; i++){
            Node* current = tail.prev->prev;
            delete tail.prev;
            tail.prev = nullptr;
            tail.prev = current;
        }
    }
    List& operator=( const List& other ) {
        if(this->begin() == other.begin()){
            return *this;
        }
        else{
            clear();
            head.next = &tail;
            tail.prev = &head;
            _size = other._size;
            //need to use copy semantics:
            for(basic_iterator i = other.begin(); i != other.end(); i++){
                //get the data at others node:
                T info = *i;
                Node* A = new Node(info, tail.prev, &tail);
                tail.prev->next = A;
                tail.prev = A;
                
            }
            return *this;
        }
    }
    //move operator:
    List& operator=( List&& other ) noexcept {
        if(this->begin() == other.begin()){
            return *this;
        }
        else{
            //create a new list to move everything into:
            clear();
            //go through the for loop:
            Node* current = other.head.next;
            head.next = &tail;
            tail.prev = &head;
            _size = other._size;
            for(int i = 0; i < _size; i++){
                Node* tmp = current->next;
                current->next = &tail;
                current->prev = tail.prev;
                tail.prev->next = current;
                tail.prev = current;
                current = tmp;
            }
            other._size = 0;
            other.head.next = &other.tail;
            other.tail.prev = &other.head;

        }
    }

    reference front() {
        return head.next->data;
    }
    const_reference front() const {
        return head.next->data;
    }
	
    reference back() {
        return tail.prev->data;
    }
    const_reference back() const {
        return tail.prev->data;
    }
	
    iterator begin() noexcept {
        return iterator(head.next);
    }
    const_iterator begin() const noexcept {
        return const_iterator(head.next);
    }
    const_iterator cbegin() const noexcept {
        return const_iterator(head.next);
    }

    iterator end() noexcept {
        return iterator(&tail);
    }
    const_iterator end() const noexcept {
        return const_iterator(&tail);
    }
    const_iterator cend() const noexcept {
        return const_iterator(&tail);
    }

    bool empty() const noexcept {
        return _size == 0;
    }

    size_type size() const noexcept {
        return _size;
    }

    void clear() noexcept {
        //completely clear:
        for(int i = 0; i < _size; i++){
            Node* current = tail.prev->prev;
            delete tail.prev;
            tail.prev = nullptr;
            tail.prev = current;
        }
        
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
        //add to the very end:
        Node* current = new Node(value, tail.prev, &tail);
        tail.prev->next = current;
        tail.prev = current;
        _size++;
    }
    void push_back( T&& value ) {
        //pushback with move:
        Node* current = new Node(std::move(value), tail.prev, &tail);
        tail.prev->next = current;
        tail.prev = current;
        _size++;
    }

    void pop_back() {
        //remove the element:
        Node* tmp = tail.prev->prev;
        delete tail.prev;
        tail.prev = nullptr;
        tail.prev = tmp;
        tmp->next = &tail;
        _size--;
    }
	
    void push_front( const T& value ) {
        // TODO
    }
	void push_front( T&& value ) {
        // TODO
    }

    void pop_front() {
        //remove front element:
        Node* tmp = head.next->next;
        delete head.next;
        head.next = nullptr;
        head.next = tmp;
        tmp->prev = &head;
        _size--;
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
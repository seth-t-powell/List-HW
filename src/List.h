#pragma once

#include <cstddef> // size_t
#include <list> // size_t

template <class T>
class List {
public:
    struct Node {
        Node* prev;
        T data;
        Node* next;
        Node(const T& data = T{}, Node* prev = nullptr, Node* next = nullptr)
        : prev{prev}, data{data}, next{next}
        {
        }
    };
    
private:
    Node head, tail;
public:
    List();
    ~List();
    List(const List<T>& other);
    List(List<T>&& other);
    List<T>& operator=(const List<T>& other);
    List<T>& operator=(List<T>&& other);

    T& at(size_t pos);
    const T& at(size_t pos) const;

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    [[nodiscard]] bool empty() const noexcept;

    [[nodiscard]] size_t size() const noexcept;

    void clear() noexcept;

    void push_back(const T& value);

    void pop_back();

    void push_front(const T& value);

    void pop_front();
};

template <class T>
List<T>::List() {
}

template <class T>
List<T>::~List() {
}

template <class T>
List<T>::List(const List<T>& other) {
}

template <class T>
List<T>::List(List<T>&& other) {
}

template <class T>
List<T>& List<T>::operator=(const List<T>& other) {
}

template <class T>
List<T>& List<T>::operator=(List<T>&& other) {
}

template <class T>
T& List<T>::at(size_t pos) {
}
template <class T>
const T& List<T>::at(size_t pos) const {
}

template <class T>
T& List<T>::operator[](size_t pos) {
}
template <class T>
const T& List<T>::operator[](size_t pos) const {
}

template <class T>
T& List<T>::front() {
}
template <class T>
const T& List<T>::front() const {
}

template <class T>
T& List<T>::back() {
}
template <class T>
const T& List<T>::back() const {
}

template <class T>
[[nodiscard]] bool List<T>::empty() const noexcept {
}

template <class T>
[[nodiscard]] size_t List<T>::size() const noexcept {
}

template <class T>
void List<T>::clear() noexcept {
}

template <class T>
void List<T>::push_back(const T& value) {
}

template <class T>
void List<T>::pop_back() {
}

template <class T>
void List<T>::push_front(const T& value) {
}

template <class T>
void List<T>::pop_front() {
}

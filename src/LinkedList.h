#pragma once

#include <cstddef> // size_t

template <class T>
class LinkedList {
public:
    typedef struct Node {
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
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList(LinkedList<T>&& other);
    LinkedList<T>& operator=(const LinkedList<T>& other);
    LinkedList<T>& operator=(LinkedList<T>&& other);

    T& at(size_t pos);
    const T& at(size_t pos) const;

    T& operator[](size_t pos);
    const T& operator[](size_t pos) const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    bool empty() const noexcept;

    size_t size() const noexcept;

    void clear() noexcept;

    void push_back(const T& value);

    void pop_back();

    void push_front(const T& value);

    void pop_front();
};

template <class T>
LinkedList<T>::LinkedList() {
}

template <class T>
LinkedList<T>::~LinkedList() {
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) {
}

template <class T>
LinkedList<T>::LinkedList(LinkedList<T>&& other) {
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>&& other) {
}

template <class T>
T& LinkedList<T>::at(size_t pos) {
}
template <class T>
const T& LinkedList<T>::at(size_t pos) const {
}

template <class T>
T& LinkedList<T>::operator[](size_t pos) {
}
template <class T>
const T& LinkedList<T>::operator[](size_t pos) const {
}

template <class T>
T& LinkedList<T>::front() {
}
template <class T>
const T& LinkedList<T>::front() const {
}

template <class T>
T& LinkedList<T>::back() {
}
template <class T>
const T& LinkedList<T>::back() const {
}

template <class T>
bool LinkedList<T>::empty() const {
}

template <class T>
size_t LinkedList<T>::size() const {
}

template <class T>
void LinkedList<T>::clear() {
}

template <class T>
void LinkedList<T>::push_back(const T& value) {
}

template <class T>
void LinkedList<T>::pop_back() {
}

template <class T>
void LinkedList<T>::push_front(const T& value) {
}

template <class T>
void LinkedList<T>::pop_front() {
}

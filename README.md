# Linked Lists
In this assignment, you will program a Doubly Linked List class called `List` which parodies the [`std::list`](https://en.cppreference.com/w/cpp/container/list) class inherent to the Standard Template Library (STL) in C++.

Topics:

- Allocation (`new`) and Deallocation (`delete`)
- Stack and Heap Memory
- Bidirectional Iterators
  - Simplification of Random Access Iterators

The difficulty of the assignment is very close to that of the `Vector` assignment. You do not need to write as many functions, but there is much more nuanced work with the inner class `List::Node`.
## Getting started
Download this code by running the following command in the directory of your choice:
```sh
git clone https://github.tamu.edu/csce221/assignment-list.git && cd assignment-list
```
[OPTIONAL] Then set up CMake (if your editor does not do this for you):
```sh
cmake -S . -B build
```
Open the code in your editor of choice. For instance, if you use VS Code:
```sh
code .
```
*Note:* On OSX you may need to enable the `code` command in VS Code with <kbd>Cmd</kbd>+<kbd>Shift</kbd>+<kbd>P</kbd> and typing "shell command." You can select the option to install the command, and then the above command will work.
## Assignment
### Doubly Linked List Implementation
Implement the following [constructors](https://en.cppreference.com/w/cpp/container/list/list), [destructors](https://en.cppreference.com/w/cpp/container/list/%7Elist), and assignment operators [`operator=`](https://en.cppreference.com/w/cpp/container/list/operator%3D) which include the Rule of 5:
| Signature | Description | Time Complexity | Test Names |
| :--- | :--- | :--- | ---: |
| `List();` | Default constructor. Constructs an empty container.                                             | O(1) | TBD |
| `List( size_type count, const T& value );` | Constructs the container with `count` copies of elements with value `value`.                      | O(`count`) | TBD |
| `explicit List( size_type count );` | Constructs the container with `count` default-inserted instances of `T`. No copies are made.        | O(`count`) | TBD |
| `List( const List& other );` | **Copy constructor.** Constructs the container with the copy of the contents of `other`.          | O(`other.size()`) | TBD |
| `List( List&& other );` | **Move constructor.** Constructs the container with the contents of `other` using move semantics. | O(1) | TBD |
| `~List();` | **Destructs the List.** The destructors of the elements are called and the used storage is deallocated. Note, that if the elements are pointers, the pointed-to objects are not destroyed. | O(`size()`) | TBD |
| `List& operator=( const List& other );` | **Copy assignment operator.** Replaces the contents with a copy of the contents of `other`.  | O(max(`size()`, `other.size()`)) | TBD |
| `List& operator=( List&& other ) noexcept;` | **Move assignment operator.** Replaces the contents with those of `other` using move semantics (i.e. the data in `other` is moved from `other` into this container). `other` is in a valid but unspecified state afterwards.  | O(`size()`) | TBD |

Click the below function names to be taken to the reference page for the function.

Implement the following functions:
| Function Name | Brief Description | Time Complexity | Test Names |
| :--- | :--- | :--- | ---: |
| [`front`](https://en.cppreference.com/w/cpp/container/list/front) | access the first element | O(1) | TBD |
| [`back`](https://en.cppreference.com/w/cpp/container/list/back) | access the last element | O(1) | TBD |
| [`begin`](https://en.cppreference.com/w/cpp/container/list/begin) | returns an iterator to the beginning | O(1) | TBD |
| [`end`](https://en.cppreference.com/w/cpp/container/list/end) | returns an iterator to the end | O(1) | TBD |
| [`empty`](https://en.cppreference.com/w/cpp/container/list/empty) | checks whether the container is empty | O(1) | TBD |
| [`size`](https://en.cppreference.com/w/cpp/container/list/size) | returns the number of elements | O(1) | TBD |
| [`clear`](https://en.cppreference.com/w/cpp/container/list/clear) | clears the contents | O(`size()`) | TBD |
| [`insert`](https://en.cppreference.com/w/cpp/container/list/insert) | inserts elements | O(1) | TBD |
| [`erase`](https://en.cppreference.com/w/cpp/container/list/erase) | erases elements | O(1) | TBD |
| [`push_back`](https://en.cppreference.com/w/cpp/container/list/push_back) | adds an element to the end | O(1) | TBD |
| [`pop_back`](https://en.cppreference.com/w/cpp/container/list/pop_back) | removes the last element | O(1) | TBD |
| [`push_front`](https://en.cppreference.com/w/cpp/container/list/push_front) | inserts an element to the beginning | O(1) | TBD |
| [`pop_front`](https://en.cppreference.com/w/cpp/container/list/pop_front) | removes the first element | O(1) | TBD |

Implement `List::basic_iterator` which will create `iterator` and `const_iterator` for you. Write the following functions, which are **different from those of the Random Access Iterator from `Vector`.** If you reuse that code, it will not work at all because the list iterator is a **Bidirectional Iterator.**
| Signature | Description | Time Complexity | Test Names |
| :--- | :--- | :--- | :--- |
| `basic_iterator() noexcept;` | Default Constructor. We generate it automatically for you. | O(1) | TBD |
| `explicit basic_iterator(Node* ptr) noexcept;` | Parameterized Constructor. Set the managed pointer to the given `Node *`. | O(1) | TBD |
| `reference operator*() const;` | Dereference the pointer, returning a reference to the value in the managed node. **Do not return a reference to the `Node`, but instead return a reference to its managed data.** | O(1) | TBD |
| `pointer operator->() const;` | Return a pointer to the data managed by `Node`. | O(1) | TBD |
| `basic_iterator& operator++();` | **Prefix Increment.** Advance the iterator so that the managed `Node` is the next node in the list. Return a reference to this iterator. | O(1) | TBD |
| `basic_iterator operator++(int);` | **Postfix Increment.** Advance the iterator so that the managed `Node` is the next node in the list. Return a copy of this iterator from before it was advanced. | O(1) | TBD |
| `basic_iterator& operator--();` | **Prefix Increment.** Retreat the iterator so that the managed `Node` is the previous node in the list. Return a reference to this iterator. | O(1) | TBD |
| `basic_iterator operator--(int);` | **Prefix Increment.** Retreat the iterator so that the managed `Node` is the previous node in the list. Return a copy of this iterator from before it was retreated. | O(1) | TBD |
| `bool operator==(const basic_iterator& other) const noexcept;` | Compare two iterators and determine if they are equivalent. | O(1) | TBD |
| `bool operator!=(const basic_iterator& other) const noexcept;` | Compare two iterators and determine if they are not equivalent. | O(1) | TBD |

A possible implementation (followed by GCC) is to make:
```cpp
auto begin_it = begin(), end_it = end();
--begin_it; ++end_it;
begin_it == end(); // this is true
end_it == begin(); // this is true
```
Thus, the end loops back to the beginning and the beginning back to the end. **You do not have to do this, but it is an approach that you can follow to prevent Segfaults from going off the end of the list.** This form of `List` is very similar to a Circular Linked List.

#### Further Reading
- [Geeks For Geeks Doubly Linked List](https://www.geeksforgeeks.org/doubly-linked-list/)
- [Tutorials Point Double Linked List](https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_algorithm.htm)
- [Wikipedia Doubly Linked List](https://en.wikipedia.org/wiki/Doubly_linked_list)

### Shuffling Cards (Application of Doubly Linked List)

A standard playing card has two main pieces of information:
1. It has a Suit (Spades, Diamonds, Clubs, or Hearts)
2. It has a Number (2 - 10 inclusive) or a Face (Ace, Jack, Queen, King)
   - In many games the order is: Ace, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, and King

We provide for you a `struct Card` in [`Cards.h`](./src/Cards.h) and ask that you implement the following two functions in [`Cards.cpp`](./src/Cards.cpp):
| Signature | Description | Time Complexity | Test Names |
| :--- | :--- | :--- | :--- |
| `List<Card> buildDeck(std::ifstream file);` | Read from the file the cards and add them to a `List<Card>` in the order that they are read. |  | TBD |
| `List<Card> shuffle(const List<Card>& deck);` | Return a new list with the same cards in a shuffled order described below. | O(`deck.size()`) | TBD |

#### Simple Shuffling Algorithm
1. Create a new empty deck to which we will add cards as we shuffle them. We henceforth refer to this as the shuffled deck.
2. Iterate over the `deck`, and for each card, flip a coin (generate a random number).
3. If the result is Heads (even), add the card to the front of the shuffled deck; otherwise, add it to the back of the shuffled deck.
4. The `deck` has been shuffled into the shuffled deck when each card has been added. Return this shuffled deck from the `shuffle` function.

## Turn In
Submit the following files **and no other files** to Gradescope:
- [ ] [`Cards.cpp`](src/Cards.cpp)
- [ ] [`Cards.h`](src/Cards.h) - You may not have changed this file and that's fine
- [ ] [`List.h`](src/List.h)

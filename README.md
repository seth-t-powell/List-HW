# Linked Lists
The overall goal of this assignment is to begin programming data structures by implementing your own slimmed-down [`list`](https://en.cppreference.com/w/cpp/container/list).
## Getting started
1. You will want to download the starter code from GitHub or Canvas.
2. You will want to run the following command:
```
cmake -S . -B build
```
**Only run this command when you are in the directory (folder) into which you downloaded the code.**

3. Now, in VS Code, you can click the *Run* button to run the program. Use this to test the code that you wrote.
   - If you are experiencing difficulties, please `cd` into the directory for the project (not `src`) and then press the "Run" button again.
## Assignment
You are to implement `LinkedList`, which has the following functions:
| Function Name | Function Description                          | Time Complexity |
| ------------- | --------------------------------------------- | --------------- |
| `front`       | access the first element                      | O(1) |
| `back`        | access the last element                       | O(1) |
| `empty`       | checks whether the container is empty         | O(1) |
| `size`        | returns the number of elements                | O(1) |
| `clear`       | clears the contents                           | O(n) |
| `push_back`   | adds an element to the end                    | O(1) |
| `pop_back`    | removes the last element                      | O(1) |
| `push_front`  | inserts an element to the beginning           | O(1) |
| `pop_front`  | removes the first element                     | O(1) |

`LinkedList` is based on `list`, a data structure you may not have used. However, this data structure is suitable for manipulating its ends and for significant churn (insertions and deletions) where data in the middle is not easily accessible. You will see its use in Allocators (Heap Memory) and other data structures in this course.

Implement an inner class `iterator` in `LinkedList`. Your `iterator` should implement the following operations.

| Function Name | Function Description                                                                  |
| ------------- | ------------------------------------------------------------------------------------- |
| `operator*`   | access a reference to the data at the location of the current iterator                |
| `operator->`  | access a member or method of the data at the location of the current iterator         |
| `operator++`  | increment the iterator by one returning the old value (postfix) or new value (prefix) |
| `operator--`  | decrement the iterator by one returning the old value (postfix) or new value (prefix) |
| `operator==`  | compare two iterators to determine if they represent the same location                |
| `operator!=`  | compare two iterators to determine if they represent different locations              |

You will also want to add the following functions to `LinkedList`
| Function Name | Function Description                 | Link                                                                   |
| ------------- | ------------------------------------ | ---------------------------------------------------------------------- |
| `begin`       | returns an iterator to the beginning | [cppreference](https://en.cppreference.com/w/cpp/container/list/begin) |
| `end`         | returns an iterator to the end       | [cppreference](https://en.cppreference.com/w/cpp/container/list/end)   |

Feel free to do some reading about `const_iterator` and `reverse_iterator` in C++. However, you need only implement `iterator` for this assignment.

The benefits to these iterators are that your repeat accesses can be constant time. All iterator operations are constant time, which is why `operator+`, `operator+=`, `operator-`, and `operator-=` are only for `Vector` iterators. Think about why these iterator functions cannot occur in constant time for a `LinkedList`.

It may be helpful for you to consult:
- Reference for Iterators: https://en.cppreference.com/w/cpp/iterator/iterator
- Reference for Vector Begin: https://en.cppreference.com/w/cpp/container/vector/begin
- Reference for Vector End: https://en.cppreference.com/w/cpp/container/vector/end
- Reference for List Begin: https://en.cppreference.com/w/cpp/container/list/begin
- Reference for List End: https://en.cppreference.com/w/cpp/container/list/end

----

A `Card` is defined as a `std::pair<Suit, int>` where `Suit` is:
```cpp
enum class Suit { SPADES, DIAMONDS, CLUBS, HEARTS };
```
We also
```cpp
#define ACE   1
#define JACK  11
#define QUEEN 12
#define KING  13
```

Implement a function called `shuffle` which takes in an `std::vector` and shuffles the deck of cards by randomly inserting each card at either the beginning or end of a `LinkedList` which the function returns.

### Important Information
The header files are provided. You can change them, but you should not need to, aside from implementing the below [Bonus](#bonus---5-points).

### Bonus - 5 Points
Implement `const_iterator` and `reverse_iterator` and the additional `cbegin`, `cend`, `rbegin`, `rend`, `crbegin`, and `crend`.

## Turn In
Submit the modified `shuffle.h`, `shuffle.cpp`, and `LinkedList.h` to Gradescope.
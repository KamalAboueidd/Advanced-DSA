# Data Structures & Algorithms in C++

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=c%2B%2B)](https://isocpp.org/) [![DSA](https://img.shields.io/badge/Topics-DSA-orange)](#topics-covered) [![Status](https://img.shields.io/badge/Status-Active%20Learning-success)](#) [![License](https://img.shields.io/badge/License-MIT-blue.svg)](#)

Welcome to my **C++ Data Structures & Algorithms** reference repository! This repository contains structured study notes, visual diagrams, and clean C++ implementations designed for deep conceptual mastery and practical problem solving.

> **Learning Source:** Playlist by *MyCodeSchool* (YouTube)
>
> **Author:** Kamal Aboueid

## Repository Overview

This repository contains:
- Detailed conceptual notes (English & Arabic).
- Custom C++ implementations written and dry-run manually.
- Clean, documented C++ source code.

---

## Topics Covered

### 1. Introduction to Data Structures
- **Concept:** What is a Data Structure? Why do we need structured memory management?
- **Classification:** Linear (Arrays, Linked Lists, Stacks, Queues) vs. Non-Linear (Trees, Graphs).
- **Key Takeaways:**
    - Choosing the right data structure optimizes time complexity ($O(1)$, $O(n)$) and memory space.

### 2. Arrays vs. Lists (Contiguous vs. Sequential Memory)

> Arrays provide cache-friendly contiguous indexing, while Linked Lists offer flexible dynamic node allocation.
- **Arrays (Static):**
  - Continuous block of memory allocation.
  - Direct access via index in $O(1)$ time.
  - Fixed size (cannot dynamically grow/shrink at runtime).
- **Dynamic Arrays (`std::vector`):**
  - Dynamic size expansion with geometric doubling (amortized $O(1)$ push-back).
  - Cache locality preserves ultra-fast indexing ($O(1)$ direct access).

---
![Static vs Dynamic Array](dynamicarray.png)
![Array Complexity Overview](complexity.arr.jpg)


---

### 3. Linked List Theory
 > A **Linked List** is a linear data structure where elements (nodes) are stored in non-contiguous heap memory, linked dynamically through explicit pointer references.

 - Linked lists store elements dynamically in memory.
 - Each element is called a node.
 - Nodes are connected using pointers.
 - Linked List Representation
 - A linked list is represented by a pointer called head, which points to the first node of the list. Each node typically contains:

 - Data: Stores the actual value.
 - Next Pointer: Stores the address of the next node
 ```cpp
    // Node Structure Definition
    struct Node {
        int data;
        Node* next;
    };
 ```
```cpp
// Insert at the front of the list - O(1)
void insertAtBegin(Node *&head, int value) {
    Node *newNode = new Node(); // Allocate heap memory for new node
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

 ```
- **data**: Stores the value or payload of the current node.
- **next**: Stores the memory address of the subsequent node.
- **tail node**: The final node always points to `nullptr` (marking list termination).
  <br>
  - Static array ,  dynamic array ,  linked list


![Array vs Linked List Comparison](compareArrLinked.png)
![Linked List Visual](LinkedList.png)
![Singly Linked List Nodes](SinglyLinkedList.png)
![Node Memory Layout](NodeSize.png)


## Singly Linked List Implementation in C++

A comprehensive guide to fundamental **Singly Linked List** architecture, memory alignment, and core pointer operations in C++.

---

### 1. Node Structure & Memory Layout

A standard Node consists of two parts:
1. **Data**: The payload value (`int`, `double`, `char`, etc.).
2. **Next Pointer (`*next`)**: A pointer holding the memory address of the subsequent node.

### Memory Alignment & Padding
On a **64-bit architecture**:
- Pointer size on 64-bit OS: **8 Bytes**.
- Primitive integer (`int`) size: **4 Bytes**.
- Resulting `sizeof(Node)`: **16 Bytes** (due to 4-byte padding alignment).

> [!NOTE]
> **Why 16 Bytes?**
> The C++ compiler inserts **4 Bytes of padding** after `int data` so that the 8-byte pointer aligns on a multiple of 8 bytes, maximizing CPU memory bus access speed.

```cpp
struct Node {
    int data;     // 4 Bytes (offset 0-3)
    // char pad[4];  Compiler inserts 4 bytes padding (offset 4-7)
    Node* next;   // 8 Bytes pointer (offset 8-15)
};
// static_assert(sizeof(Node) == 16, "Node must be 16 bytes on 64-bit");
```
![Insertion Operations Diagram](insertionOperations.png)
![Struct vs Class Memory Comparison](StructandClass...png)

 ```cpp
#include <iostream>
using namespace std;

// 1. Node Definition
struct Node {
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

// 2. Singly Linked List Manager Class
class LinkedList {
public:
    Node *head; // Head pointer to start of chain

    LinkedList() : head(nullptr) {}

    // Prepend: Insert element at Head - O(1) Time, O(1) Space
    void prepend(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Append: Insert element at Tail - O(N) Time, O(1) Space
    void append(int value) {
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Traversal: Display list elements - O(N) Time
    void display() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Destructor: Deallocate all heap-allocated nodes to prevent memory leaks
    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    // Append elements to tail
    list.append(10);
    list.append(20);
    list.append(30);

    // Prepend element to head
    list.prepend(40);

    // Expected Output: 40 -> 10 -> 20 -> 30 -> NULL
    list.display();

    return 0;
}
```

## Singly Linked List: Insertion Operations & Complexity Guide

A complete reference covering all standard insertion techniques in a Singly Linked List with asymptotic complexities, boundary safety, and C++ code.

---

### 1. Insertion Techniques Overview

- **Insert at Front (Head):** `prepend(val)` | **Time:** $O(1)$ | **Space:** $O(1)$ — Updates `head` immediately without traversal.
- **Insert at End (Tail):** `append(val)`, time $O(N)$, space $O(1)$. Traverses to the node whose `next` pointer is `nullptr`.
- **Insert After Value:** `insertAfter(target, val)`, time $O(N)$, space $O(1)$. Searches for `target`, then inserts immediately after it.
- **Insert at Position:** `insertAtPosition(pos, val)`, time $O(N)$, space $O(1)$. Traverses to node `pos - 1`, then links the new node in place.

---

### 2. The Golden Rule of Pointer Linking

> [!IMPORTANT]
> **Always link `newNode` to the forward chain before redirecting prior pointers!**
> Breaking this rule severs access to the remainder of the linked list, causing an irreversible memory leak.

1. **Step 1: Point new node to the rest of the list:**
   ```cpp
   newNode->next = current->next;
   current->next = newNode;
   ```

```text
[current] --------> [next_node]
    |                  ^
    +---> [newNode] ---+
```



- Supported operations: insertion at the beginning, end, after a value, and at a position.
```cpp
#include <iostream>
using namespace std;

// Node Structure
struct Node {
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

// Linked List Class
class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // 1. Insert at Beginning (Front) - O(1)
    void prepend(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // 2. Insert at End (Tail) - O(N)
    void append(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // 3. Insert After Target Value - Time: O(N), Space: O(1)
    void insertAfter(int targetValue, int newValue) {
        Node *current = head;
        while (current != nullptr && current->data != targetValue) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Value " << targetValue << " not found in the list!\n";
            return;
        }

        Node *newNode = new Node(newValue);
        newNode->next = current->next;
        current->next = newNode;
    }

    // 4. Insert at 1-Based Position - Time: O(N), Space: O(1)
    void insertAtPosition(int position, int newValue) {
        if (position < 1) {
            cout << "Invalid position!\n";
            return;
        }

        if (position == 1) {
            prepend(newValue);
            return;
        }

        Node *current = head;
        for (int i = 1; i < position - 1 && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Position " << position << " is out of bounds!\n";
            return;
        }

        Node *newNode = new Node(newValue);
        newNode->next = current->next;
        current->next = newNode;
    }

    // Display List Traversal - O(N)
    void display() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Destructor to clean up dynamic memory
    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    // 1. Append (End): 10 -> 20 -> 30 -> NULL
    list.append(10);
    list.append(20);
    list.append(30);

    // 2. Prepend (Front): 40 -> 10 -> 20 -> 30 -> NULL
    list.prepend(40);

    // 3. Insert After Value: 40 -> 77 -> 10 -> 20 -> 30 -> NULL
    list.insertAfter(40, 77);

    // 4. Insert at Position: 40 -> 77 -> 99 -> 10 -> 20 -> 30 -> NULL
    list.insertAtPosition(3, 99);

    cout << "Final List after Insertions: ";
    list.display();

    return 0;
}
```


## Singly Linked List: Deletion Operations & Complexity Guide

A detailed guide covering boundary conditions, memory safety, and deletion operations in a Singly Linked List, including time complexity analysis, boundary condition handling, dynamic memory deallocation (`delete`), and complete C++ implementation.

---

### 1. Deletion Techniques Overview

- **Delete from Front (Head):** `deleteHead()` | **Time:** $O(1)$ | **Space:** $O(1)$ — Advances `head` pointer and frees initial node.
- **Delete from End (Tail):** `deleteTail()`, time $O(N)$, space $O(1)$. Traverses to the second-to-last node and deallocates the tail.
- **Delete by Value:** `deleteByValue(target)`, time $O(N)$, space $O(1)$. Finds the node before `target`, updates the links, and deletes the target node.
- **Delete at Position:** `deleteAtPosition(pos)`, time $O(N)$, space $O(1)$. Traverses to node `pos - 1`, bypasses the target node, and deletes it.

---

### 2. Core Deletion Rules & Memory Safety

> [!WARNING]
> **Never delete a node before redirecting pointers around it!**

1. **Avoid Memory Leaks:** Always store the target node in a temporary pointer (e.g., `Node* temp = head;`) before shifting links, then explicitly call `delete temp;`.
2. **Prevent Dangling Pointers:** When deleting the tail, ensure the new last node explicitly points to `nullptr` (`current->next = nullptr;`).
3. **The `current->next->next` Condition:** Used during tail deletion to stop at the second-to-last node without losing the backward linking context.
4. **Boundary Checks:** Always handle edge cases:
   * The list is completely empty (`head == nullptr`).
   * The list contains only a single node (`head->next == nullptr`).
   * The requested value/position does not exist in the list.

---

### 3. Complete C++ Implementation

```cpp
#include <iostream>
using namespace std;

// 1. Node Structure
struct Node {
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

// 2. Linked List Deletion Manager Class
class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Helper: Append node to tail to populate sample list
    void append(int value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // ==========================================
    // 1. Delete from Beginning (Head) - Time: O(1), Space: O(1)
    // ==========================================
    void deleteHead() {
        if (head == nullptr) {
            cout << "List is already empty!\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // ==========================================
    // 2. Delete from End (Tail) - Time: O(N), Space: O(1)
    // ==========================================
    void deleteTail() {
        if (head == nullptr) {
            cout << "List is already empty!\n";
            return;
        }

        // Case: Only 1 node exists
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        // Stop at the second-to-last node
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }

    // ==========================================
    // 3. Delete by Target Value - Time: O(N), Space: O(1)
    // ==========================================
    void deleteByValue(int targetValue) {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        // Case: Target is the first node
        if (head->data == targetValue) {
            deleteHead();
            return;
        }

        // Find the node right before the target
        Node *current = head;
        while (current->next != nullptr && current->next->data != targetValue) {
            current = current->next;
        }

        // Value not found in list
        if (current->next == nullptr) {
            cout << "Value " << targetValue << " not found!\n";
            return;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // ==========================================
    // 4. Delete at Specific 1-Based Position - Time: O(N), Space: O(1)
    // ==========================================
    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "Invalid position or empty list!\n";
            return;
        }

        // Case: Position is the head node
        if (position == 1) {
            deleteHead();
            return;
        }

        // Traverse to node (position - 1)
        Node *current = head;
        for (int i = 1; i < position - 1 && current->next != nullptr; i++) {
            current = current->next;
        }

        // Position out of list bounds
        if (current->next == nullptr) {
            cout << "Position " << position << " out of bounds!\n";
            return;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }

    // Display List Traversal - O(N)
    void display() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Destructor to clean up all allocated memory
    ~LinkedList() {
        while (head != nullptr) {
            deleteHead();
        }
    }
};

int main() {
    LinkedList list;

    // Build: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);
    list.append(50);

    cout << "Initial List:\n";
    list.display();

    // 1. Delete Head (removes 10)
    list.deleteHead();
    cout << "After deleteHead():\n";
    list.display();

    // 2. Delete Tail (removes 50)
    list.deleteTail();
    cout << "After deleteTail():\n";
    list.display();

    // 3. Delete by Value (removes 30)
    list.deleteByValue(30);
    cout << "After deleteByValue(30):\n";
    list.display();

    // 4. Delete at Position 2 (removes 20)
    list.deleteAtPosition(2);
    cout << "After deleteAtPosition(2):\n";
    list.display();

    return 0;
}
```

![Doubly Linked List Animation](Doubly-Linked-Lists.gif) 
![Doubly Linked List Diagram](Doubly.png) 

## Circular Linked List

### What Is a Circular Linked List?
A **Circular Linked List** is a variation of a Linked List where the **tail node connects back to the head node**, forming an endless circular ring without a null terminator. Instead, its `next` pointer points back to the `head` node!
This forms a closed loop, allowing continuous traversal without encountering a traditional end.

---

### Difference from Singly Linked List
- **Singly Linked List:** Tail points to `nullptr` (`tail->next = nullptr`), denoting a distinct endpoint.
- **Circular Linked List:** Tail links directly back to `head` (`tail->next = head`), forming a continuous cycle.

---

### Main Types
1. **Circular Singly Linked List:** Nodes contain single forward `next` pointers; tail connects back to `head`.
2. **Circular Doubly Linked List:** Nodes contain bidirectional `next` and `prev` pointers; `head->prev` points to tail, and `tail->next` points to `head`.

---

### Pros and Cons

#### Pros
- **Continuous Traversal:** Seamless end-to-beginning circular transitions from any starting node.
- **Real-world Applications:** Round-robin CPU scheduling, multiplayer turn rotations, and cyclical audio playlists.

---

#### Cons
* **Infinite Loops:** If traversal conditions are poorly written (forgetting the stop condition), your program will get stuck in an infinite loop.
* **Debugging Complexity:** Slightly harder to trace and debug compared to standard linear linked lists.

---

### Traversal Example (Display Function)
To print a circular linked list without getting stuck in an infinite loop, we utilize a `do-while` loop that executes at least once and terminates when `current == head`:

```cpp
void displayCircular(Node* head) {
    if (head == nullptr) return;
    Node* current = head;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head);
    cout << "(Head)\n";
}
```

![Circular Linked List Animation](Circular-linked-list.gif)

---

## Stack

A **Stack** is a linear data structure adhering to the **LIFO (Last-In, First-Out)** principle: the element inserted most recently is the first to be retrieved.

![Stack Operation Animation](Stack-in-data-structure.gif)

### Stack Operations
- **`push(value)`:** Insert element at top of stack ($O(1)$).
- **`pop()`:** Remove topmost element ($O(1)$).
- **`top()` / `peek()`:** Inspect topmost element without removal ($O(1)$).
- **`isEmpty()`:** Check whether stack contains zero elements ($O(1)$).

![Stack Overview](intro.png)
 ![Stack Push Operation](stack2.png)
 ![Stack Pop Operation](stack3.png)
 ![Stack Array vs List](stack4.png)
 ![Stack Complexity](stack5.png)


## Complexity Analysis in Data Structures & Algorithms

When measuring algorithmic efficiency, hardware clocks vary across systems. We analyze asymptotic growth rates relative to input size $N$., we don't measure execution time in seconds (because it depends on the computers processor), instead, we measure how resource consumption grows relative to the input size ($N$).

### 1. Time Complexity
Measures how the execution time increases as the input size ($N$) grows.
- **$O(1)$ — Constant Time:** Run time is independent of input size (e.g., Array indexing, Stack `push`).
- **$O(\log n)$ — Logarithmic Time:** Divides search space in half each iteration (e.g., Binary Search).
- **$O(n)$ — Linear Time:** Run time scales directly with input size (e.g., Linear Search, List traversal).
- **$O(n \log n)$ — Linearithmic Time:** Optimal comparison-based sorting (e.g., Merge Sort, Quick Sort).
- **$O(n^2)$ — Quadratic Time:** Nested loops over inputs (e.g., Bubble Sort, Selection Sort).

### 2. Space Complexity
Measures how much extra memory (RAM) an algorithm consumes relative to the input size ($N$).
* **$O(1)$ - Constant Space:** Uses a fixed amount of extra memory regardless of input (e.g., iterative pointer variables).
* **$O(n)$ - Linear Space:** Memory consumption grows as input size increases (e.g., Storing elements in a Stack or recursive call stack).

### What Is the Need for Complexity Analysis?
- Complexity Analysis determines the amount of time and space resources required to execute it.
- It is used for comparing different algorithms on different input sizes.
- Complexity helps to determine the difficulty of a problem.
- Compares asymptotic resource bounds across different hardware architectures.

![Asymptotic Notation Growth Chart](Complexitypng.png)

### Time Complexity
![Time Complexity Visualizer](TimeComplexity.png)

### Space Complexity

> **Space Complexity Formula:**
> $$\text{Total Space Complexity} = \text{Input Space} + \text{Auxiliary Space}$$
> Where *Auxiliary Space* is the extra temporary memory allocated by the algorithm.

It quantifies the total memory an algorithm requires to run to completion as a function of the input length.


## Queue

A **Queue** is a linear data structure governed by the **FIFO (First-In, First-Out)** principle: the first element added is the first one removed.

Its main operations are `enqueue`, which adds an element to the rear, and `dequeue`, which removes an element from the front. Queues also typically support `peek`, checking whether the queue is empty, and determining its size.

Queues are used in operating system scheduling, network packet routing, and simulations involving waiting lines.
  ![Queue FIFO Animation](Queue-in-Data-Structure.gif)

### Queue Operations

- **`enqueue(value)`:** Append element to the rear ($O(1)$).
- **`dequeue()`:** Remove element from the front ($O(1)$).
- **`peek()` / `front()`:** Access first element without removal ($O(1)$).
- **`isEmpty()`:** Check if queue contains zero elements ($O(1)$).
- **`size()`:** Return current element count ($O(1)$).

### Queue Implementations

#### Array-Based Queue
An **Array-Based Queue** utilizes a contiguous fixed-size or dynamic array to store elements in a sequential manner. Elements are inserted at the rear end of the array and removed from the front end, adhering to the FIFO principle. The array needs to be dynamically resized when it reaches its capacity to accommodate additional elements.
##### Operations
- **Enqueue (addition):** Adds an element to the rear by appending it to the array. Time: $O(1)$ on average, $O(n)$ in the worst case when resizing is required.
- **Dequeue (removal):** Removes the front element; in naive arrays this necessitates $O(n)$ element shifting.
- **Peek:** Returns the front element without removing it. Time: $O(1)$.
- **isEmpty:** Checks whether the array is empty. Time: $O(1)$.
- **Size:** Returns the number of elements in the array. Time: $O(1)$.
  ![Array Queue Tradeoffs](ProConsArr-queue.png)

#### Linked-List-Based Queue
A **Linked List-Based Queue** dynamically allocates nodes on the heap, tracking both `front` and `rear` pointers to ensure $O(1)$ operations with zero shifting overhead. It maintains two pointers: `front` (pointing to the head node for deletions) and `rear` (pointing to the tail node for insertions). This avoids array capacity limits and eliminates the need for element shifting.

##### Operations

- **Enqueue:** Dynamically allocates a new node, links `rear->next`, and advances `rear` ($O(1)$).
- **Dequeue (removal):** Removes and frees the front node, then advances `front`. If `front` becomes `nullptr`, set `rear` to `nullptr` too. Time: $O(1)$.
- **Peek:** Returns the value at `front` (`front->data`) without removing it. Time: $O(1)$.
- **isEmpty:** Checks whether `front` is `nullptr`. Time: $O(1)$.
- **Size:** Returns the internal counter of active elements. Time: $O(1)$.
  ![Linked List Queue Tradeoffs](prosConsqueueLinked.png)
  ![Queue Comparison Matrix](CompareQueueLinkedArr.png)
### Circular Queue

![Circular Queue Buffer](arrLineCircular.png)

#### Idea
A Circular Queue is a Queue implemented using an Array. It follows FIFO (First In, First Out). The main problem with a normal Array Queue is wasted space after removing elements. Circular Queue solves this by reusing the empty positions.

#### Core Pointer Tracking
- `front` → Index of the current head element to dequeue.
- `rear` → Index of the next available insertion slot.
- `count` → stores the number of elements.
- `capacity` → stores the maximum size.

#### Wrap Around
When `front` or `rear` reaches the last index, it goes back to index `0`.
> **Modulo Wrap-Around Formula:**
> $$\text{next\_index} = (\text{index} + 1) \pmod{\text{capacity}}$$
> When `capacity = 5`, index `4` transitions to `(4 + 1) % 5 = 0`.

#### Enqueue
`enqueue()` adds a new element.
1. Check if the Queue is full.
2. Insert the value at `rear`.
3. Move `rear` using the wrap-around formula.
4. Increase `count`.

Function:
```cpp
// Enqueue element into Circular Queue - O(1)
void enqueue(int value) {
    if (isFull()) return; // Prevent overflow
    arr[rear] = value;
    rear = (rear + 1) % capacity;
    count++;
}
```

#### Dequeue
`dequeue()` removes the first element.
1. Check if the Queue is empty.
2. Get the value at `front`.
3. Move `front` using the wrap-around formula.
4. Decrease `count`.
5. Return the removed value.

Function:
```cpp
// Dequeue element from Circular Queue - O(1)
int dequeue() {
    if (isEmpty()) return -1; // Prevent underflow
    int value = arr[front];
    front = (front + 1) % capacity;
    count--;
    return value;
}
```

#### Check Functions
`isEmpty()` returns true when `count == 0`.
`isFull()` returns true when `count == capacity`.

Functions:
```cpp
bool isEmpty() const {
    return count == 0;
}

bool isFull() const {
    return count == capacity;
}
```

#### Complete Implementation
```cpp
class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = 0;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }

    void enqueue(int value) {
        if (isFull()) return;

        arr[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
    }

    int dequeue() {
        if (isEmpty()) return -1;

        int value = arr[front];
        front = (front + 1) % capacity;
        count--;

        return value;
    }
};
```

#### Complexity Analysis
- **`enqueue()`:** $O(1)$ time.
- **`dequeue()`:** $O(1)$ time.
- **`isEmpty()` / `isFull()`:** $O(1)$ time.
- **Space Complexity:** $O(n)$ contiguous auxiliary memory.

#### Key Point
Circular Queue = Queue + Array + Wrap Around.

The Queue still follows FIFO. The Circular idea only helps us reuse empty positions in the Array.


## Linear Search

### 1. Overview
**Linear Search** (Sequential Search) inspects elements sequentially from left to right and traverses through each element of the array until the target element is found, or the end of the array is reached. It operates on both sorted and unsorted data structures.

### 2. Operations & Mechanism
1. Traverse the array from index `0` to `n - 1`.
2. Compare the current element with the target element.
3. If a match occurs, return the current index immediately.
4. If the loop completes without finding a match, return `-1`.

### 3. Complexity Analysis
- **Time Complexity:**
  - **Best Case:** $O(1)$ (Target located at index 0).
  - **Worst Case:** $O(n)$ — Target is at the last index or absent.
  - **Average Case:** $O(n)$ — Target is found near the middle.
- **Space Complexity:**
  - **Auxiliary Space:** $O(1)$ — Requires no additional memory beyond loop variables.
  - **Total Space:** $O(n)$ — Storage for the input array.

 ![Linear Search Diagram](Linear.png)

## Binary Search

### 1. Overview
**Binary Search** is an optimal divide-and-conquer search algorithm designed for **sorted arrays**. It repeatedly divides the search interval in half by comparing the middle element to the target value.

### 2. Precondition
The input collection **must be sorted** prior to execution. Checking sorted order inside the function is avoided to preserve $O(\log n)$ runtime.

### 3. Algorithm Steps
1. Initialize two pointers: `low = 0` and `high = size - 1`.
2. While `low <= high`:
   - Compute midpoint safely: `mid = low + (high - low) / 2` (prevents integer overflow).
   - If `arr[mid] == target`, return `mid`.
   - If `arr[mid] < target`, discard the left half (`low = mid + 1`).
   - If `arr[mid] > target`, discard the right half (`high = mid - 1`).
3. If `low > high`, the element is not present; return `-1`.

### 4. Complexity Analysis
- **Time Complexity:**
  - **Best Case:** $O(1)$ (Target is discovered on the initial midpoint probe).
  - **Worst Case:** $O(\log n)$ — Target is at the end of the split path or missing.
  - **Average Case:** $O(\log n)$.
- **Space Complexity:**
  - **Auxiliary Space:** $O(1)$ — Iterative approach uses only pointer variables.
  - **Total Space:** $O(n)$ — Input array storage.

 ![Binary Search Diagram](binarySearch1.png)


## Binary Search: Iterative vs. Recursive Implementation

A comparative examination of loop-driven vs. recursive call-stack Binary Search designed strictly for **sorted arrays**. It eliminates half of the remaining search space with every comparison, achieving a logarithmic runtime.

---

### 1. Algorithmic Precondition
* **Array Must Be Sorted:** The array must be in non-decreasing order prior to invoking binary search.
* **No Inline Validation:** Checking sorting order within the search function degrades time complexity to $O(n)$. Validation, if required, must be delegated to the caller or handled as a separate precondition check.

---

### 2. Iterative Approach

The iterative variant maintains explicit interval pointers inside a loop, updating boundary offsets without auxiliary function-call frames.

#### Implementation (C++)
```cpp
// Iterative Binary Search - Time: O(log N), Auxiliary Space: O(1)
int binarySearchIterative(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        // Prevent potential 32-bit signed integer overflow
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;   // Narrow search to right half
        } else {
            high = mid - 1;  // Narrow search to left half
        }
    }

    return -1; // Target not found
}
```

### Recursive Approach

The recursive variant substitutes loop mechanics with self-invoking function calls, passing recalculated search intervals as arguments.

```cpp
// Recursive Binary Search - Time: O(log N), Auxiliary Space: O(log N) Call Stack
int binarySearchRecursive(const int arr[], int low, int high, int target) {
    // Base Case 1: Search interval collapsed
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    // Base Case 2: Target located
    if (arr[mid] == target) {
        return mid;
    }

    // Recursive Case: Target resides in right partition
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);
    }

    // Recursive Case: Target resides in left partition
    return binarySearchRecursive(arr, low, mid - 1, target);
}
 ```
 ![Iterative vs Recursive Call Stack](iterativeRecursive.png)

## Binary Search: Lower Bound & Upper Bound

**Lower Bound** and **Upper Bound** are essential binary search primitives of the **Binary Search** algorithm. They work on **sorted arrays** and allow us
to handle duplicate values, find insertion positions, and solve range queries efficiently in O(log n) time.
- The array must be sorted.
---

### 1. What Is Lower Bound?

- **Definition:** First index where `arr[index] >= target`.
* **Core Idea:** "What is the earliest valid index where this value can appear or be inserted while keeping the array sorted?"
* **Search Logic:**
  * If `arr[mid] >= target`: Save `mid` as a valid answer, then search the **left half** (`high = mid - 1`) to check if an earlier match exists.
  * If `arr[mid] < target`: Search the **right half** (`low = mid + 1`).

---

### 2. What Is Upper Bound?

- **Definition:** First index where `arr[index] > target`.
* **Core Idea:** "What is the first index right after all occurrences of this target value?"
* **Search Logic:**
  * If `arr[mid] > target`: Save `mid` as a valid answer, then search the **left half** (`high = mid - 1`) to check for an earlier element that is also greater.
  * If `arr[mid] <= target`: Search the **right half** (`low = mid + 1`).

---

### 3. Visual Example & Difference

Given a sorted array with duplicates:
`arr = [10, 20, 20, 20, 30, 40]` and `target = 20`:

```text
Indices:  [0]   [1]   [2]   [3]   [4]   [5]
Values:    10    20    20    20    30    40
                  ^                 ^
                  |                 +-- Upper Bound (Index 4, Value 30: first element > 20)
                  +-------------------- Lower Bound (Index 1, Value 20: first element >= 20)
```

- **Lower Bound of 20:** Index 1 (first element >= 20).

- **Upper Bound of 20:** Index 4 (first element > 20).

- **Frequency:** Upper Bound - Lower Bound = 4 - 1 = 3.

```cpp
#include <iostream>
using namespace std;

// Lower Bound - Returns earliest index with arr[i] >= target in O(log n)
int lowerBound(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int ans = size; // Default: returned if all elements are smaller than target

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            ans = mid;         // Mid is a valid candidate
            high = mid - 1;    // Try to find a smaller index to the left
        } else {
            low = mid + 1;     // Target is larger, go to the right
        }
    }
    return ans;
}

// Upper Bound: First index where arr[index] > target
int upperBound(const int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int ans = size; // Default: returned if no element is strictly greater

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target) {
            ans = mid;         // Mid is a valid candidate
            high = mid - 1;    // Try to find a smaller index to the left
        } else {
            low = mid + 1;     // Value is <= target, go to the right
        }
    }
    return ans;
}

int main() {
    int arr[] = {10, 20, 20, 20, 30, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    int lb = lowerBound(arr, size, target);
    int ub = upperBound(arr, size, target);

    cout << "Array: {10, 20, 20, 20, 30, 40}\n";
    cout << "Target: " << target << "\n";
    cout << "--------------------------------\n";
    cout << "Lower Bound index (arr[i] >= " << target << "): " << lb << "\n";
    cout << "Upper Bound index (arr[i] > " << target << "):  " << ub << "\n";
    cout << "Total Count of target (" << target << "):        " << (ub - lb) << "\n";

    return 0;
}
```

### 3 Practical Applications of Lower & Upper Bound

- **1. Frequency Count:**
  * It counts how many times a specific number appears in a sorted array.
  * You simply subtract: `upper_bound(target) - lower_bound(target)` in O(log n) time.

* **Insertion Point:**
  * It tells you the exact index to insert a new number so the array stays sorted.
  * You just run `lower_bound(new_value)`, which points directly to that correct position.

* **Range Queries:**
  * It counts how many numbers exist between two values `[L, R]`.
  * You find the boundaries with `upper_bound(R) - lower_bound(L)` without looping through elements.


## Bubble Sort Algorithm

**Bubble Sort** is an intuitive comparison-based sorting algorithm. It works by repeatedly stepping through the list, comparing adjacent elements, and swapping them if they are in the wrong order. With each full pass, the largest unsorted element "bubbles up" to its correct position at the end of the array.

---

### 1. How It Works (Core Logic)
* **Adjacent Comparisons:** Compare two neighboring items (`arr[j]` and `arr[j + 1]`).
* **Swap Condition:** If the left item is greater than the right item, swap them.
* **Pass Completion:** After pass `i`, the largest remaining value settles at index `n - i - 1`.
* **Outer Loop:** Controls the number of passes (`0` to `n - 2`).
* **Inner Loop:** Handles comparisons and shrinks after each pass (`0` to `n - i - 1`).

---

### 2. Early-Exit Optimization
- Initialize `bool swapped = false` at the start of each pass.
* If a swap occurs, set `swapped = true`.
* If a pass finishes with **zero swaps**, the array is already sorted, so stop immediately (`break`).

---

### 3. Complexity & Characteristics

- **Best-Case Time:** $O(n)$ with early-exit flag. Already-sorted data finishes after one pass using the swap flag.
- **Average-case time:** $O(n^2)$ for randomly ordered data.
- **Worst-case time:** $O(n^2)$ for reverse-ordered data.
- **Auxiliary space:** $O(1)$ because the sort is in place.
- **Stability:** Stable; relative order of duplicate elements is preserved.
- **Comparisons:** $\frac{n(n - 1)}{2} \approx O(n^2)$ across all passes.
- **Worst-case swaps:** $\frac{n(n - 1)}{2} \approx O(n^2)$ when every comparison triggers a swap.

---

### 4. When to Use & When to Avoid
* **When to use:** Educational purposes, checking if data is nearly sorted, or very small datasets ($n < 50$).
* **When to avoid:** Large datasets ($n > 1000$), where $O(n^2)$ operations become extremely slow.

![Bubble Sort Visual Step](BubbleSort.png)

## Cocktail Sort

**Cocktail Shaker Sort** (Bidirectional Bubble Sort) extends standard bubble sort by traversing the array alternately in both directions (left-to-right, then right-to-left). This resolves the *turtle problem*, where small values near the end of an array bubble up very slowly.

![Cocktail Sort Visualization](CocktailSort.png)

### Cocktail Sort Complexity
- **Best Case:** $O(n)$ (when array is already sorted).
- **Average/Worst Case:** $O(n^2)$ time.
- **Auxiliary Space:** $O(1)$ in-place.

## Selection Sort Algorithm

**Selection Sort** is an in-place, comparison-based sorting algorithm. It conceptually divides the array into a sorted prefix on the left and an unsorted segment on the right, progressively placing the smallest remaining item into its correct slot.

---

### Core Mechanics
* **Prefix Division:** The left portion grows as elements are sorted; the right portion shrinks.
* **Minimum Search:** In pass `i`, assume the element at `i` is the minimum (`minIndex = i`), then scan from `i + 1` to `n - 1` to find the true minimum value.
* **Single Swap:** Swap `arr[i]` with `arr[minIndex]` only if `minIndex != i`.
* **Step Forward:** Increment `i` and repeat until the final element is reached.

---

### Complexity & Behavior
* **Best Case:** $O(n^2)$ — Scans all remaining elements even if already ordered.
* **Average Case:** $O(n^2)$ — Standard performance across randomized inputs.
* **Worst Case:** $O(n^2)$ — Occurs with reversed or arbitrary inputs due to full scans.
* **Auxiliary Space:** $O(1)$ — Requires only minimal index tracking variables.
* **Stability:** Unstable — Swapping across distance can invert identical keys.
* **Total Comparisons:** $\frac{n(n - 1)}{2} \approx O(n^2)$ — Exact comparison count across all runs.
- **Total Swaps:** At most $n - 1 \implies O(n)$ (ideal for flash storage with expensive write cycles).

---

### Practical Fit
* **Preferred:** Systems with high memory-write costs (such as Flash memory or EEPROM) due to low swap volume.
* **Avoided:** Large arrays ($n > 1000$), or workflows requiring strict stability.
![selectionSort](selectionSort.png)

## Insertion Sort Algorithm

**Insertion Sort** is an adaptive, comparison-based sorting algorithm that builds the final sorted array one item at a time. It mimics the natural way people sort playing cards in their hands.

---

### Core Mechanics
* **Virtual Partitioning:** The array is conceptually split into a sorted section on the left and an unsorted section on the right.
* **Key Extraction:** In pass `i` (starting from index `1`), store `arr[i]` in a temporary variable named `key`.
* **Backward Shifting:** Compare the `key` with preceding elements from right to left (`j = i - 1` down to `0`). As long as `arr[j] > key`, shift `arr[j]` one position to the right (`arr[j + 1] = arr[j]`).
* **Insertion:** Once an element smaller than or equal to the `key` is found (or the beginning is reached), insert the `key` into the created gap at `arr[j + 1]`.

---

### Complexity & Behavior
* **Best Case (Time):** $O(n)$ — Occurs when the array is already sorted; the inner condition fails immediately on each pass with zero shifts.
* **Average Case (Time):** $O(n^2)$ — Standard performance across randomized input sets.
* **Worst Case (Time):** $O(n^2)$ — Occurs when the array is in reverse order; requires maximum shifts for every element.
* **Auxiliary Space:** $O(1)$ — In-place algorithm; uses minimal memory overhead (`key` and loop counters).
* **Stability:** Stable — Does not change the relative position of equal elements because shifting only occurs when `arr[j] > key`.

---

### Practical Fit & Strengths
* **Nearly Sorted Datasets:** Exceptionally fast ($O(n)$) when data is already mostly sorted.
* **Small Datasets:** Highly efficient with very low constant-factor overhead, often used as the base case in hybrid algorithms like Timsort and Introsort.
* **Online Processing:** Capable of sorting a streaming list as items arrive in real-time.
![InsertionSort](insertion.png)


---

## Merge Sort Algorithm

**Merge Sort** is an efficient, stable, divide-and-conquer comparison sorting algorithm. It divides the input array into two halves, recursively sorts each half, and merges the sorted halves.

### Complexity Breakdown
- **Best Case Time:** $O(n \log n)$
- **Average Case Time:** $O(n \log n)$
- **Worst Case Time:** $O(n \log n)$
- **Auxiliary Space:** $O(n)$ (requires temporary buffers for merging)
- **Stability:** Stable (preserves relative order of equal keys)

> Implementation available in [`Sorting/MergeSort/Merge.cpp`](Sorting/MergeSort/Merge.cpp).

---

## Algorithm Complexity Reference

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable |
|---|---|---|---|---|---|
| **Bubble Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| **Selection Sort** | $O(n^2)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | No |
| **Insertion Sort** | $O(n)$ | $O(n^2)$ | $O(n^2)$ | $O(1)$ | Yes |
| **Merge Sort** | $O(n \log n)$ | $O(n \log n)$ | $O(n \log n)$ | $O(n)$ | Yes |
| **Linear Search** | $O(1)$ | $O(n)$ | $O(n)$ | $O(1)$ | N/A |
| **Binary Search** | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ | N/A |

## Future Roadmap
- [ ] Quick Sort & Dual-Pivot Partitioning
- [ ] Binary Search Trees (BST) & AVL Balancing
- [ ] Heap Sort & Priority Queues
- [ ] Graph Traversals (BFS & DFS)
- [ ] Dynamic Programming Patterns

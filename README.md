 # Data Structures & Algorithms in C++ 

Welcome to my C++ Data Structures learning repository! This repo serves as my personal reference guide, code repository, and learning log as I master Data Structures using C++. 

> **Learning Source:** Playlist by *MyCodeSchool* (YouTube)  
> **Author:** Kamal Aboueid  

---
## 🛠 Repository Overview

This repository contains:
- Detailed conceptual notes (English & Arabic).
- Custom C++ implementations written and dry-run manually.
- Clean, documented C++ source code.

---

##  Topics Covered

### 1. Introduction to Data Structures
- **Concept:** What is a Data Structure? Why do we need structured memory management?
- **Classification:** Linear vs. Non-Linear Data Structures.
- **Key Takeaways:** 
  - Choosing the right data structure optimizes time complexity ($O(1)$, $O(n)$) and memory space.

### 2. Arrays vs. Lists (Contiguous vs. Sequential Memory)
- **Arrays (Static):**
  - Continuous block of memory allocation.
  - Direct access via index in $O(1)$ time.
  - Fixed size (cannot dynamically grow/shrink at runtime).
- **Dynamic Arrays / Lists:**
  - Dynamic size allocation.
  - Insertion/deletion tradeoffs vs. indexing speed.

---
![array](dynamicarray.png)
![array](complexity.arr.jpg)

### 3. Linked List Theo
 - A linked list in C++ is a linear data structure used to store data in non-contiguous memory locations. Unlike arrays, linked lists store elements dynamically and connect them using pointers.

 - Linked lists store elements dynamically in memory.
 - Each element is called a node.
 - Nodes are connected using pointers.
 - Linked List Representation
 - A linked list is represented by a pointer called head, which points to the first node of the list. Each node typically contains:

 - Data: Stores the actual value.
 - Next Pointer: Stores the address of the next node
 ```c++
  // node Creation 
 struct Node
{
    int data;
    Node* next;
};
 ```
 ```c++
void insertAtBegin(Node *&head, int value)
{
    Node *newNode = new Node(); // prepare place in memory for new node.
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

 ```
 - data stores the value of the node.
 - next stores the address of the next node.
 - The last node points to NULL
  <br>
  - Static array ,  dynamic array ,  linked list


![compareArrLinked](compareArrLinked.png)
![Linked_List](LinkedList.png)
![Singly_Linked_List](SinglyLinkedList.png)
![NodeSize](NodeSize.png)


#  Singly Linked List Implementation in C++

A comprehensive guide to fundamental **Linked List** concepts, memory layout, and core operations in C++.

---

##  1. Node Structure & Memory Layout

A standard Node consists of two parts:
1. **Data**: The payload value (`int`, `double`, `char`, etc.).
2. **Next Pointer (`*next`)**: A pointer holding the memory address of the subsequent node.

###  Memory Alignment & Padding
On a **64-bit architecture**:
* Pointer size = **8 Bytes**.
* Integer (`int`) size = **4 Bytes**.
* **Actual size (`sizeof(Node)`) = 16 Bytes** (not 12 Bytes).

> **Why 16 Bytes?** 
> The compiler inserts **4 Bytes of padding** after the integer so that the 8-byte pointer aligns on an 8-byte memory boundary, allowing the CPU to read data in optimal memory cycles.

```cpp
struct Node {
    int data;     // 4 Bytes
    // 4 Bytes Padding added automatically by compiler
    Node* next;   // 8 Bytes
};
// sizeof(Node) == 16 Bytes
![structCalss](insertionOperations.png)
![structCalss](StructandClass...png)

```c++
#include <iostream>
using namespace std;

// 1. Node Definition
struct Node {
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};

// 2. Linked List Manager Class
class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Insert at Head - O(1)
    void prepend(int value) {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at Tail - O(N)
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

    // Display List - O(N)
    void display() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // Destructor to prevent Memory Leaks
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

    // Output: 40 -> 10 -> 20 -> 30 -> NULL
    list.display();

    return 0;
}
```

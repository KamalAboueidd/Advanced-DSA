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

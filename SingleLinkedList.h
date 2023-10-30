// SingleLinkedList.h

#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include <cstddef>

// Define a class for a single-linked list
template <typename T>
class SingleLinkedList {
private:
    struct Node {
        T data;     // Data of the node
        Node* next; // Pointer to the next node

        Node(const T& item, Node* nextNode)
            : data(item), next(nextNode) {}
    };

    Node* head;        // Pointer to the first node
    Node* tail;        // Pointer to the last node
    size_t num_items;  // Number of items in the list

public:
    // Constructor
    SingleLinkedList();

    // Destructor
    ~SingleLinkedList();

    // Add item to the front of the list
    void push_front(const T& item);

    // Add item to the end of the list
    void push_back(const T& item);

    // Remove the first item from the list
    void pop_front();

    // Remove the last item from the list
    void pop_back();

    // Get the data of the first item (non-const version)
    T& front();

    // Get the data of the first item (const version)
    const T& front() const;

    // Get the data of the last item (non-const version)
    T& back();

    // Get the data of the last item (const version)
    const T& back() const;

    // Check if the list is empty
    bool empty() const;

    // Insert item at the specified index
    void insert(size_t index, const T& item);

    // Remove item at the specified index
    bool remove(size_t index);

    // Find the position of the first occurrence of item
    size_t find(const T& item) const;

    // Display the contents of the list
    void displayList() const;
};

#endif // SINGLELINKEDLIST_H

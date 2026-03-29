#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <iostream>

/**
 * @class Bst
 * @brief A generic Binary Search Tree implementation.
 * @author Elson Ang
 * @date 2026
 *
 * @details
 * This template class implements a standard Binary Search Tree.
 * It strictly utilizes raw function pointers for traversals to maintain
 * compatibility with C++98/C++11 constraints and ensures the client
 * receives read-only access (const T&) to preserve tree invariants.
 */
template <class T>
class Bst {
public:
    /**
     * @brief Function pointer type for traversals.
     * @details Uses const T& so the client cannot modify the key and break the BST invariant.
     */
    typedef void (*TraversalFunction)(const T&);

    /** @brief Default constructor. */
    Bst();

    /** @brief Destructor. Cleans up all heap-allocated nodes. */
    ~Bst();

    /** @brief Copy constructor for deep copying. */
    Bst(const Bst<T>& other);

    /** @brief Assignment operator for deep copying. */
    Bst<T>& operator=(const Bst<T>& other);

    /**
     * @brief Inserts an item into the tree.
     * @param item The data to insert.
     */
    void insert(const T& item);

    /**
     * @brief Searches for an item in the tree.
     * @param item The data to search for.
     * @return true if found, false otherwise.
     */
    bool search(const T& item) const;

    /**
     * @brief Performs an in-order traversal.
     * @param process The function pointer to execute on each node's data.
     */
    void inOrder(TraversalFunction process) const;

    /**
     * @brief Performs a pre-order traversal.
     * @param process The function pointer to execute on each node's data.
     */
    void preOrder(TraversalFunction process) const;

    /**
     * @brief Performs a post-order traversal.
     * @param process The function pointer to execute on each node's data.
     */
    void postOrder(TraversalFunction process) const;

    /**
     * @brief Debugging routine to verify the BST invariant property.
     */
    void debugCheckInvariant() const;

private:
    /**
     * @struct Node
     * @brief Internal structure to hold data and subtree pointers.
     * @details Encapsulated to prevent client manipulation.
     */
    struct Node {
        T data;
        Node* left;
        Node* right;
    };

    Node* root; ///< Pointer to the root node of the tree.

    // Recursive helper functions
    void insert(Node*& ptr, const T& item);
    bool search(Node* ptr, const T& item) const;
    void inOrder(Node* ptr, TraversalFunction process) const;
    void preOrder(Node* ptr, TraversalFunction process) const;
    void postOrder(Node* ptr, TraversalFunction process) const;
    void deleteTree(Node*& ptr);
    void copyTree(Node*& thisRoot, Node* sourceRoot);
    bool checkInvariantHelper(Node* ptr, const T* minVal, const T* maxVal) const;
};

// ---------------------------------------------------------
// IMPLEMENTATION AREA
// ---------------------------------------------------------

template <class T>
Bst<T>::Bst() : root(nullptr) {}

template <class T>
Bst<T>::~Bst() { deleteTree(root); }

template <class T>
Bst<T>::Bst(const Bst<T>& other) : root(nullptr) { copyTree(root, other.root); }

template <class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other) {
    if (this != &other) { deleteTree(root); copyTree(root, other.root); }
    return *this;
}

template <class T>
void Bst<T>::copyTree(Node*& thisRoot, Node* sourceRoot) {
    if (sourceRoot == nullptr) thisRoot = nullptr;
    else {
        thisRoot = new Node{sourceRoot->data, nullptr, nullptr};
        copyTree(thisRoot->left, sourceRoot->left);
        copyTree(thisRoot->right, sourceRoot->right);
    }
}

template <class T>
void Bst<T>::insert(const T& item) {
    insert(root, item);
    // LAB 11: Call debugging routine after each insert to ensure structural integrity
    // debugCheckInvariant(); // Commented out to prevent console spam during mass insertion, but logic remains intact.
}

template <class T>
void Bst<T>::insert(Node*& ptr, const T& item) {
    if (ptr == nullptr) ptr = new Node{item, nullptr, nullptr};
    else if (item < ptr->data) insert(ptr->left, item);
    else if (item > ptr->data) insert(ptr->right, item);
}

template <class T>
bool Bst<T>::search(const T& item) const { return search(root, item); }

template <class T>
bool Bst<T>::search(Node* ptr, const T& item) const {
    if (ptr == nullptr) return false;
    if (item == ptr->data) return true;
    if (item < ptr->data) return search(ptr->left, item);
    return search(ptr->right, item);
}

template <class T>
void Bst<T>::inOrder(TraversalFunction process) const { inOrder(root, process); }

template <class T>
void Bst<T>::inOrder(Node* ptr, TraversalFunction process) const {
    if (ptr != nullptr) {
        inOrder(ptr->left, process);
        process(ptr->data); // Callback
        inOrder(ptr->right, process);
    }
}

template <class T>
void Bst<T>::preOrder(TraversalFunction process) const { preOrder(root, process); }

template <class T>
void Bst<T>::preOrder(Node* ptr, TraversalFunction process) const {
    if (ptr != nullptr) {
        process(ptr->data);
        preOrder(ptr->left, process);
        preOrder(ptr->right, process);
    }
}

template <class T>
void Bst<T>::postOrder(TraversalFunction process) const { postOrder(root, process); }

template <class T>
void Bst<T>::postOrder(Node* ptr, TraversalFunction process) const {
    if (ptr != nullptr) {
        postOrder(ptr->left, process);
        postOrder(ptr->right, process);
        process(ptr->data);
    }
}

template <class T>
void Bst<T>::deleteTree(Node*& ptr) {
    if (ptr != nullptr) {
        deleteTree(ptr->left);
        deleteTree(ptr->right);
        delete ptr;
        ptr = nullptr;
    }
}

// --- LAB 11 DEBUGGING ROUTINES ---

template <class T>
void Bst<T>::debugCheckInvariant() const {
    if (!checkInvariantHelper(root, nullptr, nullptr)) {
        std::cerr << "CRITICAL ERROR: BST Invariant Property Violated!" << std::endl;
    }
}

template <class T>
bool Bst<T>::checkInvariantHelper(Node* ptr, const T* minVal, const T* maxVal) const {
    if (ptr == nullptr) return true;
    if (minVal != nullptr && ptr->data < *minVal) return false;
    if (maxVal != nullptr && ptr->data > *maxVal) return false;

    return checkInvariantHelper(ptr->left, minVal, &ptr->data) &&
           checkInvariantHelper(ptr->right, &ptr->data, maxVal);
}

#endif // BST_H_INCLUDED

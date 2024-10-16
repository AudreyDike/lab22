#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val;
            prev = p;
            next = n;
        }
    };
    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Push to the back of the list
    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) { 
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (current == nullptr) { 
            push_back(value);
        } else {
            newNode->next = current;
            newNode->prev = current->prev;

            if (current->prev) {
                current->prev->next = newNode;
            } else {
                head = newNode; // Update head if inserting at the front
            }
            current->prev = newNode;
        }
    }

    // Delete a node by position
    void delete_pos(int position) {
        if (position < 0 || !head) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* current = head;

        // Traverse to the desired position
        for (int i = 0; i < position && current != nullptr; ++i) {
            current = current->next;
        }

        if (!current) { // If the position is out of bounds
            cout << "Position out of bounds." << endl;
            return;
        }

        if (current == head) { // If the node to delete is the head
            pop_front();
        } else if (current == tail) { // If the node to delete is the tail
            pop_back();
        } else { // If the node to delete is in the middle
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
    }
// Delete the head node
    void pop_front() {
        if (!head) return; // List is empty
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr; // Update the new head
        else tail = nullptr; // List is empty now
        delete temp;
    }

    // Delete the tail node
    void pop_back() {
        if (!tail) return; // List is empty
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr; // Update the new tail
        else head = nullptr; // List is empty now
        delete temp;
    }

    // Rename delete() to delete_val() for deleting by value
    void delete_val(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                if (current == head) pop_front();
                else if (current == tail) pop_back();
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    delete current;
                }
                return; // Value deleted; exit
            }
            current = current->next;
        }
        cout << "Value not found in the list." << endl;
    }
 // Display the list
    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver to test the updated class
int main() {
    DoublyLinkedList dll;

    // Testing push_back and display
    for (int i = 10; i <= 20; i += 2) {
        dll.push_back(i);
    }
    cout << "List after push_back: ";
    dll.display();

    // Testing push_front
    dll.push_front(5);
    cout << "List after push_front(5): ";
    dll.display();

    // Testing insert_after
    dll.insert_after(15, 3); // Insert 15 after position 3
    cout << "List after insert_after(15, 3): ";
    dll.display();

    // Testing delete_pos
    dll.delete_pos(0); // Delete head
    cout << "List after delete_pos(0): ";
    dll.display();

    dll.delete_pos(3); // Delete position 3
    cout << "List after delete_pos(3): ";
    dll.display();

    dll.delete_pos(100); // Invalid position
    cout << "Attempting to delete at invalid position (100): ";
    dll.display();

    // Testing pop_front and pop_back
    dll.pop_front();
    cout << "List after pop_front: ";
    dll.display();

    dll.pop_back();
    cout << "List after pop_back: ";
    dll.display();

    // Testing delete_val
    dll.delete_val(12); // Delete by value
    cout << "List after delete_val(12): ";
    dll.display();

    return 0;
}


#include <iostream>
#include <cstdlib>
using namespace std;
// Singly Linked List Node
struct Node {
    int data;
    Node* next;
};
// Doubly Linked List Node
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};
// Circular Linked List Node
struct CNode {
    int data;
    CNode* next;
};
// Class for Singly Linked List
class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() {
        head = nullptr;
    }
    void create() {
        head = nullptr;
        cout << "Singly Linked List Created.\n";
    }
    void insertStart() {
        int val;
        cout << "Enter value to insert at start: ";
        cin >> val;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at the start.\n";
    }
    void insertMiddle() {
        int val, pos;
        cout << "Enter value and position to insert: ";
        cin >> val >> pos;
        Node* newNode = new Node();
        newNode->data = val;

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Node inserted at position " << pos << ".\n";
        } else {
            cout << "Position out of range.\n";
        }
    }
    void insertLast() {
        int val;
        cout << "Enter value to insert at last: ";
        cin >> val;
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Node inserted at the end.\n";
    }
    void deleteStart() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from start.\n";
    }
    void deleteMiddle() {
        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            cout << "Node deleted from position " << pos << ".\n";
        } else {
            cout << "Position out of range.\n";
        }
    }
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node deleted from last.\n";
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        cout << "Node deleted from last.\n";
    }
    void split() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Split the list
        Node* secondHalf = slow->next;
        slow->next = nullptr;
        cout << "First half: ";
        display();
        cout << "Second half: ";
        SinglyLinkedList secondList;
        secondList.head = secondHalf;
        secondList.display();
    }
    void merge(SinglyLinkedList& list2) {
        if (head == nullptr) {
            cout << "List is empty. Merging with second list.\n";
            head = list2.head;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = list2.head;
        cout << "Lists merged.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
// Class for Doubly Linked List
class DoublyLinkedList {
public:
    DNode* head;
    DoublyLinkedList() {
        head = nullptr;
    }
    void create() {
        head = nullptr;
        cout << "Doubly Linked List Created.\n";
    }
    void insertStart() {
        int val;
        cout << "Enter value to insert at start: ";
        cin >> val;
        DNode* newNode = new DNode();
        newNode->data = val;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Node inserted at the start.\n";
    }
    void insertMiddle() {
        int val, pos;
        cout << "Enter value and position to insert: ";
        cin >> val >> pos;
        DNode* newNode = new DNode();
        newNode->data = val;
        DNode* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
            cout << "Node inserted at position " << pos << ".\n";
        } else {
            cout << "Position out of range.\n";
        }
    }
    void insertLast() {
        int val;
        cout << "Enter value to insert at last: ";
        cin >> val;
        DNode* newNode = new DNode();
        newNode->data = val;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            DNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Node inserted at the end.\n";
    }
    void deleteStart() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Node deleted from start.\n";
    }
    void deleteMiddle() {
        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            DNode* delNode = temp->next;
            temp->next = temp->next->next;
            if (temp->next != nullptr) {
                temp->next->prev = temp;
            }
            delete delNode;
            cout << "Node deleted from position " << pos << ".\n";
        } else {
            cout << "Position out of range.\n";
        }
    }
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            cout << "Node deleted from last.\n";
            return;
        }
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->prev->next = nullptr;
        delete temp;
        cout << "Node deleted from last.\n";
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};
// Class for Circular Linked List
class CircularLinkedList {
public:
    CNode* head;
    CircularLinkedList() {
        head = nullptr;
    }
    void create() {
        head = nullptr;
        cout << "Circular Linked List Created.\n";
    }
    void insertStart() {
        int val;
        cout << "Enter value to insert at start: ";
        cin >> val;
        CNode* newNode = new CNode();
        newNode->data = val;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Node inserted at the start.\n";
    }
    void insertLast() {
        int val;
        cout << "Enter value to insert at last: ";
        cin >> val;
        CNode* newNode = new CNode();
        newNode->data = val;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << "Node inserted at the end.\n";
    }
    void deleteStart() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Node deleted from start.\n";
        } else {
            CNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
            cout << "Node deleted from start.\n";
        }
    }
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
            cout << "Node deleted from last.\n";
        } else {
            CNode* temp = head;
            while (temp->next->next != head) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = head;
            cout << "Node deleted from last.\n";
        }
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        CNode* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
};
int main() {
    int choice, subChoice;
    SinglyLinkedList sList;
    DoublyLinkedList dList;
    CircularLinkedList cList;
    while (true) {
        cout << "\nChoose your operation:\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Circular Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            while (true) {
                cout << "\nSingly Linked List Operations:\n";
                cout << "1. Create\n";
                cout << "2. Insert Start\n";
                cout << "3. Insert Middle\n";
                cout << "4. Insert Last\n";
                cout << "5. Delete Start\n";
                cout << "6. Delete Middle\n";
                cout << "7. Delete Last\n";
                cout << "8. Split\n";
                cout << "9. Merge\n";
                cout << "10. Display\n";
                cout << "11. Exit\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: sList.create(); break;
                case 2: sList.insertStart(); break;
                case 3: sList.insertMiddle(); break;
                case 4: sList.insertLast(); break;
                case 5: sList.deleteStart(); break;
                case 6: sList.deleteMiddle(); break;
                case 7: sList.deleteLast(); break;
                case 8: sList.split(); break;
                case 9: {
                    SinglyLinkedList secondList;
                    secondList.create();
                    sList.merge(secondList);
                    break;
                }
                case 10: sList.display(); break;
                case 11: break;
                default: cout << "Invalid option.\n";
                }
                if (subChoice == 11) break;
            }
            break;

        case 2:
            while (true) {
                cout << "\nDoubly Linked List Operations:\n";
                cout << "1. Create\n";
                cout << "2. Insert Start\n";
                cout << "3. Insert Middle\n";
                cout << "4. Insert Last\n";
                cout << "5. Delete Start\n";
                cout << "6. Delete Middle\n";
                cout << "7. Delete Last\n";
                cout << "8. Display\n";
                cout << "9. Exit\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: dList.create(); break;
                case 2: dList.insertStart(); break;
                case 3: dList.insertMiddle(); break;
                case 4: dList.insertLast(); break;
                case 5: dList.deleteStart(); break;
                case 6: dList.deleteMiddle(); break;
                case 7: dList.deleteLast(); break;
                case 8: dList.display(); break;
                case 9: break;
                default: cout << "Invalid option.\n";
                }
                if (subChoice == 9) break;
            }
            break;

        case 3:
            while (true) {
                cout << "\nCircular Linked List Operations:\n";
                cout << "1. Create\n";
                cout << "2. Insert Start\n";
                cout << "3. Insert Last\n";
                cout << "4. Delete Start\n";
                cout << "5. Delete Last\n";
                cout << "6. Display\n";
                cout << "7. Exit\n";
                cout << "Enter choice: ";
                cin >> subChoice;

                switch (subChoice) {
                case 1: cList.create(); break;
                case 2: cList.insertStart(); break;
                case 3: cList.insertLast(); break;
                case 4: cList.deleteStart(); break;
                case 5: cList.deleteLast(); break;
                case 6: cList.display(); break;
                case 7: break;
                default: cout << "Invalid option.\n";
                }
                if (subChoice == 7) break;
            }
            break;
        case 4:
            cout << "Exiting program.\n";
            exit(0);

        default:
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
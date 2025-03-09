#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtFirst(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtLast(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertAtNth(int data, int position) {
        Node* newNode = new Node();
        newNode->data = data;
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1) {
            insertAtFirst(data);
            return;
        }

        Node* temp = head;
        int count = 1;
        while (count < position - 1 && temp->next != head) {
            temp = temp->next;
            count++;
        }

        if (temp->next == head && count < position - 1) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtCenter(int data) {
        if (head == nullptr) {
            insertAtFirst(data);
            return;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast != head && fast->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = slow->next;
        slow->next = newNode;
    }
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to display the nodes in reverse order
    void displayReverse(Node* node) {
        if (node == nullptr) return;
        static bool isFirstCall = true;

        // Handle the first call by skipping the head node
        if (isFirstCall) {
            isFirstCall = false;
            node = node->next;
        }

        if (node != head) {
            displayReverse(node->next);
        }
        cout << node->data << " ";
    }

    void reverseDisplay() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        displayReverse(head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtFirst(10);
    cll.insertAtFirst(20);
    cll.insertAtLast(30);
    cll.insertAtLast(40);
    cll.insertAtNth(25, 3);
    cll.insertAtCenter(35);

    cout << "List in normal order: ";
    cll.display();

    cout << "List in reverse order: ";
    cll.reverseDisplay();

    return 0;
}

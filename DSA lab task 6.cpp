#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = NULL;
    }

    void insert_at_start(int d) {
        Node* n = new Node(d);
        n->next = head;
        head = n;
    }

    void insert_at_end(int d) {
        Node* n = new Node(d);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void insert_at_any_position(int p, int d) {
        if (p < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (p == 1) {
            insert_at_start(d);
            return;
        }
        Node* temp = head;
        for (int i = 1; i < p - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }
        Node* n = new Node(d);
        n->next = temp->next;
        temp->next = n;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void delete_first_node() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void delete_last_node() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void delete_the_center_node() {
        if (head == NULL || head->next == NULL) {
            cout << "List is too short to delete the center node" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;
        delete slow;
    }

    void delete_at_any_position(int p) {
        if (head == NULL || p < 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (p == 1) {
            delete_first_node();
            return;
        }
        Node* temp = head;
        for (int i = 1; i < p - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
        cout << "Deleted node at position " << p << endl;
    }
};

int main() {
    LinkedList list;
    list.insert_at_end(19);
    list.insert_at_end(27);
    list.insert_at_start(15);
    list.insert_at_start(12);
    list.insert_at_any_position(2, 9);
    
    cout << "Linked List: " << endl;
    list.display();
    
    list.delete_at_any_position(3);
    list.display();
    
    list.delete_first_node();
    cout << "After deleting first node:" << endl;
    list.display();
    
    cout << "After deleting last node:" << endl;
    list.delete_last_node();
    list.display();
    
    cout << "After deleting center node:" << endl;
    list.delete_the_center_node();
    list.display();

    return 0;
}
#include<iostream>
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

class Linkedlist {
public:
    Node* head;

    Linkedlist() {
        head = NULL;
    }

    void insertATend(int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void displayFirstNode() {
        if (head != NULL) {
            cout << "First node: " << head->data << endl;
        } else {
            cout << "List is empty" << endl;
        }
    }

    void displayLastNode() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        cout << "Last node: " << temp->data << endl;
    }

    void displayNthNode(int n) {
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < n) {
            temp = temp->next;
            count++;
        }
        if (temp != NULL)
            cout << "Node at position " << n << ": " << temp->data << endl;
        else
            cout << "Position " << n << " is out of bounds!" << endl;
    }

    void displayCenterNode() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Center Node: " << slow->data << endl;
    }
};

int main() {
    Linkedlist list;

    list.insertATend(10);
    list.insertATend(20);
    list.insertATend(30);
    list.insertATend(40);
    list.insertATend(50);

    
    list.displayFirstNode();  
    list.displayLastNode();   
    list.displayNthNode(3);   
    list.displayCenterNode();

    return 0;
}

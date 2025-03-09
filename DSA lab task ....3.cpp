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

class LinkedList {
    public:
        Node* head;

        LinkedList() {
            head = NULL;
        }

        void insertATstart(int d) {
            Node* newNode = new Node(d);
            newNode->next = head;
            head = newNode;
            display();  // Corrected placement
        }

        void insertATend(int d) {
            Node* newNode = new Node(d);

            if (head == NULL) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
            display();  // Corrected placement
        }

        void display() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList list;
    cout << "insert at start" << endl;
    list.insertATstart(1);
    list.insertATstart(2);
    list.insertATstart(3);

    cout << "insert at end" << endl;
    list.insertATend(4);
    list.insertATend(5);
    list.insertATend(6);

    return 0;
}

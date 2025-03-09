#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
	Node(int d){
		data = d;
		next = nullptr;
	}
};
class singlyLinkedList {
	public:
		Node*head;
		
		singlyLinkedList(){
			head = NULL;
		}
		void insert_at_end(int d){
			Node* newNode = new Node(d);
			
			if(head == NULL){
				head = newNode;
				return;
			}
			
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;				
			}
			temp->next = newNode;
		}
		
		void display(){
			Node* temp = head; 
			while(temp !=NULL){
				cout << temp->data << "-> ";
				temp = temp->next;
			}
			cout<<"NULL"<<endl;
		}
		
		void merge(singlyLinkedList& list2){
			if(head == NULL){
				head = list2.head;
				return;
			}
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp -> next;
			}
			temp -> next = list2.head;
		}
};

int main(){
  singlyLinkedList list1 , list2;
    list1.insert_at_end(1);
	list1.insert_at_end(3);
	list1.insert_at_end(5);
	
	list2.insert_at_end(2);
	list2.insert_at_end(4);
	list2.insert_at_end(6);
	
	cout<<"First singly Linked List:";
	list1.display();
	cout<<"second singly Linked List:";
	list2.display();
	
	list1.merge(list2);
	
	cout<<"Merged singly Linked List:";
	list1.display();
	
	return 0;
}
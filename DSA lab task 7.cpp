#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
Node(int d){
	data= d;
	next=prev=NULL;
}
};
class DoublyList{
	public:
		Node* head;
		Node* tail;
		
public:
	DoublyList(){
		head=tail=NULL;
	}
	
void insertATstart(int d){
	Node* newNode= new Node(d);
	if(head == NULL){
		head= tail=newNode;
		
	}
	
	else{
		newNode->next = head;
		head->prev=newNode;
		head = newNode;
	}
}

void insertATend(int d){
	Node* newNode= new Node(d);
	if(head==NULL){
		head= tail=newNode;
	}
}
void deleteATstart(){
	if(head == NULL){
		cout<<"list is empty"<<endl;
		return;
	}
	Node*temp = head;
	head = head->next;
	if(head!=NULL){
		head->prev = NULL;
	}
	else{
		tail = NULL;
	}
	
	delete temp;
	cout <<" first node delete:"<<endl;
}
void deleteATend(){
	if(tail == NULL){
		cout<<" list is empty "<<endl;
		return;
	}
	Node*temp = tail;
	tail = tail->prev;
	if(tail!= NULL){
		 tail->next = NULL;
	}
	else{
	
	head = NULL;
	}
	delete temp;
	cout<<"last node delete:"<<endl;
}
void displayForward(){
	Node* temp = head;
	cout<<"Forward :";
	while(temp != NULL){
		cout << temp->data<<" ";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}
void displayReverse(){
	Node* temp = head;
	cout<<"Reverse :";
	while(temp != NULL){
		cout << temp->data<<" ";
		temp = temp->prev;
}
cout<<"NULL"<<endl;
}

};


int main(){

 DoublyList dll;
dll.insertATstart(3);
dll.insertATstart(2);
dll.insertATstart(1);
dll.displayForward();
dll.displayReverse();

dll.insertATend(4);
dll.insertATend(5);
dll.displayForward();
dll.displayReverse();	

dll.deleteATstart();
dll.displayForward();
dll.displayReverse();

dll.deleteATend();
dll.displayForward();
dll.displayReverse();
return 0;

}

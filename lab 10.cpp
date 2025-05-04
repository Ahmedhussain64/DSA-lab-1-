//                                     lab 10
//- Stack with Linkedlist and Array
//Tasks:
//1. With Array; Push, Pop, Display 
//2. With Linkedlist; Push, Pop, Display

#include<iostream>
using namespace std;

const int size = 100;
int stack[size];
int top = -1;

void push(int value) {
if(top == size - 1){	
	cout<<"stack overflow";
}
else {
        top++;
        stack[top] = value;
    }
}


void pop(){
	if(top== -1){
	cout<<"stack underflow";	
	}
	else{
		cout<<"Popped :"<<stack[top]<<endl;
		top--;
	}
	
}


void display() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
	push(50);
	push(70);
	display();
    pop();
   	display();
    return 0;
}


// Stack using Linked List 
// struct Node{
// 	int data;
// 	Node* next;
// };
// 	
// 	
//Node*top = nullptr;
//void push ( int value) {
//	Node *newNode = new Node;
//	newNode->data = value;
//	newNode->next = top;
//	top = newNode;
//}
//
//void pop(){
//   if (top == nullptr)	{
//   	 cout<<"stack underflow"; 	
//   }
//   else{
//   	cout<< "Popped : "<<top->data<<endl;
//   	Node* temp = top;
//   	top = top ->next;
//   	delete temp;
//   }	
//}
//
//void display (){
//	if (top == nullptr){
//	 cout<<"stack is empty"	;
//}
//else{
//	cout<<"stack elements"<<endl;
//	Node* current = top;
//	 while (current != nullptr) {
//            cout << current->data << " ";
//            current = current->next;
//        }
//        cout << endl;
//    }
//}
//
//
//int main() {
//	push(500);
//	push(1000);
//	display();
//	pop();
//	display();
//	return 0;
//   
//}









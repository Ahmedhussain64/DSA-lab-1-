//dynamic memory allocation and pointer manipulation.
//Ahmad hussain. roll no. bssem-064
#include<iostream>
using namespace std;
int main(){
	int* ptr = new int(10);
	 cout << "Before modification:" << endl;
	 cout<<"value = "<<*ptr <<", Memory Address = "<< ptr << endl;
	 *ptr = 20;
	 cout<<" After modification:"<<endl;
	 cout<<"Value = "<<*ptr << ", Memory Address = " << ptr <<endl;
	 delete ptr;
	 ptr = nullptr; 
	 return 0;
}
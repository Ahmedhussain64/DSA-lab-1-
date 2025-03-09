
#include<iostream>
using namespace std;

int findMax(int arr[], int n){
     if (n == 0){
     	 cout<<"Array is empty!"<<endl;
     	 return -1;
	 }
	 
	 int maxval = arr[0];
	 for(int i = 1; i < n; i++){
	 	if(arr[i] > maxval){
	 		maxval = arr[i];
		 }
	 }
	 return maxval;
}

int main(){
	int arr[] = { 12, 34, 76, 10, 9};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"The larger number in the array is:"<<findMax(arr, n)<<endl;
	return 0;
}
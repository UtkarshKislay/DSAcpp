
#include<iostream>
using namespace std;    
int partition(int *arr, int si , int ei){
	int count =0;
	int i = si+1;
	//int j = ei-1;
	while(i<=ei){
		if(arr[i]<=arr[si]){
			count++;
		} i++;
	} 
	int temp =arr[si+count];
	arr[si+count] = arr[si];
	arr[si] = temp;   
	//partion ka index
	int PI = si+count;
	for(int i = si, j=ei;i<=PI&&j>PI;){
		if(arr[i]<= arr[PI]){
			i++;
		} 
		else if(arr[j]> arr[PI]){
			j--;
		}  
		else {
			int temp = arr[i];
			arr[i]= arr[j];
			arr[j]= temp; 
			i++;
			j--;
		}
	}  
	return PI;
}
 void quicksorthelper(int *arr, int si , int ei){  
  if (si>=ei){
  	return;
  }
	int PI = partition(arr,si , ei);
	quicksorthelper(arr,si,PI-1);
	quicksorthelper(arr,PI+1,ei);
}
 void quickSort(int *arr , int size){
 	quicksorthelper(arr, 0,size-1);
 }

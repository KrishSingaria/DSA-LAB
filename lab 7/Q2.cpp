#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<float>& bucket){
	for (int i = 0; i < bucket.size(); i += 1)
	{
		float key = bucket[i];
		int j = i-1;
		while (j>=0 && bucket[j] > key)
		{
			bucket[j+1] = bucket[j];
			j--;
		}
		bucket[j+1] = key;
	}
}
void bucketSort(vector<float> & arr,int n){
 	vector<float> b[10];
 	
 	for (int i = 0; i < n; i += 1)
 	{
 		int bi = 10*arr[i];
 		b[bi].push_back(arr[i]);
 	}
 	for (int i = 0; i < n; i += 1)
 	{
 		insertionSort(b[i]);
 	}
 	
 	int index = 0;
 	for (int i = 0; i < 10; i += 1)
 	{
 		for (int j = 0; j < b[i].size(); j += 1)
 		{
 			arr[index] = b[i][j];
			index++; 
 		}	
 	}
}
void Print(vector<float>&arr){
	for (int i = 0; i < arr.size(); i += 1)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	vector<float> arr = {0.897,0.565,0.656,0.1234,0.665,0.3434};
	int n = arr.size();
	cout<<"Original Array: ";
	Print(arr);
	
	bucketSort(arr,n);
	
	cout<<"Sorted Array: ";
	Print(arr);
	return 0;
}
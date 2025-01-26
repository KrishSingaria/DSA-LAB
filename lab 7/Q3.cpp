#include <iostream>
#include <vector>

using namespace std;
void swap(int &a,int &b){
	int temp = a;
	a = b;
	b = temp;
}
void quickSort(vector<int>&arr,int left,int right){
	if (left < right)
	{
		int pivot = arr[right];
		int i = left -1;
		for (int j = left; j <= right -1; j += 1)
		{
			if (arr[j]<=pivot)
			{
				i++;
				swap(arr[i],arr[j]);
			}
		}
		swap(arr[i+1],arr[right]);
		int partition_index = i+1;
		quickSort(arr,left,partition_index-1);
		quickSort(arr,partition_index+1,right);
	}
}
void Print(vector<int>&arr){
	for (int i = 0; i < arr.size(); i += 1)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main ()
{
	vector<int> arr = {170,45,75,90,802,24,2,66};
	cout<<"Original Array: ";
	Print(arr);
	
	quickSort(arr,0,arr.size()-1);
	
	cout<<"Sorted Array: ";
	Print(arr);
	return 0;
}
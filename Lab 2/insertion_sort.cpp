#include <iostream>
using namespace std;
void insertionSort(int arr[],int n){
    int i,j,key;
    for (i = 1; i <= n-1; i++) {
        key = arr[i];
        j = i -1;
        while (arr[j]>key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]  = key;
    }
}
int main()
{
    int array[] ={12,11,13,5,6};
    int N = sizeof(array)/sizeof(array[0]);
    cout<<"Origanal arr:";
    for (int i = 0; i < N; i++)
    {
        cout<<array[i]<< " ";
    }
    cout<<endl;
    
    insertionSort(array,N);
    cout<<"final arr:";
    for (int i = 0; i < N; i++)
    {
        cout<<array[i]<< " ";
    }
    cout<<endl;
    return 0;
}

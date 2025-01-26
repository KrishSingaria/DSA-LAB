#include <vector>
using namespace std;

void quicksort(vector<int>&arr,int left ,int right){
    if(left>right){
        int i = left -1;
        int pivot = arr[right];
        for (int j = left; j < right-1; j++)
        {
            if(arr[j]<= pivot){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[right]);
        int partition_index = i+1;
        quicksort(arr,partition_index+1,right);
        quicksort(arr,left,partition_index-1);
        
    }
}
void countingSort(int arr[],int n, int exp){
    int output[n];
    int i,count[10] = {0};

    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;
    for (i = 1; i < 10; i++)
        count[i]+=count[i-1];
    for (i = n-1; i >=0; i--){
        output[count[(arr[i]/exp)%10]-1] =arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for (i = 0; i < n; i++)   
        arr[i] = output[i];
    
}
int getMax(int arr[],int n){

}
void radixSort(int arr[],int n){
    int m = getMax(arr,n);
    for(int exp = 1; m/exp >0; exp*=10){
        countingSort(arr,n,exp);
    }
}
void insertionsort(vector<float>&arr){
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i-1;
        float key = arr[i];
        while (j>=0 && key < arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    
}
void bucketSort(vector<float>& arr,int n){
    vector<float> b[10];

    for (int i = 0; i < n; i++)
    {
        int bi = 10*arr[i];
        b[bi].push_back(arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        insertionsort(b[i]);
    }
    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            arr[index] =b[i][j];
            index++;
        }
        
    }
}
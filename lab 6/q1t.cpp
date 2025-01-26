#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent(int i){
    return (i-1)/2;
}
void maxHeapify(vector<int>& arr,int n,int i){
    int max = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && arr[left]>arr[max])
        max = left;
    if(right<n && arr[right]>arr[max])
        max =right;
    if(max!=i){
        swap(arr[i],arr[max]);
        maxHeapify(arr,n,max);
    }
}
int extractMax(vector<int>&arr,int& n){
    if(n<=0){
        cout<< "heap underflow" <<endl;
        return -1;
    }
    int max = arr[0];
    swap(arr[0],arr[n-1]);
    maxHeapify(arr,n-1,0);
    n--;
    return max;
}
void increaseKey(vector<int>&arr,int&n,int i,int newkey){
    if(i<0||i>n||n<=0||arr[i]>newkey){
        return;
    }
    arr[i] = newkey;
    while (i>0 && arr[parent(i)]<arr[i])
    {
        swap(arr[parent(i)],arr[i]);
        i = parent(i);
    }
    
}
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* newNode(int data)
{
    struct Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
struct compare
{
    bool operator()(struct Node* a, struct Node* b){
        return a->data > b->data;
    }
};

struct Node* mergeKsortedList(Node* arr[],int k){
    priority_queue<Node*,vector<Node*>,compare> pq;

    for (int i = 0; i < k; i++)
    {
        if (arr[i]!=nullptr)
        {
            pq.push(arr[i]);
        }
    }
    if (pq.empty())
    {
        return;
    }

    struct Node* dummy =newNode(0);
    struct Node* last = dummy;
    while (!pq.empty())
    {
        struct Node* curr = pq.top();
        pq.pop();

        last->next= curr;
        last = last->next;

        if(curr->next!= nullptr)
            pq.push(curr->next);
    }
    return dummy->next;
    
    
    

}
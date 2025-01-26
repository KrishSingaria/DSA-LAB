#include <iostream>
using namespace std;
class List{
public:
struct node
{
    node* pre=nullptr;
    int data;
    node* next=nullptr;
};
node* head=nullptr;
void push(int data){
    if (head!= nullptr){
        node* temp = new node;
        temp->data = data;
        temp->next = head;
        head = temp;
        temp->pre =nullptr;
        temp->next->pre =temp;
    }else{
        head = new node;
        head->data = data;
    }
}
int pop(){
    node* temp = head;
    int x = temp->data;
    head = temp->next;
    temp->next =nullptr;
    head->pre= nullptr;
    return x;
}
void remove(node* ptr){
    ptr->pre->next =ptr->next;
    if(ptr->next != nullptr) ptr->next->pre = ptr->pre;
}
void insert(int x,node*ptr){
    node* temp = new node;
    temp->data= x;
    temp->pre = ptr;
    temp->next = ptr->next;
    ptr->next = temp;
    temp->next->pre =temp;
}
int peek(){
    return head->data;
}
void Print(){
    if(head!=nullptr)
    {   
        node*ptr = head;
        while (ptr->next!=nullptr)
        {
            cout<<ptr->data<< " ";
            ptr=ptr->next;
        }
        cout<<ptr->data;
    }else cout<<"Empty Stack";
}
};
void InsertionSort(List& A,int n){
    List::node* mainPtr = A.head->next;
    while (mainPtr!=nullptr)
    {
        int key = mainPtr->data;
        List::node* ptr = mainPtr->pre;
        while (ptr->data >key && ptr !=A.head)
        {
            ptr = ptr->pre;
        }
        List::node*temp = mainPtr;
        mainPtr = mainPtr->next;
        A.remove(temp);
        if(ptr->data >key && ptr ==A.head) A.push(key);
        else A.insert(key,ptr);     
    }
}
int main()
{
    List A;
    int unSortedList[] = {3,5,1,2,7,8,9,4,6};
    int n = sizeof(unSortedList)/sizeof(int);
    for(int i=0 ;i<n;i++) A.push(unSortedList[i]);
    cout << "\nUnsorted list is : ";
    A.Print();
    cout << endl << "Sorted list is : ";
    InsertionSort(A,n);
    A.Print();
    return 0;
}
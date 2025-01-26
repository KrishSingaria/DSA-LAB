#include <iostream>
using namespace std;
class Stack
{
    public:  
    struct node
    {
        int data;
        node* next;
    };
    node *head = NULL;
    bool underflow(){
        if(head == NULL)return true;
        else return false;
    }
    void push(int key){
        node* temp = new node;
        temp->data=key;
        temp->next=head;
        head = temp;
    }
    int pop(){
        if(underflow()) {
            cout << "UnderFlow\n";
            return -1;
        }else{
            int x = head->data;
            head = head->next;
            return x; 
        }
    }
    int peek(){
        int x = head->data;
        return x;
    }
    void Print(){
        if(head!=NULL)
        {   
            node*ptr = head;
            while (ptr->next!=NULL)
            {
                cout<<ptr->data<< " ";
                ptr=ptr->next;
            }
            cout<<ptr->data;
        }else cout<<"Empty Stack";
    }
};
void Move(Stack &start,Stack &end,int& steps){
    end.push(start.pop());
    steps++;
}
void Hanoi(int n,Stack &start,Stack &end,Stack &other,int& steps){
    if(n==1){
        Move(start,end,steps);
    }else{
        Hanoi(n-1,start,other,end,steps);
        Move(start,end,steps);
        Hanoi(n-1,other,end,start,steps);
    }
}
int main()
{
    int steps = 0;
    Stack A("A"),B("B"),C("C");
    int n;
    cout<<"number of rings:";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        A.push(n-i);
    }
    cout<<"A: ";
    A.Print();
    cout<<"\nB: ";
    B.Print();
    cout<<"\nC:";
    C.Print();
    Hanoi(n,A,C,B,steps);
    cout<<"\nAfter moving disk from A to C.";
    cout<<"\nA: ";
    A.Print();
    cout<<"\nB: ";
    B.Print();
    cout<<"\nC:";
    C.Print();
    cout<<"\nNumber of Steps: "<<steps<<endl;
    return 0;
}

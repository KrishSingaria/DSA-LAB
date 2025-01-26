#include <iostream>
#include <cmath>
using namespace std;

class LinkedList {
public:
    struct Node {
        int data;
        Node* next=nullptr;
    };
    int size = 0; // Number of nodes in the list.
    Node* head =nullptr;
    void insert(int data) {
        if(head == nullptr){
            head = new Node();
            head->data = data;
            head->next = nullptr;
            size++;
        } else{
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    void remove() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
        }
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
class skipList {
public:
struct expressNode
{
    int data;
    expressNode* next =nullptr;
    LinkedList::Node* orignal = nullptr;   
};
expressNode* head = nullptr;
void Skipify(LinkedList& A){
    int expressNodes = sqrt(A.size) - 1;
    head = new expressNode;
    head->data = A.head->data;
    head->orignal = A.head;
    LinkedList::Node* ptrL = A.head;
    expressNode* ptrS = head;
    for (int i = 0; i < expressNodes; i++)
    {
        expressNode* temp = new expressNode;
        for (int j = 0; j < expressNodes; j++)
        {
            ptrL = ptrL->next;
        }
        temp->data = ptrL->data;
        ptrS->next = temp;
        temp->orignal = ptrL;
        ptrS=temp;
    }
}

void search(int x)
{
    int steps = 0;
    expressNode* curr = head;
    while (curr->next!=nullptr && curr->next->data<x)
    {
        curr = curr->next;
        steps++;
    }
    LinkedList::Node* NormalLane=curr->orignal;
    while (NormalLane->next!=nullptr && NormalLane->data!=x)
    {
        steps++;
        NormalLane=NormalLane->next;
    }
    if (NormalLane->data ==  x)
    {
        cout<< x << " found in number of "<<steps<< " steps."<<endl;
    }else
    {
        cout<<"Element not present!"<<endl;
    }
}
};
int main()
{
    LinkedList A;
    for (int i = 9; i > 0; i--)
    {
        A.insert(i);
    }
    A.printList();
    skipList B;
    B.Skipify(A);
    B.search(9);
    return 0;
}


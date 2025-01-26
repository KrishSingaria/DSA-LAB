#include <iostream>
using namespace std;
class Stack
{
    public:
    struct node
    {
        char data;
        node* next;
    };
    node *head = NULL;
    bool underflow(){
        if(head == NULL)return true;
        else return false;
    }
    void push(char key){
        node* temp = new node;
        temp->data=key;
        temp->next=head;
        head = temp;
    }
    char pop(){
        if(underflow()) {
            return -1;
        }else{
            int x = head->data;
            head = head->next;
            return x; 
        }
    }
    char peek(){
        int x = head->data;
        return x;
    }
};
void ParenthesisMatching(string eq){
    Stack s;
    for(char i:eq){
        if(i=='(' || i=='[' || i =='{'){
            s.push(i);
        }else if(i==')'|| i==']'|| i=='}'){
            if((s.peek()=='(' && i==')') || (s.peek()=='[' && i==']') || (s.peek()=='{' && i=='}')){
                s.pop();
            }else{
                cout<<"Eqution:"<<eq<<" is Not balanced"<<endl;
                return;
            }
        }
    }
    if(!s.underflow()){
        cout<<"Eqution:"<<eq<<" is Not Balanced"<<endl;
    }else{
        cout<<"Eqution:"<<eq<<" is Balanced"<<endl;
    }
}
int main()
{
    string eq1[] = {"(3+2*(4-1)","2*[{5+3}-2*(4-2)]","((3+2)-[6-(2*3)]"};
    for(string i : eq1){
        ParenthesisMatching(i);
    }
    return 0;
} 
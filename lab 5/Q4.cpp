#include <iostream>
using namespace std;
struct node
{
    int data;
    node* left=nullptr;
    node* right=nullptr;
    node* parent=nullptr;
};
class BST{
public:
node* root=nullptr;
void insert(node* T,int value,node*TParent) { 
    if(T==nullptr){
        node* temp = new node;
        temp->data =value;
        temp->parent = TParent;
        if(TParent != nullptr){
            if(TParent->data>temp->data){
                TParent->left = temp;
            }else{
                TParent->right = temp;
            }
        }else{
            root = temp;
        }
    }else{
        if(value < T->data) {
           return insert(T->left ,value,T);   
        } else{
           return insert(T->right,value,T);    
        } 
    }
}
void Transplant(BST &T, node *u, node *v) {    
    if (u->parent == nullptr) { 
       T.root = v; 
    }else {  
       if (u->data > u->parent->data)    
          u->parent->right = v;  
       else
          u->parent->left = v; 
    }  
    v->parent = u->parent;
}
node* getMinNode(node* T){
    node* y = T;
    while (y->left!=nullptr)
    {
        y = y->left;
    }
    return y;
}
void Delete(BST& T, node* z) {  
    if(z->left == nullptr){
        Transplant(T,z,z->right);
    }else if(z->right == nullptr){
        Transplant(T,z,z->left);
    }else{
        node* y = T.getMinNode(z->right);
        if(y->parent != z) {
            Transplant(T,y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(T,z,y);
        y->left = z->left;
        y->left->parent=y;
    }
}
node* search(int x){
    node* ptr = root;
    while (ptr!=nullptr &&ptr->data!=x)
    {
        if(ptr->data>x)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if(ptr!=nullptr&& ptr->data==x){
        return ptr;
    }else{
        return nullptr;
    }
}
void inorderTraversal(node *T)
{
    if(T!=nullptr)
    {
        inorderTraversal(T->left);
        cout << T->data << " ";
        inorderTraversal(T->right);
    }
}
};
int main()
{
    int values[] ={12,5,18,2,15,9,19,17};
    BST A;
    for(int i:values)
    {
        A.insert(A.root,i,nullptr);
    }
    A.inorderTraversal(A.root);
    cout<<"\n";
    A.search(15);
    A.Delete(A,A.search(15));
    cout<<"After deleting 15:\n";
    A.inorderTraversal(A.root);
    return 0;
}

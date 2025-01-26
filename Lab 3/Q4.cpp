#include <iostream>
#include <vector>
using  namespace std;
class Array2D{
public:
struct node
{
    int index;
    int data;
    node* next = nullptr;
};
vector<node*> arr = {nullptr};
void insert(int col,int val,int row)
{  
    node *temp= new node();
    temp->index = col;
    temp->data =val;
    while (row>=arr.size())
    {
        arr.push_back(nullptr);
    }
    if (arr[row]!=nullptr){
        node* ptr;
        ptr=arr[row];
        while (ptr->next != nullptr)
            ptr=ptr->next;
        ptr->next=temp;
    }
    else {
        arr[row]=temp;
    }
}
void Print(){
    cout<<"( Index , value )"<<endl;
    for (int i=0;i<arr.size();i++)
    {
        node* ptr=arr[i];
        cout<< "Row "<< i<< " : ";
        while (ptr != nullptr)
        {
           cout <<"( "<<ptr->index<<", "<<ptr->data<<" )"<<" ";
           ptr=ptr->next;
        }
        cout<<endl;
    }
}
int Peek(int row,int column)  // return the element at given position in matrix
{
    if(row<arr.size()){
        node* ptr=arr[row];
        while (ptr != nullptr){
            if(ptr->index == column) return ptr->data;
            else ptr = ptr->next;
        }
        return 0;   //return 0 if no such element is found
    }else return 0;   //return 0 if no such element is found
}
};
Array2D Transpose(Array2D A){
    Array2D B;
    for (int i = 0; i <A.arr.size() ; ++i)
    {
        Array2D::node *ptr= A.arr[i];
        while (ptr!=nullptr)
        {
            B.insert(i,ptr->data,ptr->index);
            ptr = ptr->next;
        }
    }
    return B;
}
vector<vector<int>> MatrixMultiplication(vector<vector<int>> A,vector<vector<int>> B){
	vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < B[0].size(); j++){
            result[i][j]=0;
            for (int k = 0; k < B[0].size(); k++){
                result[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    return result;
}
Array2D InsertMatrix(vector<vector<int>> A){
    Array2D a;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if(A[i][j]!=0){
                a.insert(j,A[i][j],i);
            }
        }
    }
    return a;
}
Array2D Array2DMultiplication(Array2D A,Array2D B){
    Array2D res;
    for (int i = 0; i < A.arr.size(); i++) {
        Array2D::node* ptra = A.arr[i];
        while (ptra != nullptr) {
            Array2D::node* ptrb = B.arr[ptra->index];
            while (ptrb != nullptr) {
                if(res.Peek(i,ptrb->index)==0){
                    res.insert(ptrb->index, ptra->data * ptrb->data, i);
                }else{
                    Array2D::node * temp = res.arr[i];
                    while (temp!= nullptr && temp->index!=ptrb->index) temp = temp->next;
                    temp->data += ptra->data*ptrb->data;
                }
                ptrb = ptrb->next;
            }
            ptra = ptra->next;
        }
    }
    return res;
}
int main(){
    vector<vector<int>>A ={
        {0 , 0 , 0 , 0 , 9},         
        {0 , 8 , 0 , 0 , 0},         
        {4 , 0 , 0 , 2 , 0},         
        {0 , 0 , 0 , 0 , 0},         
        {0 , 0 , 2 , 0 , 0}     
    };
    vector<vector<int>>B ={
        {0 , 0 , 0 , 0 , 1},         
        {0 , 5 , 0 , 2 , 0},         
        {0 , 0 , 1 , 0 , 0},         
        {2 , 8 , 0 , 0 , 1},         
        {0 , 0 , 4 , 0 , 0}     
    };
    //4.1
    vector<vector<int>>C = MatrixMultiplication(A,B);
    cout << "The Resultant matrix is : \n";
    for(auto i: C){
        for(auto j: i)
        	cout << j << "\t ";
    	cout << endl;
    }
    // 4.2
    Array2D D = InsertMatrix(A);
    D.Print();
    // 4.3
    Array2D E = InsertMatrix(B);
    E.Print();
    Array2D result = Array2DMultiplication(D, E);
    result.Print();
    return 0;
}
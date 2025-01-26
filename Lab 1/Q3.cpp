#include <iostream>
using namespace std;
int calculateArea(int l,int w){
    return l*w;
}
int calculatePerimeter(int l,int w){
    return 2*(l+w);
}
int main()
{
    int l,w =-1;
    while (l<0 || w<0)
    {
        cout<<"Enter length of Rectangle:";
        cin>>l;
        cout<<"Enter width of Rectangle:";
        cin>>w;   
    }
    cout<<"Area:"<<calculateArea(l,w)<<endl;
    cout<<"Perimeter:"<<calculatePerimeter(l,w)<<endl;
    return 0;
}

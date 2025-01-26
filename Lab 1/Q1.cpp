#include <iostream>
using namespace std;
void EuclidFunc(int x,int y,int &Cd){
    int q = x/y;
    int r = x%y;
    if(r != 0){
        EuclidFunc(y,r,Cd);
    }else{
        Cd = y;
    }
}
int main()
{
    int a,b = -1;
    int gcd;
    while(a<0 || b<0){
        cout<<"Enter first value:";
        cin>>a;
        cout<< "Enter second value:";
        cin>>b;
    }
    if(a>b){
        EuclidFunc(a,b,gcd);
    }else{
        EuclidFunc(b,a,gcd);
    }
    cout<<"The Greatest common divisor of "<<a<<" and "<<b<<" is "<<gcd;
    return 0;
}
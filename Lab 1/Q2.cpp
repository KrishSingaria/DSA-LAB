#include <iostream>
using namespace std;

int generateFibonacci(int n,int* p){
    if(n == 0)
    {
        *p = 1;
        return *p;
    }else if (n==1)
    {
        *(p+1) = 1;
        return *(p+1);
    }else{
        *(p+n) = *(p+n-1) + *(p+n-2);
        return *(p+n);
    }
    
}
int main()
{
    int n = -1;
    int series[n];
    int* ptr = series;
    while (n<0){
        cout<<"Enter no of terms:";
        cin>>n;
    }
    for (int i = 0; i < n; i++)
    {
        series[i] = generateFibonacci(i,ptr);
        cout<<series[i]<<" ";
    }
    return 0;
}

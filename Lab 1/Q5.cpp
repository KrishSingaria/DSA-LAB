#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of days:";
    cin>>n;
    int years = n/365.25;
    int months = (n/365.25-years)*12;
    int days = n - years*365.25 - months*30.44;
    cout<<"No of Years:"<<years<<endl;
    cout<<"No of Month:"<<months<<endl;
    cout<<"No of Days:"<<days<<endl;
    if(years%4 == 0){
        cout<<"It\'s leap year";
    }else
    {
        cout<<"It\'s not leap year";
    }
    
    return 0;
}

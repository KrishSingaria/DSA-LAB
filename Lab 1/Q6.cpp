#include<iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter string:";
    cin>>str;
    string revStr;
    cout<<"Length of String:"<<str.length()<<endl;
    
    for (int i = str.length()-1; i>=0; i-=1)
    {
        revStr+=str[i];
    }
    cout<<revStr<<endl;
    if(str == revStr){
        cout<<"It\'s palindrome."<<endl;
    }else{
        cout<<"It\'s not palindrome."<<endl;
    }
    
    return 0;
}

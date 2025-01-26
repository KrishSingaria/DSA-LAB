#include <iostream>
using namespace std;
#include <vector>
vector<string> splitSentence(string str){
    vector<string> charArray;
    string word;
    int i = 0;
    while(i<str.length()){
        if(isblank(str[i]) == false){
            word+= str[i];
        }else{
            charArray.push_back(word);
            word ="";
        }
        i++;
    }
    charArray.push_back(word);
    return charArray;
}
int main()
{
    string line;
    cout<<"Enter your sentence:";
    getline(cin,line);
    vector<string> array = splitSentence(line);
    for (int i = 0; i < array.size(); i++)
    {
        cout<<array[i]<<endl;
    }
    return 0;
}


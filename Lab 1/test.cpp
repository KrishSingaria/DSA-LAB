#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1)
            return 1;
        vector<char> words;
        vector<int> counting;
        char curr;
        int currCounting=0;
        for(int i = 0;i<chars.size();i++){
            if(chars[i]==curr){
                currCounting++;
            }else{
                words.push_back(curr);
                counting.push_back(currCounting);
                curr = chars[i];
                currCounting = 1;
            }
        }
        words.push_back(curr);
        counting.push_back(currCounting);
        counting.erase(counting.begin());
        string result;
        for(int i = 0;i<words.size();i++){
            result+= words[i];
            if(counting[i]!=1){
                result+=to_string(counting[i]);
            }
        }
        
        // cout<<result<<"\n";
        cout<<chars.size()<<endl;
        for(int i = 0;i< result.size();i++){
            chars[i] = result[i];
        }
        return result.size();
    }
    void print(vector<char> List){
    for (int i = 0; i < List.size(); i++)
    {
        cout<<List[i];
    }
}
void print(vector<int> List){
    for (int i = 0; i < List.size(); i++)
    {
        cout<<List[i];
    }
}
};
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    solution.compress(chars);
    solution.print(chars);
    vector<char> p = {};
    cout<<"\n"<<p.size()<<endl;
    return 0;
}

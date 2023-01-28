#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<string> st;
    int ans=-1;
    void sol(int idx,string &s){

        if(idx>=s.size()) return;

        string temp="";

        for(int i=idx;i<s.size();i++){
            temp+=s[i];
            if(st.count(temp)==0){
                st.insert(temp);
                ans=max(ans,(int)st.size());
                sol(i+1,s);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        sol(0,s);
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.maxUniqueSplit("ababccc")<<" Hello";

}
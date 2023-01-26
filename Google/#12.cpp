#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    

    void sol(string temp,int i,string cur,string s){
        if(i==s.size()) {
            if(cur.empty() && count(temp.begin(),temp.end(),'.')==3)
            ans.push_back(temp);
        }
        cur+=s[i];
        if(stoi(cur)>255){
            return;
        }
        
        if(cur==""){
            sol(temp,i+1,cur+s[i],s);
        }
        if(!temp.empty()){
            sol(temp+'.'+cur,i+1,"",s);
        }else{
            sol(cur,i+1,"",s);
        }
        
    }

    vector<string> restoreIpAddresses(string s) {
        sol("",0,"",s);
        return ans;
    }
};
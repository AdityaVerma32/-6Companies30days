#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        set<string> st;
        int i=0;
        while(i+k<=n){
            string temp=s.substr(i,k);
            st.insert(temp);
            i++;
        }
        if(st.size()==(int)pow(2.0,(double)k))
        return true;
        else return false;
    }
};
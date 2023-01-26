#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int ans=0;
        map<char,int> mp;
        for(j=0;j<s.size();j++){
            mp[s[j]]++;
            while(mp['a']>0&&mp['b']>0&&mp['c']>0){
                mp[s[i++]]--;// increasing the index fromn right;
                ans+=(s.size()-j); // all the strings till end will be answer

            }
        }
        return ans;
    }
};
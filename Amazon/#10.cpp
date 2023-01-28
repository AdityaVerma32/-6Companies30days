#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
   
    bool is_subsequence(string str,string s){
        int i=str.size()-1;
        int j=s.size()-1;
        if(i<j) return false;

        while(i>=0 && j>=0){
            if(str[i]==s[j]){
                i--;
                j--;
            }else{
                i--;
            }
        }
        return j<0;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int count=0;
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            if(mp.count(words[i])) count+=mp[words[i]];
            else count+=mp[words[i]]=is_subsequence(s,words[i]);
        }    
        return count;
    }
};
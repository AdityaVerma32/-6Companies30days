#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int x,vector<vector<int>>& s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if((1<<i)&x){
                for(int j=0;j<n;j++){
                    if(( s[i][j]==0 and (x&(1<<j)) )  or (s[i][j]==1 and !(x&(1<<j)) )  ) return false;
                }
            }
        }
        return true;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n=statements.size();
        int ans=0;
        for(int i=0;i<(1<<n);i++){
            if(check(i,statements))
            ans=max(ans,__builtin_popcount(i));
        }

        return ans;
        
    }

};
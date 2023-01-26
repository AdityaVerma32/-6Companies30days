#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int> arr){
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<0) return false;
        }
        return true;
    }
    int sol(vector<int>& price, vector<vector<int>>& special, vector<int>& needs,map<vector<int>,int> &mp) {

        if(mp[needs]!=0) return mp[needs];
        
        int ans=0;
        for(int i=0;i<needs.size();i++){
            ans+=needs[i]*price[i];
        }

        for(auto sp:special){
            vector<int> need = needs;
            for(int i = 0; i < need.size(); i++){
                need[i] -= sp[i];
            }
            if(check(need)) ans=min(sp[needs.size()]+sol(price,special,need,mp),ans);
        }
        return mp[needs]=ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        map<vector<int>,int> mp;
        return sol(price,special,needs,mp);
    }
};
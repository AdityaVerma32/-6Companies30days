#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int,vector<int>> mp;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++){
            mp[cards[i]].push_back(i);
        }
        for(auto i:mp){
            vector<int> temp=i.second;
            if(temp.size()<2) continue;
            sort(temp.begin(),temp.end());
            for(int j=1;j<temp.size();j++){
                ans=min(ans,temp[j]-temp[j-1]+1);
            }
        }
        if(ans==INT_MAX) return -1;
        else return ans;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        map<int,int> already_taken;
        for(auto n:nums){
            if(mp[n]==0) continue;
            if(already_taken[n]>0){
                already_taken[n]--;
                mp[n]--;
                already_taken[n+1]++;
            }else if(mp[n]&&mp[n+1]&&mp[n+2]){
                mp[n]--;
                mp[n+1]--;
                mp[n+2]--;

                already_taken[n+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int target;
    
    bool sol(int i,int k,int cur_sum,vector<int>& nums,vector<bool>& check){

        if(k==1) return true;

        if(i>=nums.size()) return false;

        if(cur_sum==target) return sol(0,k-1,0,nums,check);

        for(int j=i;j<nums.size();j++){
            
            if(check[j] || (cur_sum+nums[j])>target) continue;
            check[j]=true;
            if(sol(j+1,k,cur_sum+nums[j],nums,check)) return true;
            check[j]=false;
            
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();

        target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0 || n<k) return false;
        target=target/k;
        vector<bool> check(n,false);
        return sol(0,k,0,nums,check);
    }
};
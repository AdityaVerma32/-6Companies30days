#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rvrs(int a){
        int t=0;
        while(a!=0){
            t=t*10+a%10;
            a=a/10;
        }
        return t;
    }

    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        int ans=0;
        map<int,int> temp;
        for(int i=0;i<nums.size();i++){
            int l=nums[i]-rvrs(nums[i]);
            
            if(temp.find(l)!=temp.end()){
                
                ans=(ans+temp[l])%mod;
           }
            temp[l]++;
        }

        
        
    return ans%mod;

    }

};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=-1;
        int maxi=nums[0];    
        for(int i=1;i<n;i++){
            if(maxi>nums[i])
            end=i;
            else
            maxi=nums[i];
        }
        int mini=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(mini<nums[i])
            st=i;
            else
            mini=nums[i];
        }
        return end-st+1;
    }
};
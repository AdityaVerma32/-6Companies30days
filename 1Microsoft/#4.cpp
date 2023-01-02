#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int temp=0;
        
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            temp+=(i*nums[i]);
        }
        int ans=temp;
        for(int i=n-1;i>=0;i--)
        {
            temp=temp+sum-nums[i]*n;
            ans=max(temp,ans);
        }
    return ans;
    }
};
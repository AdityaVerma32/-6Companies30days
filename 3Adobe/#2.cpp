#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>ans.back()){
                ans.push_back(nums[i]);
            }else{
                int pos=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[pos]=nums[i];
            }
        }
        return ans.size()>=3?true:false;
    }
};
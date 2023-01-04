#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums), end(nums));
        int temp = 0;
		
        vector<int> dp(n, 1), previous(n, -1);
        for(int i = 1; i < n; i++) {          
            for(int j = 0; j < i; j++)     
				
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1)
                    dp[i] = dp[j]+1, previous[i] = j;  
            if(dp[i] > dp[temp]) temp = i;      
        }

        vector<int> ans;
        for(; temp >= 0; temp = previous[temp]) 
            ans.push_back(nums[temp]);
        return ans;
    }
};
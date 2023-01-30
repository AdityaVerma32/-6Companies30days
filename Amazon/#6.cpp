#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod=1e9+7;
    #define lli long long int
    int maxSumMinProduct(vector<int>& nums) {
        lli n=nums.size();
        vector<lli> left(n);
        vector<lli> right(n);
        vector<lli> prefix(n+1);
        prefix[0]=0;

        for(lli i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+nums[i-1];
        }

        stack<lli> st1,st2;
        st1.push(n-1);
        right[n-1]=n;

        for(lli i=n-2;i>=0;i--){
            while(!st1.empty() && nums[st1.top()]>=nums[i]){
                st1.pop();
            }
            if(st1.empty())
                right[i]=n;
            else
                right[i]=st1.top();

            st1.push(i);
        }
        left[0]=-1;
        st2.push(0);
        for(lli i=1;i<n;i++){
            while(!st2.empty() && nums[st2.top()]>=nums[i])
                st2.pop();

            if(st2.empty())
                left[i]=-1;
            else
                left[i]=st2.top();
            st2.push(i);
        }

        lli ans=0;
        for(int i=0;i<n;i++){
            lli temp=(prefix[right[i]]-prefix[left[i]+1])*nums[i];
            ans=max(ans,temp);
        }

        return ans%mod;

    }
};
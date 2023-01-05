#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int l,int r,vector<int>& vi,int diff){
        if(l==r) return 0;

        int m=(l+r)/2;
        long long result=solve(l,m,vi,diff)+solve(m+1,r,vi,diff);

        int l1=l,r1=m,l2=m+1,r2=r;

        vector<long long> changed;
        for(int i=l2;i<=r2;i++){
            int act_diff=vi[i]+diff;
            int ind=upper_bound(vi.begin()+l1,vi.begin()+r1+1,act_diff)-vi.begin()-1;
            if(ind<=r1)
            result+=ind-l1+1;
        }

        while(l1<=r1&&l2<=r2){
            if(vi[l1]<=vi[l2])
            changed.push_back(vi[l1++]);
            else
            changed.push_back(vi[l2++]);
        }
        while(l1<=r1) changed.push_back(vi[l1++]);
        while(l2<=r2) changed.push_back(vi[l2++]);

        for(int i=l;i<=r;i++){
            vi[i]=changed[i-l];
        }

        return result;

    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n=nums1.size();
        vector<int> vi(n);
        for(int i=0;i<n;i++){
            vi[i]=nums1[i]-nums2[i];
        } 
        return solve(0,n-1,vi,diff);
        
    }
};
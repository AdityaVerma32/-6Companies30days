#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int findGCD(vector<int> nums){
        int n=nums.size();
        int temp=nums[0];
        for(int i=1;i<n;i++){
            temp=__gcd(nums[i],temp);
        }
        return temp;
        
    }
    // int findHCF(vector<int> nums){
    //     int n=nums.size();
    //     queue<int> q;
    //     for(int i=0;i<n;i++){
    //         q.push(nums[i]);
    //     }
    //     while(q.size()>1){
    //         int a=q.front();q.pop();
    //         int b=q.front();q.pop();
    //         int temp=(a*b)/__gcd(a,b);

    //     }
    //     return q.front();

    // }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        //int HCF=findHCF(numsDivide);
        int GCD=findGCD(numsDivide);
        for(auto i:mp){
            if(GCD%i.first==0)
            break;
            else
            n-=i.second;
        }
        if(n==0) return -1;
        else return nums.size()-n;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int i=0;
        int j=0;
        int ans=0;
        int n=arr.size();
        map<int,int> mp;
        while(j<n){
            mp[arr[j]]++;
            if(mp.size()<=2){
                ans=max(ans,j-i+1);
                j++;
            }else{
                mp[arr[i]]--;
                if(mp[arr[i]]<=0)
                mp.erase(arr[i]);
                i++;
                j++;
            }
        }
        return ans;
    }
};
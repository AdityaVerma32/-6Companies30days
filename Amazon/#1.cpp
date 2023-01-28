#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> org;
    Solution(vector<int>& nums) {
        org=nums;
    }
    
    vector<int> reset() {
        return org;
    }
    
    vector<int> shuffle() {
        vector<int> temp=org;
        for(int i=0;i<org.size();i++){
            int k=rand()%org.size();
            swap(temp[i],temp[k]);
        }
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
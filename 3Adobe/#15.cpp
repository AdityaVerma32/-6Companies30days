#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){

            int trim=queries[i][1];
            int k=queries[i][0];

            vector<pair<string,int>> pq;
            for(int j=0;j<nums.size();j++){

                string val=nums[j];
                if(trim<nums[j].size()) val=nums[j].substr(nums[j].size()-trim,trim);
                pair<string,int> temp={val,j};

                pq.push_back(temp);
            }
            sort(pq.begin(),pq.end());
            ans.push_back(pq[k-1].second);

        }
        return ans;
    }
};




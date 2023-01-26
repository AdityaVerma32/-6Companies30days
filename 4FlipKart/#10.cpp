#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int,int> mp;
        for(int i=0;i<barcodes.size();i++){
            mp[barcodes[i]]++;
        }
        vector<int> ans;

        priority_queue<pair<int,int>> pq;

        for(auto i:mp){
            pq.push({i.second,i.first});
        }

        while(pq.top().first>0){
            pair<int,int> p1=pq.top();
            pq.pop();

            ans.push_back(p1.second);
            p1.first--;

            pair<int,int> p2=pq.top();
            pq.pop();

            ans.push_back(p2.second);
            p2.first--;

            if(p1.first>0)
            pq.push(p1);
            if(p2.first>0)
            pq.push(p2);

        }

        return ans;

    }
};
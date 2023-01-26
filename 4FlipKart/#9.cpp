#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct compare{
        bool operator ()(pair<int,string> &a,pair<int,string> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(auto w:words){
            mp[w]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;

        for(auto &i:mp){

            pq.push({i.second,i.first});
            if(pq.size()>k){
                pq.pop();
            }

        }

        
        vector<string> temp;
        while(k>0){
            temp.push_back(pq.top().second);
            k--;
            pq.pop();
        }
        return temp;
    }
};
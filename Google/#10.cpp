#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto &i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; 

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int cur_dis=pq.top().first;
            int cur_node=pq.top().second;

            pq.pop();
            
            for(pair<int,int> it:adj[cur_node]){
                int adjNode=it.first;
                int weight=it.second;
                if(dist[adjNode]>(cur_dis+weight)){
                    dist[adjNode]=(cur_dis+weight);
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        sort(dist.begin(),dist.end());
        if(dist[n-1]==INT_MAX) return -1;
        else return dist[n-1];
    }
};
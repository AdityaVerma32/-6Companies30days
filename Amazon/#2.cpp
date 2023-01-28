#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int l) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        l++;
        queue<pair<int,int>> q;
        vector<int> ans(n,INT_MAX);
        q.push({src,0});


        while(!q.empty() && l){

            int k=q.size();
            for(int i=0;i<k;i++){
                auto cur=q.front();

                int node=cur.first;
                int dis=cur.second;

                q.pop();
                for(auto &adjacent:adj[node]){
                    int cur_node=adjacent.first;
                    int price=adjacent.second;
                    if(dis+price<ans[cur_node]){
                        ans[cur_node]=dis+price;
                        q.push({cur_node,ans[cur_node]});
                    }
                }
            }
            l--;
            
        }

        if(ans[dst]==INT_MAX) return -1;
        else return ans[dst];
    }
};
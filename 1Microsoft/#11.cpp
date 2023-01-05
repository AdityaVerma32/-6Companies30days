#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define ll long long
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll, ll>> adj[n];
        for (auto i : roads)
        {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll,ll>>> pq;

        int mod = (1e9 + 7);
        vector<ll> dis(n, LONG_MAX);
        vector<ll> ways(n, 0);
        pq.push({0, 0});

        dis[0] = 0;
        ways[0] = 1;
        while (!pq.empty())
        {
            ll node = pq.top().second;
            ll cur_dis = pq.top().first;

            pq.pop();
            
            for (auto it : adj[node])
            {
                ll adjNode=it.first;

                if (cur_dis + it.second < dis[adjNode])
                {
                    // changing the  distance
                    dis[adjNode] = cur_dis + it.second ;
                    // ways was initially 0
                    ways[adjNode] = ways[node];
                    // push the node into queue
                    pq.push({ cur_dis + it.second,adjNode});
                }
                else if ((cur_dis + it.second)== dis[adjNode])
                {
                    // it is already in queue so only change the number of ways
                    ways[adjNode] = (ways[adjNode]  + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};
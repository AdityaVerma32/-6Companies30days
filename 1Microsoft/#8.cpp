#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> dis;
    vector<vector<int>> adj;



    void calParent(int root,int curParent=0,int curDis=0){
        dis[root]=curDis;
        parent[root]=curParent;
        for(int i: adj[root]){
            if(i==curParent) continue;
            
            
            calParent(i,root,curDis+1);
        }

    }

    int dfs(int curr,vector<int> &amt,int temp=0 ){
        int curr_cost=amt[curr];
        int ans=-INT_MAX;
        for(int i: adj[curr])
        {
            //this condition taking care that no node is connected to root 
            if(i!=temp) ans=max(ans,dfs(i,amt,curr));
        }
        if(ans==-INT_MAX)
        return curr_cost;
        else return curr_cost+ans;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int edges_count=edges.size();
        adj.resize(edges_count+1,vector<int>());
        for(auto &i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        parent.resize(edges_count+1);
        dis.resize(edges_count+1);

        calParent(0);

        int cur=bob;
        int curDis=0;
        while(cur!=0){
            if(dis[cur]>curDis)
            amount[cur]=0;
            else if(dis[cur]==curDis)
            amount[cur]/=2;
            cur=parent[cur];
            curDis++;
        }
        return dfs(0,amount);
        
    }
};
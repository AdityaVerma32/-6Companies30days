#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool checkCycle(int i,vector<int> adj[],vector<int>& vis,vector<int>& dfs)
    {
        vis[i]=1;
        dfs[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(checkCycle(it,adj,vis,dfs)) return true;
            }
            else if(dfs[it]==1)
            return true;
        }
        dfs[i]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses,0),dfs(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfs)) return false; 
            }
        }
        return true;
    }
};
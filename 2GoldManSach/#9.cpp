#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        priority_queue<int> pq;
        vector<pair<int,int>> vi;
        for(int i=0;i<n;i++){
            vi.push_back({capital[i],profits[i]});
        }

        sort(vi.begin(),vi.end());
        int i=0;
        while(i<vi.size()&&k){
                if(w>=vi[i].first){
                    pq.push(vi[i].second);
                    i++;
                }else{
                    if(pq.empty())
                    return w;
                    else{
                        w+=pq.top();
                        pq.pop();
                        k--;
                    }
                }
        }
        while(k--&&!pq.empty()){
            w+=pq.top();
            pq.pop();
        }        
        return w;
    }
};
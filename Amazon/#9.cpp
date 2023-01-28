#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define lli long long int
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n=creators.size();
        map<string,long long int> mp;
        map<string,vector<pair<string,lli>>> temp;
        lli maxi=0;

        for(int i=0;i<n;i++){
            mp[creators[i]]+=views[i];
            if(mp[creators[i]]>maxi)  maxi=mp[creators[i]];
            temp[creators[i]].push_back({ids[i],views[i]});
        }

        vector<vector<string>> ans;
        for(auto &it:mp){
            if(it.second==maxi){

                vector<string> a;
                string id=temp[it.first][0].first;
                lli v=temp[it.first][0].second;
                for(auto k:temp[it.first]){

                    if(v<k.second){
                        v=k.second;
                        id=k.first;
                    }else if(k.second==v && id>k.first){
                        id=k.first;
                    }

                }
                a.push_back(it.first);
                a.push_back(id);
                ans.push_back(a);                               

            }
        }

        return ans;

        
        
    }
};
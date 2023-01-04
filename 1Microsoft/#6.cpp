#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(int i=0;i<rectangles.size();i++)
        {
            mp[{rectangles[i][0],rectangles[i][1]}]++;
            mp[{rectangles[i][2],rectangles[i][3]}]++;
            mp[{rectangles[i][0],rectangles[i][3]}]--;
            mp[{rectangles[i][2],rectangles[i][1]}]--;
        }
        int ans=0;
        for(auto i=mp.begin();i!=mp.end();i++)
        {
            //only this part would have worked if overlapping was aloud
            if(abs(i->second)==1)
            ans++;
            //if some part overlaps then its vaue not be 0 or 1 or -1 and in that case we will return false
            if(i->second!=0&&abs(i->second)!=1)
            return false;
        }
        return ans==4;
    }
};
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans=0;
        for(int i=1;i<special.size();i++){
            ans=max(special[i]-special[i-1]-1,ans);
        }
        ans=max(ans,special[0]-bottom);
        ans=max(ans,top-special[special.size()-1]);

        return ans;
    }

};
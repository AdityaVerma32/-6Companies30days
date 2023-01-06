#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<2) return n;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){

                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int count=2;

                for(int k=j+1;k<n;k++){

                    int x3=points[k][0];
                    int y3=points[k][1];
                    if((x2-x1)*(y3-y1)==(x3-x1)*(y2-y1))
                    count++;
                }
                ans=max(ans,count);
            }
        }
        return ans;
    }

};
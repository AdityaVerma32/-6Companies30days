#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// double Dis(vector<int> p1,vector<int> p2){
//         double a=pow(((double)p2[1]-(double)p1[1]),2.0);
//         double b=pow(((double)p2[0]-(double)p1[0]),2.0);

//         return sqrt(a+b);

//     }
    double Dis(vector<int> p1,vector<int> p2){
        int x1=p1[0];
        int y1=p1[1];
        int x2=p2[0];
        int y2=p2[1];

        return pow((x2-x1),2)+pow((y2-y1),2);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int count=0;

        for(int i=0;i<n;i++){
            map<int,int> mp;
            for(int j=0;j<n;j++)
            {
                int d=Dis(points[i],points[j]);
                mp[d]++;
            }
            for(auto it:mp){
            if(it.second)count+=(it.second*(it.second-1));}
        }
        return count;
    }
};
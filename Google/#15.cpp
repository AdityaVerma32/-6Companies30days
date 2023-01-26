#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int check(vector<int> a,vector<int> b){
        int ans=0;
        int i=0;
        while(i<a.size())
        {
            ans+=a[i]==b[i];
            i++;
        }

        return ans;
    }

    int sol(int ind,vector<bool> mt_check,vector<vector<int>>& students, vector<vector<int>>& mentors){

        int ans=0;

        for(int j=0;j<mentors.size();j++){
            int temp=0;
            if(mt_check[j]==true){
                mt_check[j]=false;
                temp=check(students[ind],mentors[j])+sol(ind+1,mt_check,students,mentors);
                mt_check[j]=true;
            }
            ans=max(temp,ans);
        }

        return ans;
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n=mentors.size();
        
        vector<bool> mt_check(n,true);
        
        return sol(0,mt_check,students,mentors);

    }
};
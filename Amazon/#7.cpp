#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int> rq,dq;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') rq.push(i);
            if(senate[i]=='D') dq.push(i);
        }

        while(!rq.empty() && !dq.empty()){
            int r=rq.front();
            int d=dq.front();
            rq.pop();
            dq.pop();

            if(r<d) rq.push(r+n);
            else dq.push(d+n);
        }

        if(rq.empty()) return "Dire";
        else return "Radiant";
    }
};
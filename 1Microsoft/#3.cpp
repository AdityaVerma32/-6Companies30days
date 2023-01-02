#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int a=0;
        int b=0;
        map<int,int> s,g;     
        for(int i=0;i<guess.size();i++)
        {
            if(guess[i]==secret[i])
            a++;
            else{
                s[secret[i]]++;
                g[guess[i]]++;
            }
        }
        for(auto it:s)
        {
            if(g.find(it.first)!=g.end()){
                // if(it.second<g[it.first])
                // b+=it.second;
                // else
                // b+=g[it.second];
                b+=min(it.second,g[it.first]);
            }
        }
        string str=to_string(a)+"A"+to_string(b)+"B";
        return str;

    }
};
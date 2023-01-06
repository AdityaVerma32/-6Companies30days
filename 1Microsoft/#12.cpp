#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        long long n=s.size();
        string str="";
        long long ans=0;
        if(n==1)
        {
            return str;
        }

        long long p=31;
        long long mod=100000007;
        long long pow=1;

        long long ph=0;
        long long sh=0;

        for(int i=0;i<n-1;i++)
        {
            ph=((ph*p)+(s[i]-'a'+1))%mod;
            sh=(sh+((s[n-1-i]-'a'+1)*pow)%mod)%mod;

            pow=(pow*p)%mod;
            if(ph==sh) ans=i+1;
        }
        return s.substr(0,ans);

    }
};
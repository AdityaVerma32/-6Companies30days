#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        long long n=text.size();
        vector<long long> hash(n+1,0),p_pow(n,1);
        long long p=31;
        long long mod=1e9+9;

        for(int i=1;i<n;i++){
            p_pow[i]=(p_pow[i-1]*p)%mod;
        }

        for(int i=0;i<n;i++){
            hash[i+1]=(hash[i]+(text[i]-'a'+1)*p_pow[i])%mod;
        }

        map<long long,int> mp;

        for(long long l=2;l<=n;l+=2){
            for(long long i=0;i+l<=n;i++){
                long long cur1=(hash[i+l/2]-hash[i]+mod)%mod;
                cur1=(cur1*p_pow[n-i-1])%mod;
                long long cur2=(hash[i+l]-hash[i+l/2]+mod)%mod;
                cur2=(cur2*p_pow[n-i-1-l/2])%mod;
                if(cur1==cur2)
                mp[cur1]++;
            }
        }

        return mp.size();
    }
};
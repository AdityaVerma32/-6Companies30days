#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        
        string ans="";

        if((numerator<0&&denominator>0)||(numerator>0&&denominator<0))
            ans+="-";

        long long q=abs(numerator)/abs(denominator);
        long long r=abs(numerator)%abs(denominator);

        
        ans+=to_string(q);

        if(r==0) return ans;

        ans+=".";

        map<long long,int> mp;

        while(r!=0){
            if(mp.find(r)!=mp.end()){
                long long pos=mp[r];
                ans.insert(pos,"(");
                ans+=")";
                return ans;
            }else{
                mp[r]=ans.length();
                r=r*10;
                q=r/abs(denominator);
                r=r%abs(denominator);
                ans+=to_string(q);
            }
        }
        return ans;
    }
};
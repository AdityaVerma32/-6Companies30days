#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bi_to_int(int n){
        int ans=0;
        for(int i=0;i<32;i++){
            int a=n%10;
            n/=10;
            ans+=((int)pow(2.0,(double)i)*a);
            n/=10;
        }
        return ans;
    }
    int sol(int i,int n,int times){
        if(times>=32)
        return 0;

        int zero=0;
        int one=1;

        if(bi_to_int(i*10)<=n)
        zero=sol(i*10,n,times+1)+1;
        if(i%10!=1&&bi_to_int(i*10+1)<=n){
            one=sol(i*10+1,n,times+1)+1;
        }
        return zero+one;
    }
    int findIntegers(int n) {
        return sol(0,n,0);
    }
};
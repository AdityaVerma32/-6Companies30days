#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(int i,int n){
        if(i>n) return 0;

        if(i&1){
            return 1+sol(i<<1,n);
        }else{
            return 1+sol(i<<1,n)+sol(i<<1|1,n);
        }
    }
    int findIntegers(int n) {
        return 1+sol(1,n);
    }
};
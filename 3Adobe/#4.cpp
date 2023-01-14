#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string str="122";
        int i=2;
        int j=2;
        while(str.size()<n){
            if(str[i]=='2'){
                if(str[j]=='1'){
                    str+="22";
                }else{
                    str+="11";
                }
            }else{
                if(str[j]=='1'){
                    str+='2';
                }else{
                    str+='1';
                }
            }

            i++;
            j=str.size()-1;
        }

        int count=0;
        for(int k=0;k<n;k++){
            if(str[k]=='1')
            count++;
        }
        return count;
    }
};
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        int n=transactions.size();
        vector<string> name;
        vector<int> time;
        vector<int> amt;
        vector<string> city;
        for(int i=0;i<n;i++){
            int m=transactions[i].size();
            string curr_name="";
            int j=0;
            while(transactions[i][j]!=','){
                curr_name+=transactions[i][j++];
            }
            name.push_back(curr_name);
            j++;
            int curr_time=0;
            while(transactions[i][j]!=','){
                curr_time=curr_time*10+(transactions[i][j++]-48);
            }
            time.push_back(curr_time);
            int curr_amt=0;
            j++;
            while(transactions[i][j]!=','){
                curr_amt=curr_amt*10+(transactions[i][j++]-48);
            }
            amt.push_back(curr_amt);
            string curr_city="";
            j++;
            while(j!=m){
                curr_city+=transactions[i][j++];
            }
            city.push_back(curr_city);
        }
        vector<int> temp(n,0); 
        vector<string> ans;
        for(int i=0;i<n;i++){
            if(amt[i]>=1000){

            temp[i]=1;
            }
            for(int j=i+1;j<n;j++){

                if( name[j]==name[i] && abs(time[j]-time[i])<=60 && city[i]!=city[j] ){
                    temp[j]=1;
                temp[i]=1;
                }
                
            }
        }
       for(int i=0;i<n;i++){
           if(temp[i]){
               ans.push_back(transactions[i]);
           }
       }
       return ans;
    }
};
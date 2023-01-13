#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m;
    int n;
    bool validity(int x,int y){
        if(x<0||x>=m||y<0||y>=n)
            return false;
        return true;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        m=grid.size();
        n=grid[0].size();


        set<int> st;
        vector<vector<int>> left_sum(m,vector<int>(n,0));
        vector<vector<int>> right_sum(m,vector<int>(n,0));


        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                left_sum[i][j]=grid[i][j];
                right_sum[i][j]=grid[i][j];
                if(validity(i-1,j-1))
                    left_sum[i][j]+=left_sum[i-1][j-1];
                if(validity(i-1,j+1))
                    right_sum[i][j]+=right_sum[i-1][j+1];
            }
        }

        int ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                st.insert(grid[i][j]);

                for(int k=1;k<=50;k++){
                    
                    if(validity(i+k,j-k)&&validity(i+k,j+k)&&validity(i+2*k,j)){
                        ans=(grid[i][j]+grid[i+k][j-k]+grid[i+k][j+k]+grid[i+2*k][j]);

                        ans-=(grid[i][j]+grid[i+k][j-k]);   //           /
                        ans+=right_sum[i+k][j-k];           //          /  
                        if(validity(i-1,j+1)){              //         /
                            ans-=right_sum[i-1][j+1];       //        /
                        }                                   //       /

                        ans-=(grid[i][j]+grid[i+k][j+k]);     
                        ans+=left_sum[i+k][j+k];           
                        if(validity(i-1,j-1)){              
                            ans-=left_sum[i-1][j-1];      
                        }                                       

                        ans-=(grid[i+2*k][j]+grid[i+k][j-k]);   
                        ans+=right_sum[i+2*k][j];           
                        if(validity(i+k-1,j+k+1)){              
                            ans-=right_sum[i+k-1][j+k+1];       
                        }                                   

                        ans-=(grid[i+2*k][j]+grid[i+k][j+k]);   
                        ans+=left_sum[i+2*k][j];          
                        if(validity(i+k-1,j-k-1)){          
                            ans-=left_sum[i+k-1][j-k-1];      
                        }                                  

                    st.insert(ans);
                    }

                }
            }
        }

        vector<int> temp;
        for(auto i:st){
            temp.push_back(i);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        if(temp.size()<3){
            return temp;
        }
        else
        return {temp[0],temp[1],temp[2]};

    }
};
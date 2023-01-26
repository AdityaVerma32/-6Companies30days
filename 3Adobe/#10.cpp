


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long n=matrix.size();
        long long minEle=LLONG_MAX;
        long long sum=0;
        long long negCount=0;
        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){

                sum+=abs(matrix[i][j]);
                if(minEle>abs(matrix[i][j]))
                minEle=abs(matrix[i][j]);
                

                if(matrix[i][j]<0)
                    negCount++;
            }
        }
        if(negCount%2==0) return sum;
        else return sum-2*minEle;
    }
};
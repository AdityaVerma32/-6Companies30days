#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void merge(int i,int m,int j,vector<int>& nums){
        int l=i;
        int r=m+1;
        int k=0;
        
        vector<int> temp;

        while(l<=m && r<=j){
            if(nums[l]<=nums[r]){
                temp.push_back(nums[l++]);
            }else{
                temp.push_back(nums[r++]);
            }
        }

        while(l<=m){
            temp.push_back(nums[l++]);
        }

        while(r<=j){
            temp.push_back(nums[r++]);
        }

        k=temp.size();
        int b=0;
        while(b<k){
            nums[i++]=temp[b++];
        }
}

    void mergeSort(int i,int j,vector<int> &nums){
        if(i<j){
            int mid=(i+j)/2;
            mergeSort(i,mid,nums);
            mergeSort(mid+1,j,nums);

            merge(i,mid,j,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};
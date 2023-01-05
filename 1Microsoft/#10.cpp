#include<bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findUnsortedSubarray(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> temp(n);
//         temp=nums;
//         sort(temp.begin(),temp.end());
//         int i=0;
//         while(temp[i]==nums[i]&&i<n){
//             i++;
//         }
//         int j=n-1;
//         while(nums[j]==temp[j]&&j>=0){
//             j--;
//         }
//         if(i<j)
//         return j-i+1;
//         else return 0;
//     }
// };

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int st=0,end=-1;
        int maxi=nums[0];    
        for(int i=1;i<n;i++){
            if(maxi>nums[i])
            end=i;
            else
            maxi=nums[i];
        }
        int mini=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(mini<nums[i])
            st=i;
            else
            mini=nums[i];
        }
        return end-st+1;
    }
};

int main()
{
    cout<<"Hello World";
    // vector<int> app={2,6,4,8,10,9,15};
    // Solution s;
    // cout<<"Aanswer : "<<s.findUnsortedSubarray(app);
}
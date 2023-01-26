#include<bits/stdc++.h>
using namespace std;

class MountainArray {
   public:
     int get(int index);
     int length();
 };


class Solution {
public:
    int findInMountainArray(int target, MountainArray &mr) {
        int st=0;
        int end=mr.length()-1;
        int mid;
        while(st<end){
            mid=st+(end-st)/2;

            if(mr.get(mid)<mr.get(mid+1)){
                st=mid+1;
            }else if(mr.get(mid)>mr.get(mid+1)){
                end=mid;
            }

        }
        int l=mid;
        int r=mr.length()-1;
        //end=st;
        st=0;
        while(st<=end){
            mid=st+(end-st)/2;
            if(mr.get(mid)==target)
                return mid;
            else if(mr.get(mid)>target){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        while(l<=r){
            mid=l+(r-l)/2;
            
            if(mr.get(mid)<target){
                r=mid-1;
            }else if(mr.get(mid)>target){
                l=mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
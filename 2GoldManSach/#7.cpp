
#include<stdio.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<ll, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  

#define ll long long

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n=nums1.size();
        vector<ll> pos(n);
        for(ll i=0;i<n;i++){
            //storing the position of each element in nums array
            pos[nums2[i]]=i;
        }

        ordered_set s;
        vector<ll> pre(n),suf(n);
        for(ll i=0;i<n;i++){
            ll position_of_nums1i_in_nums2=pos[nums1[i]];

            pre[i]=s.order_of_key(position_of_nums1i_in_nums2);

            s.insert(position_of_nums1i_in_nums2);

        }

        s.clear();

        for(ll i=n-1;i>=0;i--){
            ll position_of_nums1i_in_nums2=pos[nums1[i]];

            suf[i]=s.size()-s.order_of_key(position_of_nums1i_in_nums2);

            s.insert(position_of_nums1i_in_nums2);

        }

        ll ans=0;
        for(ll i=1;i<n-1;i++){
            ans+=pre[i]*suf[i];
        }
        return ans;
    }
};
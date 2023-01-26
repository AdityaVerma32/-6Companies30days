#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        int n = s.size();
        map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        int m = order.size();
        string ans = "";
        for (int i = 0; i < m; i++)
        {
            if (mp.find(order[i]) != mp.end())
            {
                int k = mp[order[i]];
                while (k > 0)
                {
                    ans += order[i];
                    k--;
                }
                mp.erase(order[i]);
            }
        }
        for (auto c : mp)
        {
            int k = c.second;
            while (k > 0)
            {
                ans += c.first;
                k--;
            }
        }
        return ans;
    }
};
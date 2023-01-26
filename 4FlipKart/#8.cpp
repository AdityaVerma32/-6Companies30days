#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> dp;
    vector<int> primes;
    void sieve()
    {
        for (int i = 0; i * i <= 1e6; i++)
        {
            if (dp[i] == true)
            {
                for (int j = i * i; j <= 10e6; j += i)
                    dp[j] = false;
            }
        }
        
    }
    vector<int> closestPrimes(int left, int right)
    {
        dp.resize(10e6 + 1, true);
        sieve();
        vector<int> temp;

        for (int i = left; i <= right; i++)
        {
            if (dp[i] == true)
                primes.push_back(i);
        }


        int l = -1;
        int r = -1;

        for (int i=1;i<primes.size(); i++)
        {
            if (l == -1 || primes[i] - primes[i-1] < r - l)
            {
                l = primes[i];
                r = primes[i + 1];
            }
        }
        return {l,r};
    }
};
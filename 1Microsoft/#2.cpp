#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solution(int i, int n, int k, vector<vector<int>> &ans, vector<int> temp)
    {
        if (n == 0 && temp.size() == k)
        {
            ans.push_back(temp);
        }
        if (i == 10 || n < i)
            return;
        
        solution(i + 1, n, k, ans, temp);
        temp.push_back(i);
        solution(i + 1, n - i, k, ans, temp);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        // vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> ans;
        vector<int> temp;
        solution(1, n, k, ans, temp);
        return ans;
    }
};
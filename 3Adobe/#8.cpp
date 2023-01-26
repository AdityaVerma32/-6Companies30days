#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        queue<string> q;
        set<string> st;

        int count = 0;

        q.push(startGene);
        st.insert(startGene);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                string node = q.front();
                q.pop();
                if (node == endGene)
                {
                    return count;
                }

                for (char k : "ACGT")
                {
                    for (int j = 0; j < node.size(); j++)
                    {
                        string temp = node;
                        temp[j] = k;
                        if (!st.count(temp) && find(bank.begin(), bank.end(), temp) != bank.end())
                        {
                            q.push(temp);
                            st.insert(temp);
                        }
                    }
                }
            }
            count++;
        }
        return -1;
    }
};
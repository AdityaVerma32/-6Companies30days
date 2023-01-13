#include<bits/stdc++.h>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void dfs(TreeNode* root1,vector<int> &ans){
        if(root1==NULL)
        return ;
        dfs(root1->left,ans);
        ans.push_back(root1->val);
        dfs(root1->right,ans);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1,ans);
        dfs(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }

};
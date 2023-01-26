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
    void sol(TreeNode* root,int &n,int &sum){
        if(root==NULL) return;
        sol(root->left,n,sum);
        sol(root->right,n,sum);
        sum+=root->val;
        n++;
    }
    void answer(TreeNode* root,int &ans){
        if(root==NULL) return ;
        
        answer(root->left,ans);
        answer(root->right,ans);

        int n=0;
        int sum=0;
        sol(root,n,sum);
        if(sum/n==root->val) ans++;
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        answer(root,ans);
        return ans;
    }
};
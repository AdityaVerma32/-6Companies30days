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

    map<TreeNode*,int> mp;
    // int sol(TreeNode* root,bool check){

    //     if(root==NULL) return 0;

    //     if(mp.find(root)!= mp.end()) return mp[root];
    //     int take=INT_MIN;
    //     int not_take=INT_MIN;


    //     if(check==false){
    //         take=root->val+sol(root->left,true)+sol(root->right,true);
    //     }
    //     not_take=sol(root->left,false)+sol(root->right,false);

    //     return mp[root]=max(take,not_take);

    // }

    int rob(TreeNode* root) {
        
        // int take=sol(root,false);
        // int not_take=sol(root->left,false)+sol(root->right,false);

        // return max(take,not_take);

        if(root==NULL) return 0;

        if(mp.find(root)!=mp.end()) return mp[root];

        int a=0,b=0,c=0,d=0;

        if(root->left){
            a=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            b=rob(root->right->left)+rob(root->right->right);
        }
        c=rob(root->left)+rob(root->right);

        return mp[root]=max(root->val+a+b,c);

    }
};
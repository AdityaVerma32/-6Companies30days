#include<bits/stdc++.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
 
class Solution {
public:
    
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *root=new ListNode(0);

        root->next=head;
        
        unordered_map<int,ListNode*> mp;
        int sum=0;
        mp[0]=root;
        
        
        while(head!=NULL){
            sum+=head->val;

            if(mp.find(sum)!=mp.end()){
                ListNode *temp=mp[sum];
                ListNode *lol=temp;

                int nxt_sum=sum;
                while(temp!=head){
                    temp=temp->next;
                    nxt_sum+=temp->val;
                    if(temp!=head)
                    mp.erase(nxt_sum);
                }

                lol->next=head->next;
            }else{
                mp[sum]=head;
            }

            head=head->next;
        }

        return root->next;


    }
};
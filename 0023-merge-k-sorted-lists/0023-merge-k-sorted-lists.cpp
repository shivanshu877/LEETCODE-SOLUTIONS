/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans ;
        for( int i = 0  ; i< lists.size() ; i++){
  while(lists[i]){
      ans.push_back(lists[i]->val);
      lists[i] =  lists[i]->next;
  }
        }
     sort(ans.begin() , ans.end());
    ListNode* ne  = new  ListNode(0);
    ListNode* anss  =   ne;
    for(auto x : ans){
    ListNode* n  = new  ListNode(x);        
        ne->next = n ;
        ne =  ne->next; 
    } 
   return anss->next;
   }
};
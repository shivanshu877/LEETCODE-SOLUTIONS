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
    ListNode* swapPairs(ListNode* head) {
        vector<int> values ;
        while(head!= nullptr){
                 values.push_back(head->val);
                 head = head->next;
        }
        for(int i =0 ; i<static_cast<int>(values.size()-1) ; i+=2){
            swap(values[i],values[i+1]);
        }
          ListNode *newList =  new ListNode() ;
        auto node = newList;
        for(auto x : values){
               
        node->next = new ListNode(x);
                node = node->next;

        }
        return newList->next;
    }
};
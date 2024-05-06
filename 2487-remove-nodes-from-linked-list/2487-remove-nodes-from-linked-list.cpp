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
    ListNode* removeNodes(ListNode* head) {
       
       
        if(!head) return nullptr  ;
        stack<ListNode*> st ;
        while(head){
            int t = head->val;
            while(!st.empty()  && st.top()->val < t )st.pop();
            st.push(head);
            head = head->next;
        }
        if(st.empty())return nullptr;
       ListNode * temp = st.top();
       st.pop();
       ListNode * temp1 =  temp; 
        while(!st.empty()){
            temp->next = st.top();
            temp = temp->next ;
            st.pop();
        }
        temp->next =  nullptr;
        ListNode * prev = nullptr ;
        ListNode * curr  = temp1;
        while(curr){
          auto nxt =  curr->next ;
          curr->next = prev;
            prev = curr;
            curr = nxt ;
        }
        return prev;
    }
};
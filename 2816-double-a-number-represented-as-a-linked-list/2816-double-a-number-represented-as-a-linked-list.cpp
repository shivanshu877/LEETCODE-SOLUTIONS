class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
      auto it = head;
        ListNode*  prev = nullptr;
      while(it) {
          auto temp =  it->next ;
          it->next =  prev; 
          prev = it ;
          it = temp;
      }
      auto t = prev; 
       int carry = 0 ;
        while(prev) {
          auto v  = ( prev->val * 2  +  (carry )) %10  ;
            carry = ( prev->val * 2  +  (carry ))  / 10 ;
          prev->val = v ;
        if( prev->next == nullptr) {
             if(carry){
            ListNode* n = new ListNode(carry);   
               n->next =  nullptr;
                 prev->next =  n;
             }
         break;    
        }
            prev= prev->next ;
      }
            ListNode*  prev2 = nullptr;
      while(t) {
          auto temp =  t->next ;
          t->next =  prev2; 
          prev2 = t ;
          t = temp;
      }
       return prev2 ;
        
    }
};
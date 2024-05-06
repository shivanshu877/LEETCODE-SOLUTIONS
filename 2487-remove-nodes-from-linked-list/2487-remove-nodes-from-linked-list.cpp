class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (!head)
            return nullptr;

        stack<ListNode*> st;
        ListNode* curr = head;
        ListNode* nextNode;

        // Traverse the list
        while (curr) {
            nextNode = curr->next; // Store the next node before modifying the current node
            curr->next = nullptr; // Disconnect the current node from the rest of the list

            // Remove nodes with smaller values from the stack
            while (!st.empty() && st.top()->val < curr->val) {
                st.pop();
            }

            st.push(curr); // Push the current node onto the stack

            curr = nextNode; // Move to the next node
        }

        ListNode* newHead = nullptr;
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            curr->next = newHead; 
            newHead = curr;
        }

        return newHead;
    }
};

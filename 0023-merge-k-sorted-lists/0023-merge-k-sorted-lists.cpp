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
        struct compare {
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;  // min-heap (smallest val on top)
            }
        };
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode();
        ListNode* newNode = dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();

            newNode->next = curr;
            newNode = newNode->next;

            if (curr->next) pq.push(curr->next);
        }

        return dummy->next;
    }
};

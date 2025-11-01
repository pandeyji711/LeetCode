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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> m;
        
        // Count the frequency of each number in the nums vector
        for (int num : nums) {
            m[num]++;
        }

        // Edge case: If the list is empty, return nullptr
        if (!head) return nullptr;

        // Edge case: If the list has only one node
        if (!head->next) {
            if (m.find(head->val) != m.end()) return nullptr;
            return head;
        }

        // Initialize pointers for list traversal
        ListNode* pre = head;
        ListNode* curr = head->next;

        // Special case: if the second node is the only other node
        if (!curr->next) {
            if (m.find(pre->val) != m.end()) {
                head = curr;
            }
            if (m.find(curr->val) != m.end()) {
                pre->next = nullptr;
            }
            return head;
        }

        // General case: Traverse and remove nodes as necessary
        while (curr) {
            ListNode* next = curr->next;
            if (m.find(curr->val) != m.end()) {
                pre->next = next;  // Remove the current node
            } else {
                pre = curr;  // Move pre only if curr is not removed
            }
            curr = next;
        }

        // If the head node itself needs to be removed
        if (m.find(head->val) != m.end()) {
            head = head->next;
        }

        return head;
    }
};

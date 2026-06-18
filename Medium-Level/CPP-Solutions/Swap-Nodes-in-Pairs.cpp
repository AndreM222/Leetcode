// --------------------------------------------[ Recursion ]--------------------------------------------
// O(n)
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
    ListNode* swapper(ListNode* left, ListNode* right) {
        if(!left || !right) return left;

        ListNode* pair = right->next;

        left->next = swapper(pair, pair ? pair->next : nullptr);
        right->next = left;

        return right;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* newList;
        if(!head) return nullptr;

        newList = swapper(head, head->next);

        return newList;
    }
};

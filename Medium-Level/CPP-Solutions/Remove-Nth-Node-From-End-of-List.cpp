// --------------------------------------------[ Using Simple Recursion ]--------------------------------------------
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
private:
    ListNode* nodeDeleter(ListNode* head, int node, int& index) {
        if(head->next != nullptr)
            head->next = nodeDeleter(head->next, node, index);

        index++;
        if(index == node) return head->next;
        else return head;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = 0;
        ListNode* newHead = nodeDeleter(head, n, num);
        return newHead;
    }
};

// --------------------------------------------[ Loop and Recursion ]--------------------------------------------
// O(n * k)
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
    ListNode* merger(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        if (list1->val < list2->val) {
            list1->next = merger(list1->next, list2);
            return list1;
        } else {
            list2->next = merger(list1, list2->next);
            return list2;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newList = nullptr;

        for(int i = 0; i < lists.size(); i++) {
            newList = merger(newList, lists[i]);
        }

        return newList;
    }
};

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* cList = nullptr;

        if (list1->val < list2->val)
        {
            cList = list1;
            list1 = list1->next;
        }
        else
        {
            cList = list2;
            list2 = list2->next;
        }

        ListNode* headMerged = cList;

        while (list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
            cList->next = list1;
            list1 = list1->next;
            cList = cList->next;
            }
            else
            {
            cList->next = list2;
            list2 = list2->next;
            cList = cList->next;
            }
        }

        if (list1 != nullptr) cList->next = list1;
        else cList->next = list2;
        
        return headMerged;
    }
};

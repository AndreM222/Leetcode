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
class Solution
{
  private:
    ListNode *tempList(ListNode *l1, ListNode *l2, int carry)
    {
        // if current l1 and l2 are both null
        if (!l1 && !l2)
        {
            // if so then is there a carry
            // if yes then we creat a new node to add the number
            if (carry)
                return new ListNode(carry);

            // if there is no carry then we end everything here
            return NULL;
        }

        // else it means there are still values

        /* get total value, if one of the list is null then return 0 and add everything together
        with the carry */
        int total = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;

        // We creat the head node and value becomes the total minus the 10th place
        ListNode *node = new ListNode(total % 10);

        // We start creating the tails with the carry being the 10th place of the total
        /* if current is null then return null since, else return what comes next wich
        can be a value or null */
        node->next = tempList(l1 ? l1->next : NULL, l2 ? l2->next : NULL, total / 10);

        return node;
    }

  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // return list through recursion carry starting at 0
        return tempList(l1, l2, 0);
    }
};

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
    bool limitPoint(ListNode* head, int k)
    {
        // Parse through connections
        for(int i = 0; i < k; i++){
            if(head == NULL) return true; // If end then is limit
            head = head->next; // Set next connection
        }
        
        return false; // Return is not limit
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // End if off limits and start returning end point
        if (limitPoint(head, k)) return head;

        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        // Loop to knot bottom to top
        for(int i = 0; i < k; i++)
        {
            next = curr->next; // Store next from current
            curr->next = prev; // Replace current next with previous
            prev = curr; // Set current as previous
            curr = next; // Set next as current

            /* It will set the start to connect to null, after it
             * will make what was its next conection to be infront
             * by connecting past front as its new next */
        }
        head->next = reverseKGroup(curr, k); // Continue setup of groups
        return prev; // Return group for connection
    }
};

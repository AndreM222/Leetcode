/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> copy; // Store pointers
        Node* curr = head; // Set as pointer to current node copy

        while(curr) // Loop until we reach end
        {
           copy[curr] = new Node(curr->val); // Set new node with val
           curr = curr->next; // Next node
        }

        curr = head;
        while (curr) // Loop until we reach end
        {
            copy[curr]->next = copy[curr->next]; // Set next pointer in node
            copy[curr]->random = copy[curr->random]; // Set random pointer in node
            curr = curr->next; // Next node
        }

        return copy[head]; // Return value of starting node point
    }
};

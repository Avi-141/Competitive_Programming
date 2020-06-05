/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int listLength(ListNode* head)
    {
        int res = 0;
        if(!head)
            return res;
        while(head) {
            res++;
            head = head->next;
        }
        return res;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = listLength(headA);
        int lenB = listLength(headB);
        int diff = abs(lenA - lenB);
        ListNode* shortest;
        ListNode* longest;
        if(lenA > lenB) {
            shortest = headB;
            longest = headA;
        } else {
            shortest = headA;
            longest = headB;
        }
        
        while(diff) {
            longest = longest->next;
            diff--;
        }
        while(longest && shortest && shortest != longest) {
            longest = longest->next;
            shortest = shortest->next;
        }
        
        return shortest;
         
    }
};

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count = 0;
        vector<ListNode*> res(k , NULL);
        ListNode * curr = head;
        if(head == NULL) return res;
        
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        int size = count / k;
        int extraParts = count % k;

        curr = head;

        ListNode * prev = NULL;

        for(int i=0 ; i<k; i++){
            count = 0;
            res[i] = curr;
            if(i < extraParts){
                while(count < size + 1 && curr != NULL){
                    prev = curr;
                    curr = curr->next;
                    count++;
                }
                prev->next = NULL;
            }else{
                while(count < size && head != NULL){
                    prev = curr;
                    curr = curr->next;
                    count++;
                }
                prev->next = NULL;
            }
        }

        return res;
    }
};
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
    void reorderList(ListNode* head) {
        vector<int> store;
        ListNode * temp = head;
        while(temp != NULL){
            store.push_back(temp->val);
            temp = temp->next;
        }
        temp = head;
        
        int left=  1, right = store.size() - 1;

        while(left <= right){
            if(left == right){
                temp->next = new ListNode(store[right]);
            temp = temp->next;
            }else{
               temp->next = new ListNode(store[right]);
            temp = temp->next;
            temp->next = new ListNode(store[left]);
            temp = temp->next;
            
            }
           
            left++;
            right--;
        }
        head = temp;
    }
};
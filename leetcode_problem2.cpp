/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *last = &head;
        int carry = 0;
        int sum = 0;
        while (l1 != NULL && l2 != NULL) {
            sum =l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            ListNode *node = new ListNode(sum % 10);
            last->next = node;
            last = node;
            carry = (sum >= 10)? 1 : 0;
        }
        if (l1 != NULL) {
            while (l1 != NULL) {
                sum = l1->val + carry;
                ListNode *node = new ListNode(sum % 10);
                last->next = node;
                last = node;
                l1 = l1->next;
                carry = (sum >= 10)? 1 : 0;
            }
        }
        if (l2 != NULL) {
            while (l2 != NULL) {
                sum = l2->val + carry;
                ListNode *node = new ListNode(sum % 10);
                last->next = node;
                last = node;
                l2 = l2->next;
                carry = (sum >= 10)? 1 : 0;
            }
        }
        if(carry == 1) {
            ListNode *node = new ListNode(1);
            last->next = node;
            last = node;
        }
        return head.next;
    }
};
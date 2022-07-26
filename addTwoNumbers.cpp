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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    note: 1. 需要考虑两个链表节点数量不一致的情况
          2. 有进位的问题，如果最高位有进位，还需要新建节点
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ptr1 = l1, *ptr2 = l2, *ptr3 = nullptr, *header = nullptr, *tail = nullptr;
        int carry = 0;
        while (ptr1 != nullptr || ptr2 != nullptr) {
            carry += (ptr1 == nullptr ? 0 : ptr1->val);
            carry += (ptr2 == nullptr ? 0 : ptr2->val);
            ptr3 = new ListNode(carry % 10);
            if (header == nullptr) {
                header = ptr3;
                tail = ptr3;
            } else {
                tail->next = ptr3;
                tail = ptr3;
            }
            carry /= 10;
            if (ptr1 != nullptr)
                ptr1 = ptr1->next;
            if (ptr2 != nullptr)
                ptr2 = ptr2->next;
        }

        if (carry) {
            ptr3 = new ListNode(1);
            tail->next = ptr3;
        }

        return header;
    }
};
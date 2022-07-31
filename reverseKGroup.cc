#include<utility>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
    note: 反转链表
    1. 将反转链表封装为函数，传入需要反转的头尾，返回新的头尾
    2. 为了免去对头的特殊处理，添加一个新的空节点作为head
    3. 还需要两个指针指向prev和next，在局部反转后，重新链接到链表上
*/

class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = head, *cur = head->next;

        while (prev != tail) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return make_pair(tail, head);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *new_head = new ListNode(-1);
        new_head->next = head;
        ListNode *prev = new_head;

        while (head) {
            ListNode *tail = head;
            for (int i = 1; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr) {
                    return new_head->next;
                }
            }
            ListNode *next = tail->next;

            pair<ListNode*, ListNode*> res = reverse(head, tail);
            head = res.first;
            tail = res.second;

            prev->next = head;
            tail->next = next;
            prev = tail;
            head = tail->next;
        }
        return new_head->next;
    }
};
/*
    NOTES:
        这题不难，就算没想到什么更好的解法，也可以直接的解决。实际就是将头尾的节点交叉链接在一起。
        我一开始的想法是，顺序遍历，每次把最后一个节点链接到当前节点后即可。
        但是每次都要遍历到最后一个节点，实际非常冗余。但我没想到什么好办法可以直接拿到末尾的节点。
        看了题解，可以先遍历一遍然后用数组存储节点，这样就可以直接访存。
        
        题解还提供了另一个巧妙的题解：用快慢指针获取中间节点，然后将中间节点后的链表翻转，最后合并两个链表。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = new ListNode(0, head);
        ListNode* next = nullptr;
        ListNode* last = head;
        ListNode* last_pre = head;

        while (cur != nullptr && cur->next != nullptr) {
            
            while (last->next != nullptr) {
                last_pre = last;
                last = last->next;
            }
            last_pre->next = nullptr;

            next = cur->next;
            last->next = next;
            cur->next = last;
            cur = next;
        }
    }
};

class Solution1 {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;

        ListNode* mid = midNode(head);
        ListNode* list1 = head;
        ListNode* list2 = mid->next;
        mid->next = nullptr;
        list2 = reverseList(list2);
        mergeList(list1, list2);
    }

    // find the middle node of list
    ListNode* midNode(ListNode* h) {
        ListNode* fast = h;
        ListNode* slow = h;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* h) {
        ListNode* pre = nullptr;
        ListNode* cur = h;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* next1 = nullptr;
        ListNode* next2 = nullptr;

        while (l1 != nullptr && l2 != nullptr) {
            next1 = l1->next;
            next2 = l2->next;

            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int v) : val(v) {}
};

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        ListNode *fake_head = new ListNode(-1);
        fake_head->next = head;
        ListNode *prev = fake_head, *cur = head;
        for (int i = 1; i < m; i++) {
            prev = cur;
            cur = cur->next;
        }
        for (int i = m; i < n; i++) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }
        
        return fake_head->next;
    }
};
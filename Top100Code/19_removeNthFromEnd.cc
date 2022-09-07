#include<iostream>
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fake_head = new ListNode(0, head);

        ListNode *pre = fake_head, *next = fake_head;
        for (int i = 0; i < n; ++i) {
            next = next->next;
        }

        while (next->next != nullptr) {
            pre = pre->next;
            next = next->next;
        }

        pre->next = pre->next->next;

        return fake_head->next;
    }
};
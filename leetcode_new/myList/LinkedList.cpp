//
// Created by shucheng on 18-1-15.
//
#include <iostream>
#include <vector>
#include <stack>

#include "LinkedListStructure.h"

using namespace std;

namespace LinkedList {
    class Solution {
    public:
        //
        //206. Reverse Linked List
        ListNode *reverseList(ListNode *head) {
            ListNode *pre = nullptr;
            ListNode *cur = head;

            while (cur) {
                ListNode *next = cur->next;

                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }

        //83. Remove Duplicates from Sorted List
        ListNode *deleteDuplicates(ListNode *head) {
            if (!head || !head->next) return head;
            ListNode *cur = head;

            while (cur) {
                if (cur->next && cur->val == cur->next->val) {
                    ListNode *delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                } else {
                    cur = cur->next;
                }
            }
            return head;
        }

        //86. Partition List
        ListNode *partition(ListNode *head, int x) {
            if (!head || !head->next) return head;

            ListNode leftH(0), rightH(0);
            ListNode *left = &leftH, *right = &rightH, *cur = head;

            while (cur) {
                if (cur->val < x) {
                    left->next = cur;
                    left = left->next;
                } else {
                    right->next = cur;
                    right = right->next;
                }
                cur = cur->next;
            }
            left->next = rightH.next;
            right->next = nullptr;
            return leftH.next;
        }

        //328. Odd Even Linked List
        ListNode *oddEvenList(ListNode *head) {
            if (!head || !head->next || !head->next->next) return head;

            ListNode oddHead(0), evenHead(0);
            ListNode *odd = &oddHead, *even = &evenHead, *cur = head;

            bool isOdd = true;
            while (cur) {
                if (isOdd) {
                    odd->next = cur;
                    odd = odd->next;
                } else {
                    even->next = cur;
                    even = even->next;
                }
                isOdd = !isOdd;
                cur = cur->next;
            }
            odd->next = evenHead.next;
            even->next = nullptr;
            return oddHead.next;
        }

        //2. Add Two Numbers
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            ListNode dummyHead(0);
            ListNode *head = &dummyHead;
            int carry = 0;

            while (l1 || l2 || carry) {
                int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
                carry = sum / 10;
                head->next = new ListNode(sum % 10);
                head = head->next;
                if (l1) l1 = l1->next;
                if (l2) l2 = l2->next;
            }
            return dummyHead.next;
        }

        //445. Add Two Numbers II
        ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
            if (!l1) return l2;
            if (!l2) return l1;

            stack<int> stack1, stack2;
            stack<ListNode *> result;
            while (l1) {
                stack1.push(l1->val);
                l1 = l1->next;
            }
            while (l2) {
                stack2.push(l2->val);
                l2 = l2->next;
            }

            int carry = 0;
            while (!stack1.empty() || !stack2.empty() || carry) {
                int val1 = 0, val2 = 0;
                if (!stack1.empty()) {
                    val1 = stack1.top();
                    stack1.pop();
                }
                if (!stack2.empty()) {
                    val2 = stack2.top();
                    stack2.pop();
                }
                int sum = val1 + val2 + carry;
                carry = sum / 10;
                result.push(new ListNode(sum % 10));
            }

            ListNode dummyHead(0);
            ListNode *head = &dummyHead;
            while (!result.empty()) {
                head->next = result.top();
                result.pop();
                head = head->next;
            }
            return dummyHead.next;
        }

        //82. Remove Duplicates from Sorted List II
        ListNode *deleteDuplicates2(ListNode *head) {
            if (!head || !head->next) return head;

            auto *dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *needDelStart = dummyHead, *cur = head;
            while (cur) {
                if (!cur->next) break;
                if (cur->val != cur->next->val) {
                    cur = cur->next;
                    needDelStart = needDelStart->next;
                    continue;
                }

                while (cur->next) {
                    if (cur->val != cur->next->val) break;
                    ListNode *delNode = cur;
                    cur = delNode->next;
                    delete delNode;
                }
                needDelStart->next = cur->next;
                cur = cur->next;
            }
            return dummyHead->next;
        }

        //21. Merge Two Sorted Lists
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode dummyHead(0);
            ListNode *p = &dummyHead;

            while (l1 && l2) {
                if (l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                } else {
                    p->next = l2;
                    l2 = l2->next;
                }
                p = p->next;
            }
            p->next = l1 ? l1 : l2;
            return dummyHead.next;
        }

        //203. Remove Linked List Elements
        ListNode *removeElements(ListNode *head, int val) {
            if (!head) return head;
            ListNode dummyHead(0);
            dummyHead.next = head;
            ListNode *p = &dummyHead;

            while (p->next) {
                if (p->next->val == val) {
                    ListNode *delNode = p->next;
                    p->next = delNode->next;
                    delete delNode;
                } else {
                    p = p->next;
                }
            }
            return dummyHead.next;
        }

        //24. Swap Nodes in Pairs
        ListNode *swapPairs(ListNode *head) {
            if (!head || !head->next) return head;

            ListNode dummyHead(0);
            dummyHead.next = head;
            ListNode *p = &dummyHead, *s1 = head, *s2 = head->next, *q = head->next->next;

            while (s2) {
                p->next = s2;
                s2->next = s1;
                s1->next = q;

                p = s1;
                s1 = q;
                if (!s1 || !s1->next) break;
                s2 = q->next;
                q = s2->next;
            }
            return dummyHead.next;
        }

        //147. Insertion Sort List
        ListNode *insertionSortList(ListNode *head) {
            auto dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *pre = dummyHead;
            ListNode *cur = head;

            while (cur) {
                if (cur->next && cur->next->val < cur->val) {
                    while (pre->next && pre->next->val < cur->next->val)
                        pre = pre->next;
                    ListNode *temp = pre->next;
                    pre->next = cur->next;
                    cur->next = cur->next->next;
                    pre->next->next = temp;
                    pre = dummyHead;
                } else {
                    cur = cur->next;
                }
            }
            return dummyHead->next;
        }

        //237. Delete Node in a Linked List
        void deleteNode(ListNode *node) {
            if (!node) return;
            if (!node->next) {
                delete node;
                return;
            }

            node->val = node->next->val;
            ListNode *delNode = node->next;
            node->next = delNode->next;
            delete delNode;
            return;
        }

        //19. Remove Nth Node From End of List
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            auto *dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *pre = dummyHead, *last = dummyHead;
            while (n--) last = last->next;
            while (last->next) {
                pre = pre->next;
                last = last->next;
            }
            ListNode *delNode = pre->next;
            pre->next = delNode->next;
            delete delNode;
            return dummyHead->next;
        }

        //61. Rotate List
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head) return head;
            int len = 1;
            ListNode *tail, *newHead;
            tail = newHead = head;
            while (tail->next) {
                tail = tail->next;
                len++;
            }
            tail->next = head;
            if (k) {
                k = k % len;
                for (int i = 0; i < len - k; i ++)
                    tail = tail->next;
            }
            newHead = tail->next;
            tail->next = nullptr;
            return newHead;
        }

        //234. Palindrome Linked List
        bool isPalindrome(ListNode *head) {
            if (!head || !head->next) return true;
            int size = 0;
            ListNode *p = head;
            while (p) {
                size++;
                p = p->next;
            }

            int half = size / 2 - 1;

            p = head;
            while (half--) p = p->next;
            ListNode *right = p->next;
            p->next = nullptr;

            right = reverseList(right);
            while (head) {
                if (head->val != right->val)
                    return false;
                head = head->next;
                right = right->next;
            }
            return true;
        }
    };
}

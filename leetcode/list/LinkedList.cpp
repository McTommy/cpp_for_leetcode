//
// Created by shucheng on 17-10-26.
//
#include <iostream>

#include "LinkedListStructure.h"

using namespace std;

namespace LinkedList {
    class Solution {
    public:
        ListNode *reverseList(ListNode *head) {
            ListNode *pre = nullptr;
            ListNode *cur = head;
            while (cur != nullptr) {
                ListNode *next = cur->next;

                cur->next = pre;
                pre = cur;
                cur = next;
            }

            return pre;
        }

        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (m == n)return head;
            n -= m;
            ListNode prehead(0);
            prehead.next = head;
            ListNode *pre = &prehead;
            while (--m)pre = pre->next;
            ListNode *pstart = pre->next;
            while (n--) {
                ListNode *p = pstart->next;
                pstart->next = p->next;
                p->next = pre->next;
                pre->next = p;
            }
            return prehead.next;

        }

        ListNode *deleteDuplicates(ListNode *head) {
            if (head == nullptr)
                return head;
            ListNode *curNode = head;
            ListNode *nextNode = head->next;
            while (nextNode != nullptr) {
                if (nextNode->val == curNode->val) {
                    ListNode *delNode = nextNode;
                    nextNode = nextNode->next;
                    curNode->next = nextNode;
                    delete (delNode);
                } else {
                    curNode = nextNode;
                    nextNode = nextNode->next;
                }
            }

            return head;
        }

        ListNode *partition(ListNode *head, int x) {
            ListNode left(0), right(0);
            ListNode *l = &left, *r = &right;

            while (head != nullptr) {
                if (head->val < x) {
                    l->next = head;
                    l = l->next;
                } else {
                    r->next = head;
                    r = r->next;
                }
                head = head->next;
            }
            l->next = right.next;
            r->next = nullptr;
            return left.next;
        }

        ListNode *oddEvenList(ListNode *head) {
            if (head == nullptr)
                return head;
            ListNode *odd = head, *even = head->next, *evenStart = even;

            while (even != nullptr && even->next != nullptr) {
                odd->next = odd->next->next;
                even->next = even->next->next;
                odd = odd->next;
                even = even->next;
            }

            odd->next = evenStart;
            return head;
        }

        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        }
    };
}



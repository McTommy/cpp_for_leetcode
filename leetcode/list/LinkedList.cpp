//
// Created by shucheng on 17-10-26.
//
#include <iostream>
#include <vector>

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
            ListNode node(0);
            ListNode *p = &node;

            int n = 0;
            while (l1 || l2 || n) {
                int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + n;
                n = sum / 10;
                p->next = new ListNode(sum % 10);

                p = p->next;

                l2 = l2 ? l2->next : l2;
                l1 = l1 ? l1->next : l1;
            }

            return node.next;
        }

        ListNode *addTwoNumbers2(ListNode *l1, ListNode *l2) {
            vector<int> num1, num2;
            while (l1) {
                num1.push_back(l1->val);
                l1 = l1->next;
            }
            while (l2) {
                num2.push_back(l2->val);
                l2 = l2->next;
            }

            auto size1 = static_cast<int>(num1.size());
            auto size2 = static_cast<int>(num2.size());

            int carry = 0, sum = 0;
            ListNode *p = nullptr, *head = nullptr;

            for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0 || carry > 0; j--, i--) {
                sum = carry;
                if (i >= 0)
                    sum += num1[i];
                if (j >= 0)
                    sum += num2[i];

                carry = sum / 10;
                p = new ListNode(sum % 10);
                p->next = head;
                head = p;
            }
            return head;

        }

        ListNode *removeElements(ListNode *head, int val) {
            auto *p = new ListNode(0);
            p->next = head;

            ListNode *cur = p;
            while (cur->next != nullptr) {
                if (cur->next->val == val) {
                    ListNode *delNode = cur->next;
                    cur->next = delNode->next;
                    delete delNode;
                } else
                    cur = cur->next;
            }
            ListNode *ret = p->next;
            delete p;

            return ret;
        }

        ListNode *deleteDuplicates2(ListNode *head) {
            if (!head) return nullptr;
            if (!head->next) return head;

            int val = head->val;
            ListNode *p = head->next;

            if (p->val != val) {
                head->next = deleteDuplicates(p);
                return head;
            } else {
                while (p && p->val == val) p = p->next;
                return deleteDuplicates(p);
            }
        }

        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            auto *p = new ListNode(0);
            ListNode *dummyHead = p;


            while (l1 || l2) {
                if (!l1 || !l2) {
                    p->next = l1 ? l1 : l2;
                    p = p->next;
                    l1 ? l1 = l1->next : l2 = l2->next;
                } else {
                    p->next = (l1->val < l2->val) ? l1 : l2;
                    p = p->next;
                    (l1->val < l2->val) ? l1 = l1->next : l2 = l2->next;
                }
            }
            return dummyHead->next;
        }

        ListNode *swapPairs(ListNode *head) {
            auto *dummyHead = new ListNode(0);
            dummyHead->next = head;
            ListNode *p = dummyHead;
            while (p->next && p->next->next) {
                ListNode *node1 = p->next;
                ListNode *node2 = node1->next;
                ListNode *next = node2->next;

                node2->next = node1;
                node1->next = next;
                p->next = node2;

                p = node1;
            }

            ListNode *ret = dummyHead->next;
            delete dummyHead;
            return ret;
        }

        ListNode *insertionSortList(ListNode *head) {
            auto *dummyHead = new ListNode(0);
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

            ListNode *ret = dummyHead->next;
            delete dummyHead;
            return ret;
        }

        ListNode *removeNthFromEnd(ListNode *head, int n) {
            auto *dummyHead = new ListNode(0);
            dummyHead->next = head;

            ListNode *preNode = dummyHead, *endNode = head;
            while (n--)
                endNode = endNode->next;
            while (endNode) {
                preNode = preNode->next;
                endNode = endNode->next;
            }

            ListNode *delNode = preNode->next;
            preNode->next = delNode->next;

            delete delNode;
            ListNode *retNode = dummyHead->next;
            delete dummyHead;
            return retNode;
        }

        ListNode *rotateRight(ListNode *head, int k) {
            if (!head) return head;

            int len = 1; // number of nodes
            ListNode *newH, *tail;
            newH = tail = head;

            while (tail->next)  // get the number of nodes in the list
            {
                tail = tail->next;
                len++;
            }
            tail->next = head; // circle the link

            if (k %= len) {
                for (auto i = 0; i < len - k; i++)
                    tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
            }
            newH = tail->next;
            tail->next = nullptr;
            return newH;
        }
    };
}



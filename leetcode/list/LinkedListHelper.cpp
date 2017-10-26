//
// Created by shucheng on 17-10-26.
//
#include <iostream>

#include "LinkedListStructure.h"

using namespace std;

namespace LinkedListHelper {
    class LinkedListHelper {
    public:
        ListNode *createLinkedList(int arr[], int n) {
            if (n == 0)
                return nullptr;

            auto *head = new ListNode(arr[0]);

            ListNode *curNode = head;
            for (int i = 1; i < n; i++) {
                curNode->next = new ListNode(arr[i]);
                curNode = curNode->next;
            }
            return head;
        }

        void printLinkedList(ListNode *head) {
            ListNode *curNode = head;
            while (curNode != nullptr) {
                cout << curNode->val << " -> ";
                curNode = curNode->next;
            }
            cout << "NULL" << endl;
        }

        void deleteLinkedList(ListNode *head) {
            ListNode *curNode = head;
            while (curNode != nullptr) {
                ListNode *delNode = curNode;
                curNode = curNode->next;
                delete (delNode);
            }
        }
    };
}


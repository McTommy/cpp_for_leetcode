#include <iostream>

#include "leetcode/list/LinkedList.cpp"
#include "leetcode/list/LinkedListHelper.cpp"

using namespace std;

int main() {
//    linkedList
    int arr[] = {3, 4, 5};
    int arr2[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    LinkedList::Solution solution = LinkedList::Solution();
    LinkedListHelper::LinkedListHelper helper = LinkedListHelper::LinkedListHelper();

    ListNode* head = helper.createLinkedList(arr, n);
    helper.printLinkedList(head);

    ListNode* head2 = solution.oddEvenList(head);
    helper.printLinkedList(head2);

    helper.deleteLinkedList(head2);

    return 0;
}
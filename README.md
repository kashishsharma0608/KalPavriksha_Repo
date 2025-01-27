# KalPavriksha_Repo
This repository consist of the assignment given during KalPavriksha Learning program
Problem Statement: Sort Even and Odd Numbers in a Linked List
You are given a singly linked list where each node contains an integer value. Your task is to implement the Selection Sort algorithm to perform the following tasks:

Sort all the even numbers in ascending order.
Sort all the odd numbers in descending order.
Maintain the order of even and odd numbers, i.e., even numbers should remain in the original order of the list, and the same goes for odd numbers, but their values should be sorted as per the rules above.
Input:
A singly linked list of n nodes, where each node contains an integer value. (1 ≤ n ≤ 10^3)
The integers can range from -10^3 to 10^3.
Output:
The linked list where all even numbers are sorted in ascending order and all odd numbers are sorted in descending order.

Function Signature:
struct Node {
    int data;
    Node* next;
};

Node* sortEvenAndOdd(Node* head);

Constraints:
Do not use any additional data structures like arrays. Perform the sorting directly on the linked list.
Use Selection Sort to sort both even and odd numbers.
You must sort even numbers in ascending order and odd numbers in descending order.

Approach:
Traverse the linked list and separate the even and odd numbers into two different lists (preserving their original order).
Sort the even numbers list in ascending order using Selection Sort.
Sort the odd numbers list in descending order using Selection Sort.
Merge the even and odd numbers back into the original linked list, maintaining the positions of the even and odd groups.

Example:
Input:
head = 12 -> 3 -> 5 -> 8 -> 7 -> 6 -> 10
Output:
head = 6 -> 3 -> 5 -> 10 -> 7 -> 8 -> 12

Explanation:
Even numbers: [12, 8, 6, 10] are sorted in ascending order to become [6, 8, 10, 12].
Odd numbers: [3, 5, 7] are sorted in descending order to become [7, 5, 3].
The final linked list should maintain the relative positions of the even and odd groups, but the numbers within each group should be sorted according to the given rules.
Selection Sort Logic for Linked List:
Even Numbers: Traverse the list, find the minimum even number in the unsorted part of the list, and swap it with the first unsorted even number.
Odd Numbers: Traverse the list, find the maximum odd number in the unsorted part of the list, and swap it with the first unsorted odd number.
Perform these steps on their respective lists to achieve the desired sorting.

time complexity

createNode: O(1)
createLinkedList: O(n)
display: O(n)
sortOddList: O(n^2)
sortEvenList: O(n^2)
sortEvenOdd: O(n^2)
Overall Time Complexity: O(n^2)

space complexity
createNode: O(1)
createLinkedList: O(1)
display: O(1)
sortOddList: O(1)
sortEvenList: O(1)
sortEvenOdd: O(1)
main(): O(n)

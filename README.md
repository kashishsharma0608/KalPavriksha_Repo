Problem Statement
You are tasked with finding the Kth smallest element in a singly linked list. Given a linked list of integers and a value k, your goal is to determine the element that would appear in the Kth position if the list were sorted in ascending order. The linked list is built dynamically, and you need to process the data as provided.

Input Format
The first line contains an integer numberOfNodes representing the number of nodes in the linked list.
The next numberOfNodes lines each contain an integer, representing the elements of the linked list.
The last line contains an integer k, representing the position of the element to find when the list is sorted.
Output Format
Print a single integer, the Kth smallest element in the list.

Example
Input:

Copy
Edit
5
7
3
10
1
5
3
Output:

Copy
Edit
5
Explanation
The linked list is created with elements: 7 -> 3 -> 10 -> 1 -> 5.
Sorting the list results in: 1, 3, 5, 7, 10.
The 3rd smallest element in this sorted list is 5.

Time Complexity
createNode(int value) - o(1)
createLinkedList(struct node **head, int value) - o(n)
display() -o(n)
partition() -o(n) - it traverses entire list for partition it into two.
findKthSmallestElement(struct node *head, int kthElement) - o(n^2) this is worst case when pivot selected ends up being smallest or largest element in the list.

space complexity 
findKthSmallestElement(struct node *head, int kthElement) -o(n) recursive call stack in worst case.
main() -o(n) for storing nodes

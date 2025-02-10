Problem Statement:

You are required to implement a function to perform group-wise sorting on a singly linked list. The list should be sorted in groups of k nodes using insertion sort.

Task
You need to create a program that:

Takes an integer n (the number of nodes) as input and creates a singly linked list by taking n integers as the node values.
Takes an integer k (the group size) as input. The linked list should be sorted in groups of k nodes using the insertion sort algorithm.
Outputs the original linked list and the sorted list.

Input and Output:

The input consists of:
An integer n representing the number of nodes in the list.
n integers representing the values of the nodes.
An integer k representing the group size for sorting.
The output consists of:
The original linked list.
The group-wise sorted linked list.
If k is 1, the list remains unchanged as no sorting is required.

Constraints:
1 <= n <= 10^4 (Number of nodes)
1 <= k <= n (Group size)

Example:
Input:
5
4 3 2 1 5
3
Output:
Original List: 4 3 2 1 5
3 Wise Sorted List:
1 2 4 3 5
time complexity
createNode(int value): O(1)
createLinkedList(struct node **start, int value): O(n)
display(struct node *start): O(n)
sortList(struct node *head, struct node *newSortedHead): O(n)
insertionSort(struct node *head): O(n^2)
kGroupWiseSort(struct node *head, int groupValue): O(n * k) - k^2 for insertion sort , n/k because there will be n/k times sorting for each group. 
freeMemory(struct node **start): O(n)

Total : O(n*k)

Space Complexity:
createNode(int value): O(1)
createLinkedList(struct node start, int value): O(1)
display(struct node *start): O(1)
sortList(struct node *head, struct node *newSortedHead): O(1)
insertionSort(struct node *head): O(n) space for new sorted list
kGroupWiseSort(struct node *head, int groupValue): O(n) dummy node is created and sorted n nodes

Total: O(n)
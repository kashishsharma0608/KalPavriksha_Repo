Problem Description:
In a magical world, Harry Potter is on a quest to find a pair of nodes from a mystical tree (represented by a Doubly Linked List) whose sum of values is equal to a given harryPower. Harry Potter is searching for pairs of nodes from both ends of the tree, and when a valid pair is found, it is displayed.
NOTE: list is always sorted.
Input:
numberOfMysticTrees (N): The number of nodes in the Doubly Linked List (1 ≤ N ≤ 10^5).
Nodes: A sequence of N integers, each representing the data stored in a node of the tree.
harryPower: A single integer representing the target sum of the pair of nodes Harry Potter is looking for.
Output:
If a pair of nodes with their sum equal to harryPower is found, output the pair.
If no such pair exists, print "No Mystic Tree found".
Constraints:
1 ≤ N ≤ 10^5: The number of nodes in the list.
1 ≤ value ≤ 10^6: The value in each node.
1 ≤ harryPower ≤ 2 * 10^6: The target sum of the pair.

Sample Input:
5
1 3 5 7 9
8
Sample Output:
Mystic Pair: (1, 7)
Mystic Pair: (3, 5)

Time Complexity and Space Complexity
createNode(int value) - o(1)
createDoublyLinkedList(struct node **head, int value) - o(n)
display() -o(n)
findHarryMysticTree(struct node *head, int harryPower) - o(n) for traversing and comparing

space complexity
main() -o(n) to store n nodes

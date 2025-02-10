You are the dedicated librarian of a grand library, entrusted with the responsibility of ensuring that all books are always arranged in perfect order. The books are typically organized alphabetically by their titles, starting from A to Z, creating a seamless browsing experience for readers.

However, one chaotic afternoon, a mischievous kid wanders into the library and disrupts the arrangement of books, leaving them in complete disarray. Now, your task is to restore order to the shelves. To do this, you need to implement an efficient algorithm to sort the books back into their proper alphabetical order.

The sorting should arrange the books such that they follow an ascending to descending alphabetical sequence based on their titles, from the smallest (starting with 'A') to the largest (ending with 'Z'). Design a solution that can handle this scenario effectively, ensuring the library regains its pristine and organized state.

Input Format:

A linked list where each node contains a string representing a book title.
The input is provided by the user dynamically by adding nodes to the linked list.
Output Format:

A sorted linked list, where the titles are arranged alphabetically in ascending order.
Constraints:

The implementation must use a linked list data structure (singly or doubly).
The algorithm must handle any number of nodes, including edge cases like an empty list or a single-node list.
The sorting should be done in-place or by reconstructing the linked list.
Example:

Input:
"Harry Potter" -> "1984" -> "The Alchemist" -> "Pride and Prejudice" -> "To Kill a Mockingbird"

Output:
"1984" -> "Harry Potter" -> "Pride and Prejudice" -> "The Alchemist" -> "To Kill a Mockingbird"

Time Complexity:

createNode: O(1)
createLinkedList: O(n²)
display: O(n)
freeMemory: O(n)
splitList: O(n)
mergeSortedList: O(n)
mergeSort: O(n log n)

Overall : O(n^2)

Space Complexity

createNode: O(1)
createLinkedList: O(n) (for the entire list)
display: O(1)
freeMemory: O(1)
splitList: O(1)
mergeSortedList: O(1) (excluding recursion)
mergeSort: O(n) (due to recursion)
 
Overall : O(n)




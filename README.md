**Queue implementation through linked list**

This C program implements a circular queue using a linked list. It provides basic queue operations such as enqueue, dequeue, peek, checking size, and displaying elements. The queue maintains FIFO (First-In-First-Out) order and uses pointers to keep track of the front and rear elements.

->Key Functionalities
Creating a Queue Node -Uses createNode(int value) to allocate memory dynamically.Initializes data and next pointers.
Checking if the Queue is Empty -isEmpty(queue *front) returns 1 if the queue is empty, else 0.
Enqueue Operation-Adds a new node to the rear.Updates the rear pointer and maintains circular linkage.

Dequeue Operation-Removes the front node and updates the front pointer.If only one element remains, resets front and rear to NULL.

Peek Operation-Retrieves the front element without removing it.

Size Calculation-Traverses the queue to count the number of elements.

Display Function-Prints all elements from front to rear, maintaining the circular nature.

Main Function-Takes user input for the number of operations and choice selection.Implements a menu-driven approach.

**Time complexity**
Enqueue	O(1)
Dequeue	O(1)
Peek	O(1)
Size	O(n)
Display	O(n)
Free Queue	O(n)

**Space complexity**
O(n) for storing n queue elements
O(1) for front, rear, and function call variables

**Edge cases**
If queue is empty or full condition are checked.
If user access peek or any operation while queue is empty is checked properly
Linked list is implemented with memory freeing for any segmentation fault or memory leak



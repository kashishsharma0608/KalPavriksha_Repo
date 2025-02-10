Stack Implementation using Two Queues

This C program implements a stack using two queues. It simulates stack operations like push, pop, peek, and size using queue-like structures. The stack follows the LIFO (Last-In-First-Out) order while utilizing the basic enqueue and dequeue operations of queues.

Key Functionalities

Creating Two Queues: Two arrays (queue1 and queue2) are used to simulate the stack. queue1 holds the main elements, while queue2 is used temporarily during the push operation.

Push Operation (push function):Inserts an element into the stack (implemented using two queues).
If queue1 is empty, the element is added directly.
If not, all elements from queue1 are transferred to queue2, the new element is added to queue1, and then elements from queue2 are moved back to queue1 to preserve the order.

Pop Operation (pop function): Removes and prints the front element of queue1 (which represents the top element of the stack).
If the queue is empty, a message indicating the stack is empty is displayed.

Peek Operation (peek function):Displays the top element (front element of queue1) without removing it.
If the queue is empty, a message is printed.

Size Calculation (size function):Computes and displays the number of elements currently in the stack (based on the difference between rear1 and front1).
If the stack is empty, it prints "stack is empty".

Main Function:Takes user input for the number of operations and choice of operation.
Implements a menu-driven approach to handle multiple operations like push, pop, peek, and size.

Time Complexity
Push: O(n) – All elements in the stack are transferred between the queues.
Pop: O(1) – Only the front element is removed.
Peek: O(1) – The front element is accessed directly.
Size: O(1) – The size is calculated using the difference between the front and rear pointers.

Space Complexity
O(n) for storing n elements in the queue-based stack.
Edge Cases
Checks if the stack is empty before performing pop, peek, or size operations.
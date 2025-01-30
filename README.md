Queue Implementation Using Two Stacks
This C program implements a queue using two stacks. It simulates the basic queue operations like enqueue, dequeue, peek, and size using stack-like structures. The queue follows the FIFO (First-In-First-Out) order while utilizing the push and pop operations of stacks.

Key Functionalities

Creating Two Stacks: Two arrays (stack and stack2) are used to simulate the queue. The first stack (stack) holds the elements when they are enqueued, and the second stack (stack2) is used for dequeueing.

Enqueue Operation (enqueue function):Adds an element to the queue by pushing it onto stack.
If stack is full, an overflow message is displayed.

Dequeue Operation (dequeue function): Removes the front element of the queue.
If stack is empty, the elements of stack are transferred to stack2 in reverse order to simulate the FIFO behavior.
After transferring, the top of stack2 is popped and printed as the dequeued value.
Elements from stack2 are then pushed back to stack to maintain the correct order.

Peek Operation (peek function): Displays the front element of the queue, which is the first element of stack after the dequeue operation has been executed.

Size Calculation (size function): Displays the number of elements in the queue by checking the current position of the top pointer.

Main Function: Takes user input for the number of operations and choice of operation.
Implements a menu-driven approach to handle multiple operations like enqueue, dequeue, peek, and size.

Time Complexity
Enqueue: O(1) – The element is added directly to the stack.
Dequeue: O(n) – All elements may need to be transferred from stack to stack2 to maintain the queue order.
Peek: O(1) – The front element is accessed directly from stack.
Size: O(1) – The size is determined by the current position of the top pointer.

Space Complexity
O(n) for storing n elements in the two stacks used to simulate the queue.

Edge Cases
Handles the underflow condition when the queue is empty during a dequeue operation.
Displays overflow and underflow messages for invalid operations when the queue is full or empty.
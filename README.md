Queue implementation using stack

A-isEmpty(int top) – Checks if the stack (used to implement the queue) is empty by verifying if top is -1.

B-enqueue(int stack[], int *top, int value) – Inserts a new element at the top of the stack, simulating an enqueue operation in a queue. If the stack is full (top == MAX - 1), it prints an overflow message.

C-dequeue(int stack[], int *top) – Removes the front element of the queue. Since a stack follows LIFO order but a queue requires FIFO, the function transfers all elements (except the bottom-most) to a temporary array, removes the front element, and then pushes the remaining elements back into the stack in the correct order. If the stack is empty, it prints an underflow message.

D-peek(int stack[], int top) – Displays the front element of the queue (i.e., the bottom-most element of the stack). If the stack is empty, it prints an error message.

E-size(int stack[], int top) – Calculates and prints the current number of elements in the queue using top + 1. If the stack is empty, it prints an appropriate message.

F-main() – Handles user input, allowing them to perform queue operations through a menu-driven interface. The user enters the number of operations and then selects from options (enqueue, dequeue, peek, size, exit). The program processes each choice accordingly, modifying the stack as needed.

Time complexity
enqueue - o(1)
dequeue -o(n)
peek - o(1)
size - o(1)
main() -o(n^2) due to mulitple dequeue call

space complexity
enqueue, peek, size: O(1)
dequeue: O(n) due to the temporary array
main: O(n) for the stack and the temporary array.
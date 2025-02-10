Janice, a passionate young cricketer, dreams of becoming a professional player. She joins the WBC Cricket Academy, which follows a strict "One Coach Per Player" policy. To begin her training, Janice needs to find an available coach.

The academy has a list of coaches, each with a name and an availability status (1 for available, 0 for not available). The system should allow Janice to:

Check the availability of a specific coach by name.
Display the list of all coaches with their availability.
Find any available coach for her training.

Constraints:
The number of coaches must be greater than or equal to 0 and less than 100.
The program should validate the input and terminate gracefully if the number of coaches is invalid.
The names of the coaches are unique and consist of alphabets only.

Input Format:
The first line contains the number of coaches 
𝑁
N, where 
0
≤
𝑁
<
100
0≤N<100.
The next 
𝑁
N lines contain the coach's name (a string) and their availability (0 or 1).
After entering the coaches, Janice can interact with the system using a menu-driven approach:
1: Enter the name of the coach to check availability.
2: Display the list of all coaches with their availability.
3: Check for any available coach.
0: Exit the program.

Output Format:
If a coach is found, display a message:
"Congratulations! You have been assigned [Coach Name] for training."
If a specific coach or any coach is not available, display:
"Sorry! The coach [Coach Name] is not available."
or
"Sorry! No coach is available."
When displaying the coach list, format each entry as:
"Coach Name: [Coach Name], Availability: [Available/Not Available]"
If the number of coaches is invalid, display:
"Invalid input! The number of coaches must be between 0 and 99."

Example:
Input:
5  
Ram 1  
Shyam 0  
Krishna 1  
Vishnu 0  
Radha 1 

Menu Interaction:
1. Check for the coach availability by name.  
2. Display coach list.  
3. Check for any coach availability.  
0. Exit.

Sample Interaction:
Input: 1
Enter the name of the coach you want: Vishnu
Output:
Sorry! The coach Vishnu is not available.

Time Complexity and Space Complexity:
Function Name	    Time Complexity	    	
createNode	                    O(L)		    //constant time and space for allocation and initialization
createLinkedList	            O(M²)		    // M for traversing and calling it for M times 
displayCoachList	            O(M)		    // M for traversing
chechCoachAvailability      O(M × L)    	    //M for node and L for comparing
checkAnyCoachAvailability	    O(M)		    //M for node 
freeMemory	                    O(M)		   
Total (Main Function)  O(M² + M × L) 

Space Complexity:
It takes M spaces to store N nodes and other function takes constant times .
Total Space : O(M);
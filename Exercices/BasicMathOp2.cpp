/*
🔹 Exercise 4: Input Validation with Repeated Prompt

🎯 Objective:

Modify the program so that if the user enters an invalid value,
it will keep asking for the numbers until valid input is provided.

📚 Key Concepts to Learn
	1.	Loops (while or do-while)
	•	We need a loop to keep asking until valid input is provided.
	2.	Checking std::cin.fail() continuously
	•	If the input is invalid, std::cin enters a failure state and needs to be reset.
	3.	Clearing the error state and discarding invalid input
	•	Use std::cin.clear() and std::cin.ignore() inside the loop.

💡 Hints for the Solution
	1.	Use a while loop to keep asking for numbers until valid input is given.
	2.	Inside the loop:
	•	If input is not a number, clear the error state (std::cin.clear()) and discard the invalid input (std::cin.ignore()).
	•	Ask the user to re-enter the numbers.
	3.	Once valid input is received, perform the calculations as before.
*/

#include <iostream>
#include <string>

int main(void)
{
    std::cout << "Hello,\nGive me 2 numbers please:\n";

    double n1, n2;

    do {
        std::cout << "Number 1: ";
        std::cin >> n1;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
    } while (std::cin.fail());

    do {
        std::cout << "Number 2: ";
        std::cin >> n2;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a valid number.\n";
        }
    } while (std::cin.fail());

    std::cout << "Sum: " << (n1 + n2) << std::endl;
    std::cout << "Difference: " << (n1 - n2) << std::endl;
    std::cout << "Product: " << (n1 * n2) << std::endl;
    
    if (n2 == 0) {
        std::cout << "Cannot be divided by 0!" << std::endl;
    } else {
        std::cout << "Quotient: " << (n1 / n2) << std::endl;
    }

    return 0;
}

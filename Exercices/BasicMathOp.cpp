/*
🔹 Exercise 3: Basic Math Operations

🎯 Objective:

Write a program that:
	1.	Asks the user for two numbers.
	2.	Computes and displays their sum, difference, product, and quotient.


📚 Key Concepts to Learn:
	1.	User input with std::cin → Reading multiple values.
	2.	Basic arithmetic operators:
	    •	+ for addition
	    •	- for subtraction
	    •	* for multiplication
	    •	/ for division
	3.	Handling division by zero (Hint: check if the second number is 0 before dividing).


💡 Hints to Guide You:
	•	Declare two variables (double is better than int for division).
	•	Use std::cin to get two numbers from the user.
	•	Perform the four basic operations using +, -, *, /.
	•	Be careful with division! What happens if the second number is 0? 🤔
*/

# include <iostream>
# include <string>

int main(void)
{
    std::cout << "Hello,\nGive me 2 numbers please : " ;

    double n1, n2;

    std::cin >> n1 >> n2;

    std::cout << "Sum: " << (n1 + n2) << std::endl;
    std::cout << "Difference: " << (n1 - n2) << std::endl;
    std::cout << "Product: " << (n1 * n2) << std::endl;
    if (n2 == 0) {
        std::cout << "Cannot be divid by 0!" << std::endl;
    }
    else
        std::cout << "Quotient: " << (n1 / n2) << std::endl;

    return 0;
}

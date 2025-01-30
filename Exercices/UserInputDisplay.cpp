/*
Exercise 2: User Input & Display

🎯 Objective:
Write a program that asks the user for their first name and then displays a welcome message.

📚 Key Concepts to Learn:
	1.	User input with std::cin
	•	In C, you used scanf(), but in C++, you use std::cin.
	2.	Strings in C++ (std::string)
	•	Instead of using char array[] like in C, C++ provides a dedicated string type: std::string.
	•	Requires including <string>.

💡 Hints for the Exercise:
	•	Include the necessary libraries: <iostream> and <string>.
	•	Declare a variable: std::string firstName;.
	•	Ask the user for their name using std::cin >> firstName;.
	•	Print a message like “Welcome to 42, [firstName]!”.
*/

# include <iostream>
# include <string>

int main(void)
{
    std::cout << "Enter your first name : ";

    std::string name;
    std::cin >> name;

    std::string	str = "at 42, ";

    std::cout << "Welcome " << str << name << std::endl;

    return 0;
}

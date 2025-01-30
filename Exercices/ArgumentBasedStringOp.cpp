/*
🔹 Exercise 6: Argument-Based String Operations

🎯 Objective:

Write a program that takes command-line arguments and performs various operations on the input strings, such as:
	1.	Checking if each string is a palindrome.
	2.	Sorting the arguments in lexicographical order.
	3.	Counting the total number of vowels across all arguments.

📚 Key Concepts to Use
	1.	Command-Line Arguments:
	•	Parsing argc and argv to access the strings.
	2.	String Manipulation:
	•	Reversing strings to check for palindromes.
	•	Sorting strings using std::sort.
	•	Counting vowels in a string.
	3.	Custom Functions:
	•	Modularizing the code by creating helper functions for each operation.

💡 Steps to Solve
	1.	Parse Arguments:
	•	Loop through argv starting from argv[1] (skip argv[0], which is the program name).
	•	Treat each argument as a string (std::string).
	2.	Palindrome Check:
	•	For each string, reverse it and compare it to the original.
	3.	Sorting:
	•	Use std::sort to sort the arguments alphabetically.
	4.	Vowel Counting:
	•	Loop through each string and count a, e, i, o, u (case-insensitive).

📌 Expected Output

Example Command:
    ./a.out racecar hello world level apple

Output:
    Palindromes:
    - racecar
    - level

    Sorted Arguments:
    - apple
    - hello
    - level
    - racecar
    - world

    Total Vowel Count: 13
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // For std::sort
#include <cctype>    // For std::tolower

// Function to check if a string is a palindrome
bool isPalindrome(const std::string &str) {
    int left = 0;
    int right = str.size() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Function to count vowels in a string
int countVowels(const std::string &str) {
    int vowelCount = 0;
    for (char ch : str) {
        char lowerCh = std::tolower(ch);
        if (lowerCh == 'a' || lowerCh == 'e' || lowerCh == 'i' || lowerCh == 'o' || lowerCh == 'u') {
            vowelCount++;
        }
    }
    return vowelCount;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "Error: No arguments provided. Please enter some strings as arguments." << std::endl;
        return 1;
    }

    // Store arguments in a vector (excluding argv[0])
    std::vector<std::string> args;
    for (int i = 1; i < argc; i++) {
        args.push_back(argv[i]);
    }

    // Step 1: Check for palindromes
    std::cout << "Palindromes:" << std::endl;
    for (const auto &arg : args) {
        if (isPalindrome(arg)) {
            std::cout << "  - " << arg << std::endl;
        }
    }

    // Step 2: Sort arguments lexicographically
    std::sort(args.begin(), args.end());
    std::cout << "\nSorted Arguments:" << std::endl;
    for (const auto &arg : args) {
        std::cout << "  - " << arg << std::endl;
    }

    // Step 3: Count total vowels
    int totalVowelCount = 0;
    for (const auto &arg : args) {
        totalVowelCount += countVowels(arg);
    }
    std::cout << "\nTotal Vowel Count: " << totalVowelCount << std::endl;

    return 0;
}
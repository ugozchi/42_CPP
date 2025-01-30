/*🔹 Exercise 5: The Number Guessing Game 🎲

🎯 Objective:

Create a number guessing game where:
	1.	The computer generates a random number between 1 and 100.
	2.	The user has to guess the number.
	3.	The program gives hints (“Too high” / “Too low”) after each wrong guess.
	4.	The game continues until the user guesses correctly.

📚 Key Concepts to Learn
	1.	Random Number Generation (rand() and srand())
	2.	Loops (while or do-while) to keep asking until the correct number is guessed.
	3.	User Input Validation (Making sure the input is a number).

💡 Hints for the Solution
	1.	Use rand() and srand(time(0)) to generate a random number.
	2.	Use a loop to keep asking the user for a guess.
	3.	If the guess is too high, print "Too high!".
	4.	If the guess is too low, print "Too low!".
	5.	When the user guesses correctly, print "Congratulations! You found the number." and exit.
*/

# include <iostream>
# include <random>

int main(void)
{
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);

	int	SecretNumber = dist(gen);

	std::cout << "The Number Guessing Game 🎲" << std::endl;
    std::cout << "Let me choose a number between 1 and 100\nTry to guess it!" << std::endl;

	int	guess;
	while (true) {
		std::cout << "Your guess :";
		std::cin >> guess;

		if (std::cin.fail()) {
			std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a valid number." << std::endl;
			continue ;
		}

		if (guess < SecretNumber) {
			std::cout << "Too low! try again." << std::endl;
		}
		else if (guess > SecretNumber) {
			std::cout << "Too high! Try again." << std::endl;
		}
		else {
			std::cout << "Congratulations! You found the number." << std::endl;
			break ;
		}
	}
	return 0;
}

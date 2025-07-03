#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int randomNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    cout << "Welcome to the Guessing Game!" << endl;
    cout << "I have generated a random number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    // Loop until the user guesses correctly
    do {
        // Ask the user to guess the number
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Increase the attempt count
        attempts++;

        // Check if the guess is too high, too low, or correct
        if (userGuess > randomNumber) {
            cout << "Your guess is too high. Try again!" << endl;
        } else if (userGuess < randomNumber) {
            cout << "Your guess is too low. Try again!" << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            cout << "It took you " << attempts << " attempts to guess the number." << endl;
        }
    } while (userGuess != randomNumber);

    return 0;
}
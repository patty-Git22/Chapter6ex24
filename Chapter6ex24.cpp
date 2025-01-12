/*
Title: Chapter 6 exercise 24: Rock, Paper, Scissors Game
File name: Chapter6ex24.cpp
Programmer: Patrick
Date: 11/23

Requirements: 
Write a program that lets the user play the game of Rock, Paper, Scissors against the computer.
The program should work as follows:
1. When the program begins, a random number in the range of 1 through 3 is generated. 
	If the number is 1, then the computer has chosen rock. If the number is 2, then the computer has chosen paper.
	If the number is 3, then the computer has chosen scissors. (Don�t display the computer�s choice yet.)
2. The user enters his or her choice of �rock�, �paper�, or �scissors� at the keyboard. (You can use a menu if you prefer.)
3. The computer�s choice is displayed.
4. A winner is selected according to the following rules:
  � If one player chooses rock and the other player chooses scissors, then rock wins. (The rock smashes the scissors.)
  � If one player chooses scissors and the other player chooses paper, then scissors wins. (Scissors cuts paper.
  � If one player chooses paper and the other player chooses rock, then paper wins. (Paper wraps rock.)
  � If both players make the same choice, the game must be played again to determine the winner.
Be sure to divide the program into functions that perform each major task.
*/

#include <iostream>
#include<random>
#include <cstdlib> 
#include <ctime>   

// Constant variables
const int ROCK = 1, PAPER = 2, SCISSORS = 3;

// Function Prototypes
int inputValidate(int);
int computerChoice(int);
int userChoice(int);
void displayRandomNumber(int);
void correctSelection(int, int, bool&);

int computer_choice, user_choice;

using namespace std;

int main()
{
    bool playAgain;

    do
    {
        computer_choice = computerChoice(computer_choice);

        user_choice = userChoice(user_choice);

        displayRandomNumber(computer_choice);

        correctSelection(computer_choice, user_choice, playAgain);

    } while (playAgain == 1);

} // END int main()

int computerChoice(int computer_choice)
{
    srand(0);

    return (rand() % (SCISSORS - ROCK + 1)) + ROCK;
}

int userChoice(int user_choice)
{
    cout << "\nChoose one of the following: \n1. Rock \n2. Paper \n3. Scissors\n";

    user_choice = inputValidate(user_choice);

    return user_choice;
}

int inputValidate(int num1)
{

    while (!(cin >> num1) || (num1 < 1 || num1 > 3))
    {
        cout << "Error. Number must be 1, 2, or 3";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return num1;
}

void displayRandomNumber(int computer_choice)
{
    cout << "\nComputer Choice is = ";

    if (computer_choice == 1)
        cout << "Rock";
    else if (computer_choice == 2)
        cout << "Paper";
    else if (computer_choice == 3)
        cout << "Scissors";

    cout << endl;
}

void correctSelection(int computer_choice, int user_choice, bool & playAgain)
{
    cout << endl;

    if (computer_choice == ROCK)
    {
        if (user_choice == PAPER)
        {
            cout << "You win! Paper beats rock.\n";
            playAgain = 0;
        }
        else if (user_choice == SCISSORS)
        {
            cout << "Computer wins! Rock beats scissors.\n";
            playAgain = 0;
        }
        else if (user_choice == ROCK)
        {
            cout << "It's a tie. Play again to determine the winner." << endl;
            playAgain = 1;
        }
    }
    else if (computer_choice == PAPER)
    {
        if (user_choice == ROCK)
        {
            cout << "Computer wins! Paper beats rock.\n";
            playAgain = 0;
        }
        else if (user_choice == SCISSORS)
        {
            cout << "You win! Scissors beats paper.\n";
            playAgain = 0;
        }
        else if (user_choice == PAPER)
        {
            cout << "It's a tie. Play again to determine the winner." << endl;
            playAgain = 1;
        }
    }
    else if (computer_choice == SCISSORS)
    {
        if (user_choice == ROCK)
        {
            cout << "You win! Rock beats scissors.\n";
            playAgain = 0;
        }
        else if (user_choice == PAPER)
        {
            cout << "Computer wins! Scissors beats paper.\n";
            playAgain = 0;
        }
        else if (user_choice == SCISSORS)
        {
            cout << "It's a tie. Play again to determine the winner." << endl;
            playAgain = 1;
        }
    }
 
}
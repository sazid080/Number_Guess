//
//  main.cpp
//  Number_Guess
//
//  Created by MOHAMMAD SAZID on 31/07/25.
//

using namespace std;

#include <iostream>
#include <cmath>
#include <cstdlib> // For rand() and srand()
#include <ctime>

void intro(){
    cout << "Welcome to the number guessing game."<< endl;
    cout << "I am thinking of a number between 1 and 100." << endl;
    cout << "Please select difficulty level: " << endl;
    cout << "1. Easy (10 chances)"<<endl
         << "2. Medium (5 chances)"<<endl
         << "3. Hard (3 chances)"<<endl;
}

int difficulty(){
    int difficultLvl;

    while(true){
        cout << "Enter your choice (1 to 3): " << endl;
        cin >> difficultLvl;
        
        if(difficultLvl <= 0 || difficultLvl > 3){
            cin.clear();
            cin.ignore();
            cout << "Invalid, choose again"<< endl;
            continue;
        }else if(difficultLvl == 1){
            cout << "Great! You have selected Easy difficulty." << endl << "Lets start the game!" << endl;
        }else if(difficultLvl == 2){
            cout << "Great! You have selected Medium difficulty." << endl << "Lets start the game!" << endl;
        }else{
            cout << "Great! You have selected Hard difficulty." << endl << "Lets start the game!" << endl;
        }
        return difficultLvl;
    }
}

int Random(){
    srand(static_cast<unsigned int>(time(0)));
    int randomNum = (rand() % 100) + 1;
    return randomNum;
}

void playGame(){
    int attempts = 0;
    int maxAttempts = 0;
    int min = 1;
    int max = 100;
    int guessed = 0;
    
    int difficultyChoice = difficulty();
    
    if(difficultyChoice == 1){
        maxAttempts = 10;
    }else if(difficultyChoice == 2){
        maxAttempts = 5;
    }else{
        maxAttempts = 3;
    }
    
    int secretNum = Random();
    
    while(attempts <= maxAttempts) {
        
        cout << "Attempts left: " << (maxAttempts - attempts) << endl;
        cout << "Enter your guess: " << endl;
        cin >> guessed;
        
        if(guessed < min || guessed > max){
            cout << "Invalid input! Please choose between " << min << " and " << max << endl;
            continue;
        }
        
        attempts++;
        
        if(guessed < secretNum){
            cout << "Incorrect! The number is greater than " << guessed << endl;
        }else if(guessed > secretNum){
            cout << "Incorrect! The number is smaller than " << guessed << endl;
        }else{
            cout << "Congratulations! You guessed the correct number in "  << attempts << " attempts" << endl;
            return;
        }
    }
    
    if(attempts > maxAttempts){
        cout << "The number is: " << secretNum << endl;
        return;
    }
    
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    intro();
    playGame();
    return 0;
}

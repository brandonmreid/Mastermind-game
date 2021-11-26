#include <string>
#include <array>
#include <time.h>
#include <iostream>
#include <string.h>
#include "functions.h"

bool DEBUG = false;

using namespace std;


void welcome() {
    cout << "Welcome to the Mastermind game" << endl << endl
         << "Default rules" << endl <<
            "=============" << endl <<
             "* 4 pegs in guess/solution" << endl <<
             "* 6 colors to choose from" << endl <<
             "* Pegs in guess/solution must be colored differently" << endl <<
             "* If you or computer makes 4 correct choices the game is over." << endl << endl;  
}

int playSequence1() { // if user chooses to be code maker
    string * code = generateCode();
    string * guess;
    int roundCount = 0;
    int sameColorAndPosition = 0;
    int sameColorWrongPosition = 0;

    while(roundCount < 12) {
        sameColorAndPosition = 0;
        sameColorWrongPosition = 0;
        cout << endl << "======Round " << roundCount + 1 << "======" << endl;
        guess = enterGuess();

        
        if (DEBUG) {
            cout << "   Guess             Code" << endl;
            for(int i = 0; i < 4; i++) {
                cout << guess[i] << "       " << code[i] << endl;
            }
        }

        for (int i = 0; i < 4; i++) { // checks to find matching beps and positions
            for (int k = 0; k < 4; k++) {                   
                if (guess[i] == code[k]) {                        
                    if (i == k) {
                        sameColorAndPosition++;
                    } else {
                        sameColorWrongPosition++;
                    }
                }

            }
        }           
        cout << endl << "====Summary====" << endl << "Same color and position: " << sameColorAndPosition << endl;
        cout << "Same color wrong position: " << sameColorWrongPosition << endl;
        if (sameColorAndPosition == 4) {
            cout << endl << "=======Congratulations! You won the game!======" << endl;
            return 0;
        } else {
            roundCount++;
        }
        // check each stop for either right position or right right color then output number of pegs
    } 

    cout << "Game Over.....You have used all 12 guesses. " << endl
            << "The solution was:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << code[i] << endl;
    }

    return 0;   

}



int playSequence2() {  // if user chooses to be code breaker
    string * code = userMakesCode();
    string * guess;
    int roundCount = 0;
    int sameColorAndPosition = 0;
        int sameColorWrongPosition = 0;

    //srand (time(NULL)); 
    int randomNum = 0;
    int randomNums[4];       
    string* compGuess;
    compGuess = new string[4];    

    while(roundCount < 12) {
        sameColorAndPosition = 0;
        sameColorWrongPosition = 0;

        for (int i = 0; i < 4; i++) {
            randomNum = rand() % 6;
            randomNums[i] = randomNum;                
        }

        for(int i = 0; i < 4; i++){

            switch(randomNums[i]) {       
                    case 0:
                        compGuess[i] = "red";
                        break;    
                    case 1:
                        compGuess[i] = "green";
                        break;        
                    case 2:
                        compGuess[i] = "blue";
                        break;
                    case 3:
                        compGuess[i] = "yellow";
                        break;
                    case 4:
                        compGuess[i] = "white";
                        break;
                    case 5:
                        compGuess[i] = "orange";
                        break;
            }
        
        }

        cout << endl << "======Round " << roundCount + 1 << "======" << endl               
            << "The computer guessed: " << compGuess[0] << " ," << compGuess[1] << " ," << compGuess[2] << " ," <<compGuess[3] << endl;
        
        
        if (DEBUG) {
            cout << "   Guess             Code" << endl;
            for(int i = 0; i < 4; i++) {
                cout << compGuess[i] << "       " << code[i] << endl;
            }
        }

        for (int i = 0; i < 4; i++) { // checks to find matching beps and positions
            for (int k = 0; k < 4; k++) {                   
                if (compGuess[i] == code[k]) {                        
                    if (i == k) {
                        sameColorAndPosition++;
                    } else {
                        sameColorWrongPosition++;
                    }
                }

            }
        }

        if (DEBUG) {
            cout << endl << "Same color and position: " << sameColorAndPosition << endl
                << "Same color wrong position: " << sameColorWrongPosition << endl;

        }

        
        if (sameColorAndPosition == 4) {
            cout << endl << "=========Tough Luck! The computer guessed your code. Game over...======" << endl;
            return 0;
        } else {
            roundCount++;

        }
        // check each stop for either right position or right right color then output number of pegs

        
    }

            
            cout << endl << "Game Over.....The computer used all its guesses and your *Master code* won the game! " << endl
                << "You code was:" << endl;
            for (int i = 0; i < 4; i++) {
                cout << code[i] << endl;
            }  
    return 0; 

}    

           
// initialize random seed and generate random color code
string *generateCode(){

  string* code;
  code = new string [4];
  int codeNums [4];
  int randomNum;
  
  srand (time(NULL)); 
  int randomNumSize = 0;

    for(int i = 0; i < 4; i++) { //generate 4 unique colors       
        bool check; 
        
        do {
            randomNum = rand() % 6;
            check = true;   
            if (DEBUG){         
                cout << endl <<  "Iteration " << i << " Comparing " << randomNum << " and " << codeNums[i] << endl;
            }
            for (int j = 0; j < i; j++) {
                if (randomNum == codeNums[j]) {
                    check = false;
                    break;
                }
            }        
        } while (!check);
        codeNums[i] = randomNum;
            
    }    
  
if (DEBUG) {
  cout << endl << "Code: " << codeNums[0] << " " <<  codeNums[1]  << " " << codeNums[2] << " " << codeNums[3]  << "end" << endl;
}

  //0 == red
  //1 == green
  //2 == blue
  //3 == yellow
  //4 == white
  //5 == orange 

  for(int i = 0; i < 4; i++){

   switch(codeNums[i]) {       
        case 0:
            code[i] = "red";
            break;    
        case 1:
            code[i] = "green";
            break;        
        case 2:
            code[i] = "blue";
            break;
        case 3:
            code[i] = "yellow";
            break;
        case 4:
            code[i] = "white";
            break;
        case 5:
            code[i] = "orange";
            break;
   }

  

  } 
  if (DEBUG) {
      cout << "Unique colors: " << code[0] << "1 " << code[1] << "2 " << code[2] << "3 " << code[3] << "4 end" << endl;
  }

  return code;

}



int playChoice () {
    int input;
    do {
        cout << "Would you like to be the code breaker(1) or code maker(2)? ";
        if (!(cin >> input)) { // validates that numbers were entered and checks input
            cerr << "Error! Please enter a valid integar." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue; 
        }
        if (input == 1) {
            cout << endl << "You've chosen to be the code breaker!" << endl;
            return input;
        } else if (input == 2) {
            cout << endl << "You've chose to be the code maker!" << endl;
            return input;
        } else {            
            cerr << "Error! Invalid Input. Please try again." << endl;
        }
    } while (true);
}


 //1 == red
  //2 == green
  //3 == blue
  //4 == yellow
  // 5 == white
  // 6 == orange 

string *enterGuess() {
    string* guess;
    guess = new string[4];
    string guess1 = "";
   

    cout << "Please write your guess in all lowercase" << endl << endl;
    //update to push peg string array onto linked list
    for (int i = 0; i < 4; i++) { 
        do {       
            cout << "What color would you like to guess for peg " << i + 1 << "? ";
            cin >> guess1;
            if (guess1 == "red" || guess1 == "green" ||  guess1 == "blue" ||  guess1 == "yellow" || guess1 == "white" ||  guess1 == "orange") {
                guess[i] = guess1;
                break;
            } else {
                cout << "Error! Invalid string input. Please try again" << endl;
            }

        } while (true);
    }
   
    return guess;

}

string *userMakesCode() {
    string* code;
    code = new string[4];
    string guess = "";

    for (int i = 0; i < 4; i++) { 
        do {       
            cout << "What color would you like to select for peg " << i + 1 << "? ";
            cin >> guess;
            if (guess == "red" || guess == "green" ||  guess == "blue" ||  guess == "yellow" || guess == "white" ||  guess == "orange") {
                code[i] = guess;
                break;
            } else {
                cout << "Error! Invalid string input. Please try again" << endl;
            }

        } while (true);
    }

    return code;

}

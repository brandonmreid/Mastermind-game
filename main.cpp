#include <iostream>
#include <any>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>     
#include <time.h>
#include <string>
#include <array>
//#include "functions.h"
#include "functions.cpp"
using namespace std;

int main () {
    // variables
    string* code;
    string* guess;
    int choice = 9;
   
    welcome();

    choice = playChoice(); 


    if (choice == 1) { // if user chooses to be code maker
        playSequence1(); 
                     
    } else { // if user chooses to be code breaker
        playSequence2();

    }
}
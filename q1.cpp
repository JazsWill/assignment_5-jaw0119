#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

// Assignment 5 - Exercise 1

void grammarly(char sentence[])
{  
    // Capitalize the first letter of the sentence
    if (sentence[0] != ' ')
    {
        sentence[0] = toupper(sentence[0]);
    }

    for (int i = 0; i < 100; i++)
    {
        // Ignore extra spaces
        if ((sentence[i] == ' ') && (sentence[i + 1] == ' '))
        {
            continue;
        }
        
        // Force lowercase letters for the remaining characters
        if (i > 0)
        {
            sentence[i] = tolower(sentence[i]);
        }
    }
    cout << "OUTPUT: " << sentence;
}

int main()
{
    // Assignment 5 - Exercise 1

    char sentence[100], choice1;
    cout << "Exercise 1\n";
    cout << "Input sentence (No more than 100 characters): ";
    cin.getline(sentence, 100);
    grammarly(sentence);

    return 0;
}

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

void cupid(char text[])
{
    int length = 0;
    for (int i = 0; i < 100; i++)
    {
        // Increase 'length' when a letter is idenitified
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            length++;
        }

        if (text[i] >= 'A' && text[i] <= 'Z')
        {
            length++;
        }
        
        // Check for length of word after a space is identified
        if ((text[i] == ' ')||(text[i] == '\0'))
        {
            // If four-letter word, replace with 'Love' || 'love'
            if (length == 4)
            {
                if (isupper(text[i - 4]))
                {
                    text[i - 4] = 'L';
                }
                else
                {
                    text[i - 4] = 'l';
                }
                
                text[i - 3] = 'o';
                text[i - 2] = 'v';
                text[i - 1] = 'e';              
            }
            length = 0;
        }
    }
    cout << "OUTPUT: " << text;
}

int main()
{
  // Assignment 5 - Exercise 2

    char text[100];
    cout << "Exercise 2\n";
    cout << "Input sentence into Love Generator: ";
    cin.getline(text, 100);
    cupid(text);
  
    return 0;
}

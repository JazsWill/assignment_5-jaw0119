#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

int main()
{
  // Assignment 5 - Exercise 4

    char choice4;
    int ch, count = 0;
    string answers, question;
    //char question[100];
    fstream fileAnswers("answers.txt");
    cout << "Exercise 4\n";

    do
    {
        // Check to see if file failed to open
        if (fileAnswers.fail())
        {
            cout << "ERROR Opening File!!\n";
            break;
        }
        else
        {
            cout << "Enter your question: " << endl;
            cin >> question;
            fileAnswers.open("answers.txt");
            if (fileAnswers.is_open())
            {
                while (getline(fileAnswers, answers))
                {
                    cout << answers << "\n";
                }
            }

            if (fileAnswers.eof())
            {
                fileAnswers.close();
            }
        }
        
        cout << "Do you want to continue?(Y/N): ";
        cin >> choice4;
    } while (choice4 == 'y' || choice4 == 'Y');
    
    return 0;
}

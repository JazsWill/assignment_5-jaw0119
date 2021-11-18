#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cctype>
#include <cmath>
using namespace std;

// Assignment 5 - Exercise 3

void mergeFiles(ifstream& in1, ifstream& in2, ofstream& out1)
{
    int i, j, k, m, n, count1 = 0, count2 = 0;
    int InArr1[50], InArr2[50], OutArr[100];
    
    i = 0;
    // Read file1 and store integers into array
    while (in1 >> m)
    {
        InArr1[i] = m;
        i++;
    }
    count1 = i; // Size of array for file1

    j = 0;
    // Read file2 and store integers into array
    while (in2 >> n)
    {
        InArr2[j] = n;
        j++;
    }
    count2 = j; // Size of array for file2

    i = 0; j = 0; k = 0;
    // Merge both arrays
    while (i < count1 && j < count2)
    {
        if (InArr1[i] <= InArr2[j])
        {
            OutArr[k] = InArr1[i];
            i++;
        }
        else
        {
            OutArr[k] = InArr2[j];
            j++;
        }
        k++;

        if (i < count1)
        {
            for (int c = i; c <= count1; c++)
            {
                OutArr[k] = InArr1[c];
                k++;
            }
        }
        else
        {
            for (int d = j; d <= count2; d++)
            {
                OutArr[k] = InArr2[d];
                k++;
            }
        }

    }

    for (int z = 0; z < k; z++)
    {
        out1 << OutArr[z] << " ";
    }
}

void openFile(const char* fileName)
{
    ifstream file(fileName);
    int tmp;

    if (file)
    {
        cout << "Opening file... '" << fileName << "'\n";
        while (file >> tmp)
        {
            cout << setw(7) << tmp << " ";
        }
        file.close();
        cout << endl;
    }
    else
    {
        cout << "ERROR!! There was a problem opening the file: " << fileName << endl;
    }
}

int main()
{
    // Assignment 5 - Exercise 3

    // Create two input files and output file
    cout << "Exercise 3\n";
    ifstream inFile1("file1.txt");
    ifstream inFile2("file2.txt");
    ofstream outFile("file3.txt");

    if (!inFile1 || !inFile2)
    {
        cout << "The file isn't an input file.\n";
        exit(1);
    }

    mergeFiles(inFile1, inFile2, outFile);
    outFile.close();
    openFile("file1.txt");
    openFile("file2.txt");
    openFile("file3.txt");
  
    return 0;
}

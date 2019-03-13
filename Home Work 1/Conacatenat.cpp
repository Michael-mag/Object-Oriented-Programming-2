/*
CH08-320143
a1 p2.cpp
Michael Magaisa
m.magaisa@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    int n, i;
    char filename[50];
    char ch;
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> filename;
        ifstream input(filename);
        //opening file in append mode
        ofstream output("concat.txt", ios::app);
        //Checking of files were succesfully opened
        if(!input.good() || !output.good())
        {
            cerr << "Error opening file " << filename << endl;
            exit (1);
        }
        //Reading character ny character
        while(input.get(ch))
        {
            output << ch;
        }

        /*  Closing files to prevent data corruption
            and to save the content
        */
        input.close();
        output.close();
    }

    return 0;
}

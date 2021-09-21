#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include "myfunction.h"

using namespace std;
//function defenition 
void binarySearch( vector <string> list, string searchString, int len);
//declaring variables 
int positionFound;
int steps;

// main function with command line arguments 
int main(int argc, char** argv)
{

    /*for (int i = 0; i < argc; ++i)
        cout << argv[i] << "\n";*/

// creating a vector called list 
    vector<string> list;
    int count=0; // counter to keep track of the comparisons made 

    string filename="Dictionary466544words.txt";
    int wordstoprint=5;

    /*if (argc==5) {
        filename=argv[2];
        wordstoprint=atoi(argv[4]);
    }*/

    //command line arguments
    for(int i=1; i<argc; i++)
    {
        if(string(argv[i])=="-d" && i+1 < argc)
            filename= argv[i+1];

        if(string(argv[i])=="-l" && i+1 < argc)
            wordstoprint= atoi(argv[i+1]);
    }


    ifstream fin(filename);

    if(fin.fail()) // if the file cannot be opened
    {
        cout<< "Cannot open"<<filename<<endl;
        return EXIT_FAILURE;
    }

    //reading from the file and storing it in a vector
    do
    {
        string input;
        fin>>input;
        list.push_back(input);
    }

    while (fin);
//main while loop 
    while(true)
    {
        string searchString;
        cout<<"Please enter the word:"; //asks user to enter the word he/she would like to search for 
        cin>>searchString;

        if (searchString=="exit" or searchString=="quit") // if the user types exit or quit, the program terminates 
            return EXIT_SUCCESS;

        //saves the position of the * and the ? in integers x and y 

        int x=searchString.find("*"); //A word with *
        int y=searchString.find("?"); //A word with ?


        if (x>0 && x<searchString.length()) {
            //Search
            string prefix= searchString.substr(0,x); // the prefix is everything before the position of the *

            positionFound=-1;
            binarySearch(list, prefix, x); // calling the binary search function on the prefix search 

            int i=positionFound;
            int numEntries=0; // numEnties for the matches found set to 0 

            vector<string> wordsFound; //creating another vector to store the words found 

// while the substring of the word found matches the prefix, the words matching will increase 
            while (list[i].substr(0,x)==prefix) {
                numEntries++;
                if (numEntries<=wordstoprint) wordsFound.push_back(list[i]); // we are pushing the words found to the list 
                i++;
            }
// print the words found and the number of matches 
            cout<<numEntries<<" matches found\n";
            for (i=0;i<wordsFound.size();i++) {
                cout<<wordsFound[i]<<"\n";
            }

            cout<<steps<<" word comparisons up-to the first match\n";

            // this is the case for searching with a "?"

        }
        else if (y>=0 && y<searchString.length()) {
            //Search for prefix from 0 to the location of the "?"

            string prefix= searchString.substr(0,y);
            // suffix is set to be ther letterss after the "?"
            string suffix= searchString.substr(y+1,searchString.length());
// same logic as the "*" search 
            positionFound=-1;
            binarySearch(list, prefix, y);

            int i=positionFound;
            int numEntries=0;

            vector<string> wordsFound;

            while (list[i].substr(0,y)==prefix) {

                if (list[i].substr(y+1,list[i].length())==suffix) {
                    steps++;
                    numEntries++;
                    if (numEntries<=wordstoprint) wordsFound.push_back(list[i]);

                }

                i++;
            }

            cout<<numEntries<<" matches found\n";
            for (i=0;i<wordsFound.size();i++) {
                cout<<wordsFound[i]<<"\n";
            }

            cout<<steps<<" word comparisons executed\n";

        }
        else {


            positionFound=-1;
            binarySearch(list, searchString, searchString.length());
            if (positionFound!=-1)
                cout << "Your keyword is found: " <<list[positionFound]<<" in "<<steps<<" steps"<<endl;
            else
                cout << "Your keyword is not found"<<endl;
        }

    }

    return EXIT_SUCCESS;
}




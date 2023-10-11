#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    ifstream fin;
    string line;
    ofstream out_file; // o is for writing
    out_file.open("output.txt"); //for appending ios:app
    //out_file << "new line" << endl; //overrides
  
    try //error handling
    {
        fin.open("input.txt"); //in a try block incase the file does not exist
        if(!fin) 
        {
            throw string("file does not exist");
        }
    }
    catch(string err)
    {
        cout<<err; //error gets thrown
    }

    int userin;
    cout << "Enter 1 to capitalize the entire line " << endl;
    cout << "Enter 2 to lowercase the entire line " << endl;
    cout << "Enter 3 to remove all punctuations and numbers " << endl;
    cin >> userin;

    while(getline(fin,line)) // traversing through test.txt
    {
       
    //cout << line << endl;
   
    char currentletter; //placeholder
    
    if (userin == 1)
    {
        for (char a: line) // traverse through each line
            {
                if(islower(a))
                    { 
                        currentletter = char(toupper(a)); //change to uppercase
                        out_file << currentletter;
                    }   
                else
                    {
                        out_file << a; //print all non-alpha characters
                    }
            }

    }

    if (userin == 2)
    {
        for (char a: line) // traverse through each line
            {
                if(isupper(a))
                    { 
                        currentletter = char(tolower(a)); //change to uppercase
                        out_file << currentletter;
                    }   
                else
                    {
                        out_file << a; //print all non-alpha characters
                    }
            }

    }

    if (userin == 3)
        for(char a: line)
        {
            if(isalpha(a))
            {
                out_file << a;
            }
        }
  
        out_file << endl;

    }
    fin.close();
    out_file.close();
}
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    string newfile = argv[1];

    ifstream fin;
    string line;
    ofstream out_file; // o is for writing
    out_file.open(newfile); //for appending ios:app
    //out_file << "new line" << endl; //overrides
  
    try //error handling
    {
        fin.open("test.txt"); //in a try block incase the file does not exist
        if(!fin) 
        {
            throw string("file does not exist");
        }
    }
    catch(string err)
    {
        cout<<err; //error gets thrown
    }

    while(getline(fin,line)) // traversing through test.txt
    {
       
    //cout << line << endl;
    char currentletter; //placeholder
     for (char a: line) // traverse through each line
     {
        if (isupper(a))
        {
            currentletter = char(tolower(a)); //change to lowercase
            out_file << currentletter;
        }
        else if(islower(a))
        { 
            currentletter = char(toupper(a)); //change to uppercase
            out_file << currentletter;
        }
        else
        {
            out_file << a; //print all non-alpha characters
        }
       // out_file << a;
     }
     out_file << endl; // match the lines in test.txt
     //cout << endl;

    }
    fin.close();
    out_file.close();
}
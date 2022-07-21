// 20000111 - M.A.D.V.S.ANAWARATHNA

#include<iostream> 
#include<fstream> 
#include<string>
#include<vector> 
#include<cctype>

using namespace std;

vector<string> moduleLinesArray;  // create a dynamic array(vector)
int numberOfMatching = 0; 

void moduleRead()
{
    fstream myFile;
    myFile.open("modules.txt",ios::in); //open the modules.txt file to read
    if(myFile.is_open()) 
    {
        string line;
        while(getline(myFile,line)) // read the modules.txt file, until end of the file
        {
            moduleLinesArray.push_back(line);  // read lines one by one and push to the dyanamic array 
        }
        myFile.close();
    }
}



char swapCaseofChar(char character)
{
    if(islower(character))
        character = char(toupper(character));
    else
        character = char(tolower(character));

    return character;
}



int matchingAlgo(string text, string pattern)
{
    int i = 0,j = 0,charMatchingTime = 0;

    if(text.length() < pattern.length())
    {
        return numberOfMatching;
    }
    // text checking loop
    for (i = 0; i < text.length(); i++)
    {
        // pattern checking loop
        for (j = 0; j < pattern.length(); j++)
        {
            // check the pattern character is equal to text character and remove the case sensitive
            if( pattern[j] == text[i] || pattern[j] == swapCaseofChar(text[i])  )
            {
                i++;
                charMatchingTime++;
            }
            else if( pattern[j] != text[i] || pattern[j] != swapCaseofChar(text[i]) )
            {
                charMatchingTime = 0;  // if there is no consecutive time pattern matching time then charMatchingTime = 0
                break;
            }
        }

        // if charMatchingTime isq equal to pattern length, that's means pattern is found in the string
        if(charMatchingTime == pattern.length() )
        {
            numberOfMatching++;
            cout << text <<endl;
            break;
        }
    }
}



// drive function
int main()
{
    cout<<endl;
    moduleRead();   // call moduleRead function for reading the modules.txt file
    string searchString;
    cout << "Enter a search string: "; 
    cin >> searchString;

    for( const auto &value: moduleLinesArray)
    {
        string text = value;
        matchingAlgo(text,searchString);
    }
    
    cout << "Number of matches: " << numberOfMatching;


    cout << endl;
    return 0;
}

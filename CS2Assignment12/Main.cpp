#include "BinarySearch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
void DriverCode();
int main()
{
    DriverCode();

    system("pause");
    return 0;
}
void DriverCode()
{
    //READ IN DICTIONARY
    fstream fin ("dictionary.txt");
    vector<string> wordHolder;
    string word;

    //PUT INTO VECTOR
    while(!fin.eof())
    {
        fin>>word;
        if(word != "")
        {
            wordHolder.push_back(word);
        }        
    }
        
    //RANDOMIZE
    random_shuffle (wordHolder.begin(), wordHolder.end());

    //PLACE IN TREE
    BinarySearch tree;
    for(unsigned int i =0; i<wordHolder.size(); i++)
    {
        tree.Insert(wordHolder.at(i)); 
    }

    //REPORT SIZE AND HEIGHT
    cout<<"The size of the binary tree is: "<<tree.Size()<<endl<<endl;
    cout<<"The height of the binary tree is: "<<tree.Height()<<endl<<endl;

    //READ IN THE LETTER
    fin.close();
    fin.open("letter.txt");
    vector<string> letterWords;
    string letWord;
    while(!fin.eof())
    {
        fin>>letWord;
        char parseWord;
        for(unsigned int i=0; i<letWord.size(); i++)
        {
            parseWord = letWord[i];

            //REMOVE ILLEGAL CHARACTERS
            if(parseWord != '"' && parseWord != ',' && parseWord != ':' && parseWord != '!' && parseWord != '?' && parseWord != '(' && parseWord != ')' && parseWord != '.')
            {
                letWord[i] = parseWord;
            }else
            {
                letWord[i] = NULL;
            }
        }
        letterWords.push_back(letWord);
    }

    //LOOP THROUGH LETTER VECTOR CHECKING FIND
    bool found;
    string tempWord;
    char parsed;
    for (unsigned int i=0; i<letterWords.size(); i++)
    {
        tempWord = letterWords.at(i);

        //SWITCH TO LOWER
        for(unsigned int j=0; j<tempWord.size(); j++)
        {
            parsed = tolower(tempWord[j]);
            tempWord[j] = parsed;
        }
        found = tree.Find(tempWord);
        if(!found)
        {
            cout<<"The word: "<<letterWords.at(i)<<" is misspelled."<<endl;
        }
    }
    //TEST PUBLIC FUNCTIONS WITH 10 NODE TREE
    //INSERT
    cout<<"Testing the insert function with a random 10 node tree: "<<endl;
    BinarySearch tester;
    for( int i=0; i<10; i++)
    {
        tester.Insert(wordHolder.at(i));
    }
    tester.Display();

    //FIND
    found = tester.Find(wordHolder.at(3));
    cout<<"Check for a word that IS in the tree (should be 1): "<<found<<endl;
    found  = tester.Find(wordHolder.at(500));
    cout<<"Check for a word that is NOT in the tree (should be 0): "<<found<<endl;

    //SIZE
    cout<<"The size of the tree should be ten. It is: "<<tester.Size()<<endl;

    //HEIGHT
    cout<<"The height of the tree is: "<<tester.Height()<<endl;
}
#include "BinarySearch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
void DriverCode();
int main(){
    BinarySearch first;
    
    //INSERT
    first.Insert("math");
    first.Insert("zebras");
    first.Insert("apple");
    first.Insert("appl");
    first.Insert("app");
    first.Insert("ap");
    first.Insert("sappy");
    
    //FIND
    cout<<"Should be 1"<<endl<<first.Find("apple")<<endl;
    cout<<"Should be 0"<<endl<<first.Find("apes")<<endl;
    
    //COPY CONSTRUCTOR
    BinarySearch second(first);
    cout<<"Should be 1"<<endl<<second.Find("math")<<endl;
    cout<<"Should be 0"<<endl<<second.Find("me")<<endl;

    //SIZE
    cout<<"Should be 7: "<<endl<<first.Size()<<endl;

    //HEIGHT
    cout<<"Should be 4: "<<endl<<first.Height()<<endl;
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
        wordHolder.push_back(word);
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
        cout<<letWord<<" ";
    }
    //LOOP THROUGH LETTER VECTOR CHECKING FIND
    bool found;
    for( unsigned int i=0; i<letterWords.size(); i++)
    {
        found = tree.Find(letterWords.at(i));
        if(!found)
        {
            cout<<"The word: "<<letterWords.at(i)<<" is misspelled."<<endl;
        }
    }
}
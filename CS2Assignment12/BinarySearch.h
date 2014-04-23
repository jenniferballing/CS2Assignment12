#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H
#include <string>
using namespace std;

class TreeNode
{
public:
    string name;
    TreeNode *ptrLeft, *ptrRight;

    TreeNode();
    TreeNode(string n);
};

class BinarySearch
{
private:
    TreeNode* root;

public:
    BinarySearch();
    BinarySearch(BinarySearch &obj);   
    void Insert (string n);
    bool Find (string n);
    int Size ();
    int Height ();
    void Display();
    ~BinarySearch();
private:
    void RCopy(TreeNode*& , TreeNode*&);
    void RInsert (string n, TreeNode*& ptr);
    bool RFind (string n, TreeNode*& ptr);
    int RSize (TreeNode*& ptr);
    void RDisplay (TreeNode*& ptr);
    int RHeight (TreeNode*& ptr);   
};
#endif


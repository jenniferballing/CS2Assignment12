#include "BinarySearch.h"

//TREENODE CONSTRUCTORS
TreeNode::TreeNode()
{
    ptrLeft = NULL;
    ptrRight = NULL;
}
TreeNode::TreeNode(string n)
{
    name = n;
    ptrLeft = NULL;
    ptrRight = NULL;
}

//BINARYSEARCH CONSTRUCTORS
BinarySearch::BinarySearch()
{
   root = NULL;
}
BinarySearch :: BinarySearch(BinarySearch &obj)
{
    if(obj.root == NULL) root = NULL;
    else RCopy(root, obj.root);
}

//NORMAL
void BinarySearch::Insert (string n)
{
    RInsert( n, root);
}
bool BinarySearch::Find (string n)
{
    return RFind(n, root);
}
int BinarySearch::Size ()
{
    if(root == NULL) return 0;
    return RSize (root);
}
int BinarySearch::Height ()
{
    return RHeight(root);
}
void BinarySearch::Display()
{
    RDisplay(root);
}

//RECURSIVE
void BinarySearch::RCopy(TreeNode*& thisRoot, TreeNode*& sourceRoot)
{
     if(sourceRoot == NULL) thisRoot = NULL;
     else
     {
         thisRoot = new TreeNode;
         thisRoot->name = sourceRoot->name;
         RCopy(thisRoot->ptrLeft, sourceRoot->ptrLeft);
         RCopy(thisRoot->ptrRight, sourceRoot->ptrRight);
     }
}
void BinarySearch::RInsert (string n, TreeNode*& ptr)
{
    if(ptr == NULL)
    {
        ptr = new TreeNode(n);
    }else
    {
        if(n <= ptr->name)
        {
            RInsert (n, ptr->ptrLeft);
        }else
        {
            RInsert (n, ptr->ptrRight);
        }
    }
}   
bool BinarySearch::RFind (string n, TreeNode*& ptr)
{
    if(ptr == NULL){return false;}
    else if (ptr->name == n) {return true;}
    else
    {
        if(n <= ptr->name)
        {
            return RFind (n, ptr->ptrLeft);
        }else
        {
            return RFind (n, ptr->ptrRight);
        }
    }    
}
int BinarySearch::RSize (TreeNode* &ptr)
{
    if(ptr == NULL) return 0;
    return 1+(RSize(ptr->ptrLeft))+(RSize(ptr->ptrRight));
}
int BinarySearch::RHeight (TreeNode*& ptr)
{
    int l = ptr->ptrLeft ? RHeight(ptr->ptrLeft) : 0;
    int r = ptr->ptrRight ? RHeight(ptr->ptrRight) : 0;
    if(ptr == root)
    {
        return max(l, r);
    }
    return 1+max(l, r);
}
void BinarySearch::RDisplay (TreeNode*& ptr)
{

}
BinarySearch::~BinarySearch()
{
    delete root;
}

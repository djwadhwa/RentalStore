// ------------------------------------------------ BinTree.h -------------------------------------------------------
// Tarcisius Daniel Hartanto CSS 343
// Start: Sunday, January 28 2019
// Date of Last Modification : Sunday, Feb 3 2019
// --------------------------------------------------------------------------------------------------------------------
// This is the header file for BinTree class
// --------------------------------------------------------------------------------------------------------------------
// 
// ------------------------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <memory>

using namespace std;
template <class ItemType>
class BinTree {

	/**
	 * << operator overload
	 * @param outStream all that will be printed in the cout
	 * @param &tree the tree that will be printed
	 * @ret outStream the printed state
	 */
	friend ostream& operator<<(ostream& outStream, const BinTree &tree)
	{
		if (tree.root == NULL)
		{
			outStream << "There is no node in this tree.";
		}
		else
		{
			tree.printHelper(outStream, tree.root); 
		}
		return outStream;
	} 

public:

 	//constructors and destructor
	BinTree();							
	BinTree(const BinTree &);			
	~BinTree();							

 	//methods
	bool isEmpty() const;	 
	void makeEmpty();		   	  
	int getHeight(const ItemType &) const;
	bool insert(ItemType *);
	bool retrieve(const ItemType &, ItemType *&) const; 
	void displaySideways() const;  
	void bstreeToArray(ItemType* []);    
    void arrayToBSTree(ItemType* []);	  
	
 	//"=" operator overload
	BinTree& operator=(const BinTree &);			
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;

private:
	//Node class
	struct Node{
		ItemType* data;			
		Node* left;				
		Node* right;				
	};
	Node * root;   // the root Node for the tree

 	//Private recursive helper methods
	void helpEmpty(Node*);	// helper for makeEmpty()
	void retrieveHelper(Node*, const ItemType & , ItemType*&) const;	// helper for retrieve()
	void bstreeToArrayHelper(Node * , ItemType* [], int& );    // helper for bstreeToArray()
	void arrayToBSTreeHelper(Node *& , ItemType * [], int , int ); // helper for arrayToBSTree()
	void copyNodes(Node*, Node*&); // copy all Nodes from a tree
	void printHelper(ostream& outStream, Node* curr) const; // helper for <<
	bool checkBothBST(Node*, Node*) const; // helper for "==" operator overload
	int treeSize(Node *) const; // returns number of nodes in tree
	void sideways(Node* current, int level) const; // helper for displaySideways()
	Node* findNode(const ItemType&, Node*) const;
	int getHeightHelper(const ItemType&, Node*) const; // helper for getHeight
	int recursiveGetHeightHelper(Node*) const; // helper for getHeightHelper
	

};

#endif
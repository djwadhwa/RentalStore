// ------------------------------------------------ BinTree.cpp -------------------------------------------------------
// Tarcisius Daniel Hartanto CSS 343
// Start: Sunday, January 28 2019
// Date of Last Modification : Sunday, Feb 3 2019
// --------------------------------------------------------------------------------------------------------------------
// This is the implementation of all the methods for Poly classes
// --------------------------------------------------------------------------------------------------------------------
// 
// ------------------------------------------------------------------------------------------

#include "BinTree.h"
#include <iostream>
using namespace std;

/**
 * Construct a BinTree object
 */
template <class ItemType>
BinTree<ItemType>::BinTree()//
{
    root = NULL;
}

/**
 * Copy constructor for BinTree
 * @param &tree the tree that will be copied
 */
template <class ItemType>
BinTree<ItemType>::BinTree(const BinTree &tree)//
{
	//copy &tree
    copyNodes(tree.root, root);
}

/**
 * Destructor for BinTree
 */
template <class ItemType>
BinTree<ItemType>::~BinTree()//
{
	//delete all nodes in the tree
    makeEmpty();
}

/**
 * Check if a tree has a Node or does not have any Node at all
 * @ret true if the tree has no Node
 * @ret false if the tree has Node(s)
 */
template <class ItemType>
bool BinTree<ItemType>::isEmpty() const//
{
	return (root == NULL);
}

/**
 * Delete all Nodes inside a tree
 */
template <class ItemType>
void BinTree<ItemType>::makeEmpty()//
{
    // make a pointer to the root of a tree
	Node * curr = root;
    
    //check if the root is NULL (no Nodes in the tree)
    //or not (there is Node(s) inside the tree)
	if (curr != NULL)
    {   
        //call the helper to delete all the Nodes
		helpEmpty(curr);
	}
}

/**
 * The helper to delete all Nodes in a tree
 * @param *curr the Node that will be deleted
 */
template <class ItemType>
void BinTree<ItemType>::helpEmpty(Node * curr)//
{
	if (curr != NULL)
    {
		//recursive calls inside the method
        //to delete the Node with post-order traversal
        helpEmpty(curr->left);
		helpEmpty(curr->right);

        //delete the Node and the data inside it
		delete curr->data;
		delete curr;
        curr->data = NULL;
		curr = NULL;
	}
    
    //change the root to be NULL
	root = NULL;

}


/** 
 * Returns the height of a given node in a binary standard tree
 * If the node given is a leaf than the height is 1
 * Uses helper function getHeightHelper
 */
template <class ItemType>
int BinTree<ItemType>::getHeight(const ItemType &toFind) const
{
    return getHeightHelper(toFind, this->root);
}

/** 
 * Helper function to getHeight
 * Finds the specific node in the tree, if it exists
 * Uses helper function recursiveGetHeightHelper
 */
template <class ItemType>
int BinTree<ItemType>::getHeightHelper(const ItemType &toFind, Node* current) const
{
    if (current == NULL)
    {
        return 0;   // node is not in tree, return height = 0
    }
    else if (*current->data == toFind)
    {
        return recursiveGetHeightHelper(current);   // node found
    }
    else
    {
        int left = getHeightHelper(toFind, current->left);  // search left
        int right = getHeightHelper(toFind, current->right);    // search right

        return max(left, right);
    }
}

/** 
 * Helper function to getHeightHelper
 * Determines the height of the root node
 */
template <class ItemType>
int BinTree<ItemType>::recursiveGetHeightHelper(Node* current) const
{
    if (current == NULL)
    {
        return 0;   // have reached a leaf node
    }
    else
    {
        // counts the amount of levels in the tree from root node
        return 1 + max(recursiveGetHeightHelper(current->left), recursiveGetHeightHelper(current->right));
    }
}

/**
 * Insert a Node to a tree
 * @param node the NodeData that will be contained in the new Node that will be inserted
 * @ret true if it is successfully inserted
 * @ret false if it is not inserted
 */
template <class ItemType>
bool BinTree<ItemType>::insert(ItemType* node)
{
    //make the new Node that contains
    //the NodeData in the parameter
    Node* put = new Node;
    ItemType* newData = new ItemType;
    *newData = *node;
    put->data = newData;
    put->left = NULL;
    put->right = NULL;

    //make the new Node as the root
    //if the root is NULL
    //which indicates that there isnno Nodes in the tree
    if (root == NULL)
    {
        root = put;
        return true;
    }

    //if the tree has at least one Node
    //go to this else if statement
    else if (root != NULL)
    {
        //make a Node pointer to go trhough Nodes in the tree
        Node* curr = root;
        //make a bool variable as indicator for the while loop
        bool spec = true;
        //while loop will be used to go through the Nodes in the tree
        while (spec)
        {
            //go left if the data in the new Nodes is smaller than
            //the currently visited Node in the tree
            if (*node < *(curr->data))
            {
                // if the left Node of the visited Node is NULL
                // insert the new Node
                if (curr->left == NULL)
                {
                    Node** addCurr = &(curr->left);
                    *addCurr = put;
                    return spec;
                }
                // if the left Node of the visited Node is not NULL
                // visit the Node
                curr = curr->left;
            }

            //go right if the data in the new Nodes is bigger than
            //the currently visited Node in the tree
            else if (*node > *(curr->data))
            {
                // if the right Node of the visited Node is NULL
                // insert the new Node
                if (curr->right == NULL)
                {
                    Node** addCurr = &(curr->right);
                    *addCurr = put;
                    return spec; 
                }
                // if the right Node of the visited is not NULL
                // visit the Node
                curr = curr->right;
            }

            // return false and do not insert the new Node
            // if there is a Node with the same NodeData value
            // delete the Node to avoid memory leak
            else if (*node == *(curr->data))
            {
                // delete the data inside the Node and the Node itself
                delete newData;
                delete put;

                // set the data and the Node as NULL
                newData = NULL; 
                put = NULL;

                //return false because the method did not insert anything
                spec = false;
                return spec;
            }
        }
    }   
}

/**
 * Retrieve a Node based on the NodeData given in the parameter
 * and return the data by recording it in the the addres given in the parameter
 * @param &nd the data used as comparison in scanning all the Nodes
 * @param *&record record the Node that is found (retrieve it)
 */
template <class ItemType>
bool BinTree<ItemType>::retrieve(const ItemType &nd, ItemType *& record) const
{
    // point the root with a Node pointer
    // visit Nodes in the tree
    Node * curr = root;

 	// use the retrieveHelper if the tree has at least one Node
    // if the tree has no Nodes return false
    if (curr != NULL)
    {
 		retrieveHelper(curr, nd, record);
 	}
 	else
    {
        return false;
    }

    // if the retrieved NodeData is not NULL and
    // have the same NodeData with nd
    // return true
    // if the retrieved NodeData is NULL or does not have the same NodeData with nd
    // return false
 	if (record != NULL && *record == nd)
    {
 		return true;
 	}
 	else
    {
        return false;
    }

}

/**
 * Helper recursive function for retrieve
 * @param curr the current Node that is scanned
 * @param &nd the data used as comparison in scanning the visited Node
 * @param *&record record the Node that is found (retrieve the NodeData of it)
 */
template <class ItemType>
void BinTree<ItemType>::retrieveHelper(Node * curr, const ItemType & nd, ItemType *& record) const 
{
 	// if the visited Node is NULL
    // set the record (the Node to record the found Node) to be NULL
     if (curr == NULL)
    {
 		record = NULL;
 	}

    // if the visited Node has the same NodeData with nd
    // record the data
 	else if (*(curr->data) == nd) 
    {   
 		record = curr->data;
 	} 
    
    // if the NodeData is smaller than the current visited NodeData
    // go to left Node
 	else if (nd < *(curr->data))
    {
 		retrieveHelper(curr->left, nd, record);
 	}
    
    // if the NodeData is bigger than the current visited NodeData
    // go to the right Node
 	else
 	{
 		retrieveHelper(curr->right, nd, record);
 	}
	
}

/**
 * The "=" overload operator for BinTree
 * @param &tree the object that will be copied to the assigned BinTree object
 * @ret *this the object that has been modified
 */
template <class ItemType>
BinTree<ItemType>& BinTree<ItemType>::operator=(const BinTree &tree)
{
	// from this if statement
    // it is checking if the assigned BinTree object 
    // is the same with the copied object (&tree) or not
    if (*this != tree)
    {
		//delete the Nodes in the tree
        helpEmpty(root);

        //copy the Nodes from &tree to the assigned object
		copyNodes(tree.root, root);
	}

    //return the assigned object
	return *this;

}

/**
 * Copy all the Nodes from a tree to another tree
 * @param *copied the pointer to Node that will be used to copy all the nodes
 *                from the tree that will be copied
 * @param *&receive the pointer to the address of the Node in the tree
 *                  that will receive the copy
 */
template <class ItemType>
void BinTree<ItemType>::copyNodes(Node * copied, Node *& receive)
{
	// check if the Node that wants to be copied
    // are NULL or not
    if (copied != NULL)
    {
		//make a Node to copy the Node* copied and the data inside it
        receive = new Node();
		ItemType *stored = new ItemType;
        *stored = *(copied->data);
		receive->data = stored;
		
        //do the method again for the left and right Node of the current Node recursively
		copyNodes(copied->left, receive->left);
		copyNodes(copied->right, receive->right);
	}
    // if copied is NULL
    // set receive as NULL as well
	else
    {
		receive = NULL;
	}
}

/**
 * The "==" operator overload
 * @param &tree the tree that will be compared with the assigned tree
 * @ret true if both tree have the exact same Nodes (same location, Nodes numbers, and NodeData value)
 * @ret false if both tree have different Nodes (different number of Nodes, location, Nodedata)
 */
template <class ItemType>
bool BinTree<ItemType>::operator==(const BinTree &tree) const
{
    // assign the root of bnoth tree (&tree and the assigned tree)
    // to Node pointers
    Node *firstNode = root;
    Node *secondNode = tree.root;

    // if statement to see if both has no Nodes or not
    // if both has no Nodes then return true
    // if only one of them has no Nodes, go to the else statement
	if (firstNode == NULL && secondNode == NULL)
    {
        return true;
    }

    // check all the Nodes more thoroughly 
    // (number of Nodes, the location of Nodes, and the NodeData value)
	else
    {
        // using helper method to check both trees
        return checkBothBST(firstNode, secondNode);
    }
}

/**
 * Check two trees' Nodes (number of Nodes, the location of Nodes, and the NodeData value)
 * @param *firstTree the first Tree that will be checked together with secondTree
 * @param *secondTree the second Tree that will be checked together with firstTree
 * @ret true if both tree pass the similarity tests
 * @ret false if both tree do not pass the similarity test
 */
template <class ItemType>
bool BinTree<ItemType>::checkBothBST(Node * firstTree, Node * secondTree) const 
{
	// check both Node from both trees to see that
    // the two Nodes compared are not NULL
    // and both the Nodes have the same NodeData value
    // if pass the if statement, return true
    if ((firstTree != NULL && secondTree != NULL) && (*(firstTree->data) == *(secondTree->data)))
    {
        return true;
    }

    // check both Node from both trees
    // if one of the Nodes are NULL
    // if one of the Nodes is NULL, return false
	if (firstTree == NULL || secondTree == NULL)
    {
        return false;
    }

    // return the value that is returned from this method that is called recursively
    // it will give the overall result from this method that is going recursively
	if ((*(firstTree->data) == *(secondTree->data)))
    {
        return true && checkBothBST(firstTree->left, secondTree->left) && checkBothBST(firstTree->right, secondTree->right);
    }
}

/**
 * "!=" operator overload
 * @param &tree the tree that will be compared with the assigned BinTree object
 * @ret true if the two Tree are different
 * @ret false if the two Tree are the same
 */
template <class ItemType>
bool BinTree<ItemType>::operator!=(const BinTree &tree) const
{
	// call the "==" operator overload
    // return false if the "==" says true
    // return true if the "==" says false
    return !(*this == tree);
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
template <class ItemType>
void BinTree<ItemType>::displaySideways() const {
    sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
template <class ItemType>
void BinTree<ItemType>::sideways(Node* curr, int level) const {
    if (curr != NULL) {
        level++;
        sideways(curr->right, level);

        // indent for readability, 4 spaces per depth level 
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *(curr->data) << endl;        // display information of object
        sideways(curr->left, level);
    }
}

/**
 * Put all the Nodes in a Tree to an Array and delete all the Nodes in the Tree
 * @param ndArr the Array that will contain all the NodeData in all the Nodes
 */
template <class ItemType>
void BinTree<ItemType>::bstreeToArray(ItemType* ndArr[])
{
	// make the index for the array (ndArr)
    int index = 0;

    // go to the helper to put all the NodeData in the array
	bstreeToArrayHelper(root, ndArr, index);

    // delete all the Nodes
	helpEmpty(root);
} 

/**
 * Helper for bstreetoArray
 * @param *curr the node that will be put inside ndArr
 * @param ndArr the array that will be used to contain all the NodeData
 * @param index the index to put the NodeData
 */
template <class ItemType>
void BinTree<ItemType>::bstreeToArrayHelper(Node *curr, ItemType* ndArr[], int& index)
{
	// traverse in-order through all Nodes
    // and put all the Nodes in the array
    if (curr != NULL)
    {
        bstreeToArrayHelper(curr->left, ndArr, index);
		ndArr[index] = curr->data;
		curr->data = NULL;	
		index++;
		bstreeToArrayHelper(curr->right, ndArr, index);
	}
}

/**
 * Put the whole NodeData in an assorted Array to a binary search tree (convert it to Node)
 * @param ndArr the assorted array
 */
template <class ItemType>
void BinTree<ItemType>::arrayToBSTree(ItemType* ndArr[])
{
    // find the lower highest and lowest index in the array
    int upper = 0;
	int lower = 0;
	for (int i = 0; i < sizeof(ndArr); i++)
    {
		if (ndArr[i] != NULL)
        {
            upper++;
        }	
	}
	
    // if the tree is empty already
    // convert all NodeData in the array to Nodes to the tree
	if (isEmpty())
    {
	    arrayToBSTreeHelper(root, ndArr, lower, upper-1);
	}

    // if the tree has Node(s)
    // delete the Nodes first
    // and then convert all NodeData in the array to Nodes to the tree
	else 
    {
		helpEmpty(root);
		arrayToBSTreeHelper(root, ndArr, lower, upper-1);
	}
}

/**
 * A helper for arrayToBSTree
 * @param curr the Node that will be put inside the Tree
 * @param ndArr the assorted Array
 * @param lower the lower index 
 * (plus by the upper and then divided by 2 to get the index of the NodeData that will be inserted to the Tree)
 * @param uppoer the upper index
 */
template <class ItemType>
void BinTree<ItemType>::arrayToBSTreeHelper(Node *& curr, ItemType * ndArr[], int lower, int upper)
{
	// if lower index is smaller than or the same with the upper index
    // insert the NodeData in the middle index of the lower and upper index
    // to the tree
	if (lower <= upper)
    {
		int binIndex = (lower+upper)/2;
	    NodeData* temp;
	    temp = ndArr[binIndex];
        insert(temp);
	    ndArr[binIndex] = NULL;
	    arrayToBSTreeHelper(curr->left, ndArr, lower, binIndex - 1 );
	    arrayToBSTreeHelper(curr->right, ndArr, binIndex + 1, upper);
	}

    // if lower index is bigger than the upper index
    // make the currently visited Node as NULL
    else
    {
        curr = NULL;
    }
    
}

/**
 * Get the size of the tree (number of Nodes)
 * @param curr the Node that will be counted 
 * (a Node will be counted if it is not NULL)
 * @ret the total number of all Nodes in a Tree
 */
template <class ItemType>
int BinTree<class ItemType>::treeSize(Node * curr) const 
{
	// check to see whether the current visited Node is NULL or not
    // do not copunt it if it is NULL (return 0)
    if (curr == NULL)
    {
		return 0;       
    }

    // go here if the visited Node is not NULL
    // count it and try to go to other Nodes in the Tree (call the method recursively)
	else
    {
		return 1 + treeSize(curr->left) + treeSize(curr->right);        
    }
}

/**
 * Helper for "<<" operator overload
 * Print it in-order traversely
 * @param outStream the things that will be printed in the cout
 * @param curr the visited Node in the tree
 */
template <class ItemType>
void BinTree<class ItemType>::printHelper(ostream& outStream, Node* curr) const
{
    // record the NodeData to the outStream if it is not NULL
    if (curr != NULL)
    {
        printHelper(outStream, curr->left);
        outStream << *(curr->data) << " ";
        printHelper(outStream, curr->right);
    }
}



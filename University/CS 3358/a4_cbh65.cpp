#include <iostream>
using namespace std;

struct BinNode {
       int key;
       BinNode *left;
       BinNode *right;
};

class myBST {
public:
	myBST () { root = NULL; }
	~myBST ();
	BinNode* findInBST(int k); // return NULL if not found
	void insertToBST(int k);
	void preOrderTraversal();
	void postOrderTraversal();
	void inOrderTraversal();
	void rotatedPrintTree();
private:

    BinNode* root;

	void free_helper(BinNode* node);
	// BinNode* find_helper(BinNode* node, int k);  //optional helper function for findInBST
	void insert_helper(BinNode* node, int k);  //optional helper function for insertToBST
	void preOrder(BinNode* node);
	void postOrder(BinNode* node);
	void inOrder(BinNode* node);
	void rotatedPrint(BinNode* node, int d);
};

myBST::~myBST() {
	free_helper(root);
}

void myBST::free_helper(BinNode* node) {
	if(node != NULL) {
		free_helper(node->left);
		free_helper(node->right);
		delete node;
	}
}



// //***************************
// //recursive implementation***
// //***************************
// BinNode* myBST::findInBST(int k) {

// }

// BinNode* myBST::find_helper(BinNode* node, int k) {

// }


//*******************************
//non-recursive implementation***
//*******************************
BinNode* myBST::findInBST(int k)
{
    BinNode* temp = root;
    while (temp != NULL)
    {

        if(k > temp -> key)
            temp = temp -> right;
        else if (k < temp -> key)
            temp = temp -> left;
        else
            return temp;
    }

}

// //***************************
// //recursive implementation***
// //***************************
// void myBST::insertToBST(int k) {

// }


void myBST::insert_helper(BinNode* node, int k)
{

        if(node->key == k)
            cout << node->key << " is an existing key.  No new node has been inserted. \n";
        else if (node->key > k)
        {
            if (!node->left)
            {
                node->left = new BinNode;
                node->left->key = k;
                node->left->left = NULL;
                node->left->right = NULL;
            }
            else
            {
                insert_helper(node->left, k);
            }
        }
        else
        {
            if (!node->right)
            {
                node->right = new BinNode;
                node->right->key = k;
                node->right->left = NULL;
                node->right->right = NULL;
            }
            else
            {
                insert_helper(node->right, k);
            }
        }
}



void myBST::insertToBST(int k)
{

    if (root)
    {
        insert_helper(root, k);
    }
    else
    {
        root = new BinNode;
        root->key = k;
        root->left = NULL;
        root->right = NULL;
    }

}




//***********************************
//preOrderTraversal implementation***
//***********************************
void myBST::preOrderTraversal()
{
	preOrder(root);
	cout << endl;
}

void myBST::preOrder(BinNode* node)
{
    if (node == NULL)
        return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}


//************************************
//postOrderTraversal implementation***
//************************************
void myBST::postOrderTraversal()
{
	postOrder(root);
	cout << endl;
}

void myBST::postOrder(BinNode* node)
{
    if(node == NULL)
        return;
    postOrder(node -> left);
    postOrder(node -> right);
    cout << node -> key << " ";
}



//**********************************
//inOrderTraversal implementation***
//**********************************
void myBST::inOrderTraversal()
{
	inOrder(root);
	cout << endl;
}

void myBST::inOrder(BinNode* node)
{
    if(node == NULL)
        return;
    inOrder(node->left);
    cout << node ->key << " ";
    inOrder(node->right);

}


//***********************************
//print the tree (left rotated)******
//***********************************
void myBST::rotatedPrintTree()
{
	rotatedPrint(root, 0);
}

void myBST::rotatedPrint(BinNode* node, int d)
{
	if(node == NULL)
		return;

	if (node->right != NULL)
		rotatedPrint(node->right, d+1);

	for(int i = 0; i < d; i++)
		cout << "\t";
	cout << node->key << endl;

	if (node->left != NULL)
		rotatedPrint(node->left, d+1);
}



int main()
{
    myBST testTree;

	int user_input = 0;

	while (user_input != -1) {
		cout << "Inserting a new node...." << endl;
		cout << "Please enter an integer between 0 and 99 as the key, ";
		cout << "and enter -1 to stop and to see the resulting tree: ";
		cin >> user_input;
		if (user_input >= 0 and user_input <= 99)
			testTree.insertToBST(user_input);
		else if (user_input != -1)
			cout << "Invalid input value (" << user_input << ") !" << endl;
	}

	cout << "Print the resulting tree (left-rotated):" << endl;
	testTree.rotatedPrintTree();

	cout << "preOrderTraversal: ";
	testTree.preOrderTraversal();
	cout << "postOrderTraversal: ";
	testTree.postOrderTraversal();
	cout << "inOrderTraversal: ";
	testTree.inOrderTraversal();


	user_input = 0;

	while (user_input != -1) {
		cout << "Searching a key...." << endl;
		cout << "Please enter an integer between 0 and 99 as the key to search, ";
		cout << "and enter -1 to stop searching: ";
		cin >> user_input;

		if (user_input >= 0 and user_input <= 99) {
			BinNode* temp = testTree.findInBST(user_input);
			if(temp == NULL)
				cout << user_input << " is not in this BST." << endl;
			else {
				cout << user_input << " is in this BST." << endl;
				if(temp->left != NULL)
					cout << user_input << " has a left child " << temp->left->key << endl;
				if(temp->right != NULL)
					cout << user_input << " has a right child " << temp->right->key << endl;
			}
		}
		else if (user_input != -1)
			cout << "Invalid input value (" << user_input << ") !" << endl;
	}

	return 0;
}

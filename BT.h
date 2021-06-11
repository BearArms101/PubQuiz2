#pragma once
#include <iostream>
#include <queue>

//tutorial: youtube.com/watch?v=log-68bnS1g&ab_channel=ahmadbazziahmadbazzi

//I did all implementations for this in the header because I had compiler issues when declaring the Node* methods within cpp
//... due to having to input the class name like CLASSNAME::METHOD(), compiler didn't agree due to the pointer??

//Can't do much with this class. I have no idea how to pass anything from outside to it. It seems to just classify everything passed to it as an object


using namespace std;
class BT //british telecom
{
	struct Node
	{
		int key;
		Node* left;
		Node* right;
	};

	Node* createNode(int k)
	{
		Node* node = new Node();
		node->key = k;
		node->left = NULL;
		node->right = NULL;
		return node;
	}

public:	Node* Search(Node *root, int k)
		//level order traversal
	{
		if (root == NULL) //if we don't have a root key, then there won't be anything to search for anyway
			return NULL;
		queue<Node*> q;
		Node* out = NULL;
		q.push(root); //stick the node in a queue
		while (!q.empty()) 
		{
			Node* temp = q.front(); //define a new node, this will be what we search for
			q.pop(); 

			if (temp->key == k) //if the value of the key  is equal to what we're looking for
			{
				out = temp;  //make it our output
				cout << "FOUND IT" << endl;
			}
			if (temp->left != NULL) q.push(temp->left); 
			if (temp->right != NULL) q.push(temp->right);
		}
		return out;
	}
		
	void Insert(Node *root, Node *node)
	{

	}

public:	void Insert(Node **root, int k)
		//insert by finding first vacant node in level order traversal fashion
	{
		if (*root == NULL) 
		{
			//if we don't have a root node, then make the new node the root
			//(*root)->key = k;
			*root = createNode(k);
			return;
		}
		Node* nodeToInsert = createNode(k); 
		queue < Node*> q;
		q.push(*root); 

		while (!q.empty())
		{
			//left
			Node* temp = q.front();
			q.pop();
			if (temp->left == NULL)
			{
				temp->left = nodeToInsert;
				return;
			}
			else {
				q.push(temp->left);
			}
			//right
			if (temp->right == NULL)
			{
				temp->right = nodeToInsert;
				return;
			}
			else {
				q.push(temp->right);
			}
		}
	}

public:	void setRightMosttoNULL(Node *root, Node *rightMost)
	{
		queue<Node*> q;
		q.push(root);
		Node* temp;
		while (!q.empty())
		{
			temp = q.front();
			q.pop();
			if (temp->left != NULL)
			{
				if (temp->left == rightMost)
				{
					temp->left = NULL;
					return;
				}
				else 
				{
					q.push(temp->left);
				}
			}
			if (temp->right != NULL)
			{
				if (temp->right == rightMost)
				{

					temp->right = NULL;
					return;
				}
				else
				{
					q.push(temp->right);
				}
			}

		}
	}
public:	void deleteNode(Node *root, int key)
	{
		Node *nodeToDelete = Search(root, key);
		queue<Node*> q;
		Node* temp;
		if (nodeToDelete != NULL)
		{
			q.push(root);
			Node* temp = q.front();
			while (!q.empty())
			{
				temp = q.front();
				q.pop();

				if (temp->left != NULL)
				{
					q.push(temp->left);
				}
				if (temp->right != NULL)
				{
					q.push(temp->right);
				}
			}
			int keyAtDeepestRight = temp->key;
			setRightMosttoNULL(root, temp);
			nodeToDelete->key = keyAtDeepestRight;
		}
	}


public: void Run()
	//testing function 
	{		
		Node* root = NULL;
		for (int i = 1; i <= 6; i++)
		{
			Insert(&root, i); 
		}
		cout << "outputting all nodes created...\n";
		cout << root->key << endl;
		cout << root->left->key << endl;
		cout << root->right->key << endl;
		cout << root->left->left->key << endl;
		cout << root->left->right->key << endl;
		cout << root->right->left->key << endl;

		cout << "deleting node 6... (tree will be balanced as well)\n";
		deleteNode(root, 6);
		cout << root->key << endl;
		cout << root->left->key << endl;
		cout << root->right->key << endl;
		cout << root->left->left->key << endl;
		cout << root->left->right->key << endl;
		cout << root->right->left << endl; //this node was 6. Had to remove key output as compiler didn't like it.

		cout << "searching for 5...\n";
		Node *node = Search(root, 5); 
		cout << node->key << endl;
		/* dunno how to deal with a nullptr, don't have time to learn atm
		cout << "searching for 6...\n";
		Node* node2 = Search(root, 6);
		cout << node2->key << endl; */

	}
};


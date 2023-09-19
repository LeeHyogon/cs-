``` c++
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;
#define INF 987654321
#define LINF 321321321321
#define M 5
#define MAX_CHILDREN M
#define MAX_KEYS MAX_CHILDREN-1
#define MIN_KEYS (int)(ceilM(2.0))-1 //최소 키 갯수 구하는 식
typedef long long ll;

class BTreeNode {
	int *keys; // key 배열
	int t; // 최소 자식 갯수 minimum degree
	BTreeNode **C; //An array of child pointers
	int n; // Current number of keys
	bool leaf; // true면 리프 노드

public:
	BTreeNode(int _t, bool _leaf); 

	// A utility function to insert a new key in the subtree rooted with
	// this node. The assumption is, the node must be non-full when this
	// function is called
	void insertNonFull(int k);

	// A utility function to split the child y of this node. i is index of y in
	// child array C[].  The Child y must be full when this function is called
	void splitChild(int i, BTreeNode *y);

	// A function to traverse all nodes in a subtree rooted with this node
	void traverse();
	
	BTreeNode* search(int k); 

	friend class BTree;
};

class BTree {
	BTreeNode* root; // Pointer to root node
	int t; //Minimum degree

public:
	BTree(int _t) {
		root = NULL;
		t = _t;
	}

	void traverse()
	{
		if (root != NULL)
			root->traverse();
	}

	BTreeNode* search(int k) {
		return (root == NULL) ? NULL : root->search(k);
	}
	void insert(int k);
};

BTreeNode::BTreeNode(int _t, bool _leaf)
{
	// Copy the given minimum degree and leaf property
	t = _t;
	leaf = _leaf;

	// Allocate memory for maximum number of possible keys
	// and child pointers
	keys = new int[2 * t - 1];
	C = new BTreeNode*[2 * t];

	// Initialize the number of keys as 0
	n = 0;
}

// Function to traverse all nodes in a subtree rooted with
// this node
void BTreeNode::traverse()
{
	// There are n keys and n+1 children, traverse through n
	// keys and first n children
	int i;
	for (i = 0; i < n; i++) {
		if (leaf == false)
			C[i]->traverse();
		cout << " " << keys[i];
	}
	
	// Print the subtree rooted with last child
	// 자식이 n+1개이므로, key값 다 출력한 이후 마지막 자식 순회
	if (leaf == false)
		C[i]->traverse();
}

BTreeNode* BTreeNode::search(int k) {

	//Find the first key greater than or equal to k
	int i = 0;
	while (i<n && k > keys[i])
		i++;

	// If the found key is equal to k, return this node
	if (keys[i] == k)
		return this;

	// If the key is not found here and this is a leaf node
	if (leaf == true)
		return NULL;

	// Go to the appropriate child
	return C[i]->search(k);
}

// The main function that inserts a new key in this B-Tree
void BTree::insert(int k) {
	if (root == NULL) {
		//Allocate memory for root
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	}
	else {
		if (root->n == 2 * t - 1) {
			// Allocate meory for new root
			BTreeNode *s = new BTreeNode(t, false);

			s->C[0] = root;

			s->splitChild(0, root);

			int i = 0;
			if (s->keys[0] < k)
				i++;
			s->C[i]->insertNonFull(k);
		}
		else 
			root->insertNonFull(k);
	}
}

// A utility function to insert a new key in this node
// The assumption is, the node must be non-full when this
// function is called
void BTreeNode::insertNonFull(int k) {
	// Initialize index as index of rightmost element
	int i = n - 1; 

	if (leaf == true) {

		// the following loop does two thins
		// a) Finds the location of new key to be inserted
		// b) Moves all greater keys to one place ahead
		while (i >= 0 && keys[i] > k) {
			keys[i + 1] = keys[i];
			i--;
		}
		//Insert the new key at found location
		keys[i + 1] = k;
		n = n + 1;
	}
	else {
		// Find the child which is going to have the new key
		while (i >= 0 && keys[i] > k)
			i--;
		// See if the found child is full
		if (C[i + 1]->n == 2 * t - 1) {
			//If the child is full, then split it
			splitChild(i + 1, C[i + 1]);
			// After split, the middle key of C[i] goes up and
			// C[i] is splitted into two.  See which of the two
			// is going to have the new key
			if (keys[i + 1] < k)
				i++;
		}
		C[i + 1]->insertNonFull(k);
	}
}
// A utility function to split the child y of this node
// Note that y must be full when this function is called
void BTreeNode::splitChild(int i, BTreeNode *y) {
	// Create a new node which is going to store (t-1) keys
	// of y
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;

	// Copy the last (t-1) keys of y to z
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];

	if (y->leaf == false) {
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}

	// Reduce the number of keys in y
	y->n = t - 1;

	// Since this node is going to have a new child,
	// create space of new child
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	// Link the new child to this node
	C[i + 1] = z;

	// A key of y will move to this node. Find the location of
	// new key and move all greater keys one space ahead
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];

	//Copy the middle key of y to this node
	keys[i] = y->keys[t - 1];

	// Increment count of keys in this node
	n = n + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}
```

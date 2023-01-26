#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
	char data;
	Node* left;
	Node* right;
	Node() {
		data = '0';
		left = NULL;
		right = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> list;
	Tree() {
		root = new Node();
		root->data = 'A';
		list.push_back(root);
	}
	Node* search(char x) {
		for (int i = 0; i < list.size(); i++) {
			if (list[i]->data == x) return list[i];
		}
		return NULL;
	}
	void insert(char x, char y, char z)
	{
		Node* parent = search(x);
		if (y != '.')
		{
			Node* leftNode = new Node();
			leftNode->data = y;
			parent->left = leftNode;
			list.push_back(leftNode);
		}
		if (z != '.')
		{
			Node* rightNode = new Node();
			rightNode->data = z;
			parent->right = rightNode;
			list.push_back(rightNode);
		}
	}
	void preOrder(Node* n) {
		if (n == NULL) return;
		cout << n->data;
		preOrder(n->left);
		preOrder(n->right);
		return;
	}
	void posOrder(Node* n) {
		if (n == NULL) return;
		posOrder(n->left);
		posOrder(n->right);
		cout << n->data;
		return;
	}
	void inOrder(Node* n) {
		if (n == NULL) return;
		inOrder(n->left);
		cout << n->data;
		inOrder(n->right);
	}
};

int main() {
	int T;
	Tree t;
	cin >> T;
	while (T--)
	{
		char x, y, z;
		cin >> x >> y >> z;
		t.insert(x, y, z);
	}
	t.preOrder(t.root);
	cout << endl;
	t.inOrder(t.root);
	cout << endl;
	t.posOrder(t.root);
}
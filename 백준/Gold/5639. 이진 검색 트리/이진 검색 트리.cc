#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef long long ll;

using namespace std;

class BinaryTree {
public:
	int value;
	BinaryTree* left;
	BinaryTree* right;

	BinaryTree(int value) {
		this->value = value;
		left = NULL;
		right = NULL;
	}
};

void PostOrder(BinaryTree* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->value << " ";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int rootValue = 0;
	cin >> rootValue;

	BinaryTree root(rootValue);
	int input;
	while (cin >> input) {
		BinaryTree* ptr = &root;
		while (ptr != NULL) {
			if (input < ptr->value) {
				if (ptr->left == NULL) {
					ptr->left = new BinaryTree(input);
					break;
				}
				ptr = ptr->left;
			}
			else {
				if (ptr->right == NULL) {
					ptr->right = new BinaryTree(input);
					break;
				}
				ptr = ptr->right;
			}
		}
		
	}
	

	PostOrder(&root);
	return 0;
}





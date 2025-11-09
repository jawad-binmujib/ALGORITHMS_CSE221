#include <iostream>
#include <vector>
using namespace std;

int length1;
vector<int> postOrder;
vector<int> inOrderMap;
int postIndex;

struct Node {
    int value;
    Node *left;
    Node *right;
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

Node* buildTree(int inStart, int inEnd) {
    if (inStart > inEnd) {
        return nullptr;
    }

    int rootVal = postOrder[postIndex--];
    Node* root = new Node(rootVal);
    int inRootIndex = inOrderMap[rootVal];
    root->right = buildTree(inRootIndex + 1, inEnd);
    root->left = buildTree(inStart, inRootIndex - 1);
    return root;
}

void printPreOrder(Node* root) {

    if (root == nullptr) {
        return;
    }
    cout << root->value << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> length1;
    postOrder.resize(length1);
    inOrderMap.resize(length1 + 1);
    for (int i = 0; i < length1; ++i) {
        int val;
        cin >> val;
        inOrderMap[val] = i;
    }

    for (int i = 0; i < length1; ++i) {
        cin >> postOrder[i];
    }
    postIndex = length1 - 1;
    Node* root = buildTree(0, length1 - 1);
    printPreOrder(root);
    cout << endl;

    return 0;
}
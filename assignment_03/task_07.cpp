#include <iostream>
#include <vector>
using namespace std;

int length;
vector<int> preOrder;
vector<int> inOrder;
vector<int> inOrderMap;
int preIndex = 0;
void printPostOrder(int inStart, int inEnd) {
    if (inStart > inEnd) {
        return;
    }
    int rootVal = preOrder[preIndex++];
    int inRootIndex = inOrderMap[rootVal];
    printPostOrder(inStart, inRootIndex - 1);
    printPostOrder(inRootIndex + 1, inEnd);
    cout << rootVal << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> length;
    preOrder.resize(length);
    inOrder.resize(length);
    inOrderMap.resize(length + 1);
    for (int i = 0; i < length; ++i) {
        cin >> inOrder[i];
        inOrderMap[inOrder[i]] = i;
    }
    for (int i = 0; i < length; ++i) {
        cin >> preOrder[i];
    }
    printPostOrder(0, length - 1);
    cout << endl;

    return 0;
}
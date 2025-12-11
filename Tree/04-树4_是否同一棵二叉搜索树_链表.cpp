#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int flag;
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : flag(0), data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : flag(0), data(x), left(nullptr), right(nullptr) {}
};


TreeNode* Insert(int x, TreeNode* Tree) {
    if (Tree == NULL) {
        TreeNode* Tmp = new TreeNode(x);
        return Tmp;
    }
    else if (Tree->data < x) {
        Tree->right = Insert(x, Tree->right);
    }
    else
        Tree->left = Insert(x, Tree->left);
    return Tree;
}
vector<int> CreatExTree(int N) {
    vector<int>T;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        T.push_back(x);
    }
    return T;
}
TreeNode* CreatTree(int N) {
    int x;
    cin >> x;
    TreeNode* Tree = new TreeNode(x);
    for (int i = 1; i < N; i++) {
        cin >> x;
        Tree = Insert(x, Tree);
    }
    return Tree;
}


bool NoProblem(int tar, TreeNode* TreeA) {
    while (TreeA != nullptr) {
        if (TreeA->data == tar) {
            TreeA->flag = 1; break;
        }
        else if (TreeA->data > tar) {
            if (TreeA->flag == 0) return false;
            TreeA = TreeA->left;
        }
        else {
            if (TreeA->flag == 0) return false;
            TreeA = TreeA->right;
        }
    }
    return true;
}
void Isomorphism(vector<int> TreeEX,
    TreeNode* TreeA) {
    int tag = 0;
    for (int i = 0; i < TreeEX.size(); i++) {
        int tar = TreeEX[i];
        if (!NoProblem(tar, TreeA)) {
            tag = 1; break;
        }
    }
    if (tag == 0) {
        cout << "Yes";
    }
    else
        cout << "No";
}
int main() {
    vector<int> TreeEX;
    int N;
    cin >> N;
    while (N != 0) {
        int L;
        cin >> L;
        TreeEX = CreatExTree(N);
        while ((L--) > 0) {
            TreeNode* TreeA = new TreeNode();
            TreeA = CreatTree(N);
            //compare_function:
            if ((TreeEX.size() == 0) && (!TreeA)) {
                cout << "Yes";
            }
            else if ((TreeEX.size() == 0) || (!TreeA)) {
                cout << "No";
            }
            else {
                Isomorphism(TreeEX, TreeA);
            }
            cout << endl;
        }
        cin >> N;
    }
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

string post_order(const string &preorder, const string &inorder){
     
    if(preorder.empty()){
        return "";
    }

    const int treeSize = preorder.length();

    const char root = preorder[0];

    const int leftSubtreeSize = inorder.find(root);
    const int rightSubtreeSize = treeSize - leftSubtreeSize - 1;

    const string leftPreorder = preorder.substr(1, leftSubtreeSize);
    const string leftInorder = inorder.substr(0, leftSubtreeSize);
    
    const string rightPreorder = preorder.substr(leftSubtreeSize+1, rightSubtreeSize);
    const string rightInorder = inorder.substr(leftSubtreeSize+1, rightSubtreeSize);
     
    string ret;

    ret.append(post_order(leftPreorder, leftInorder));
    ret.append(post_order(rightPreorder, rightInorder));

    ret += root;

    return ret;
}

int main(){

    string preorder;
    cin.sync_with_stdio(false);

    while(cin >> preorder){
        string inorder;
        cin >> inorder;

        cout << post_order(preorder, inorder) <<"\n";
    }

    return 0;
}



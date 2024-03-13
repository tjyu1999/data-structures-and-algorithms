# include <iostream>
# include <queue>

using namespace std;

struct TreeNode{
    int key;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode():key(0), left(nullptr), right(nullptr){}
    TreeNode(int val):key(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):key(val), left(left), right(right){}
};

class BinarySearchTree{
private:
    TreeNode *root;
    
    bool search(TreeNode *node, int k){
        if(!node) return false;
        
        if(node->key > k) return search(node->left, k);
        else if(node->key < k) return search(node->right, k);
        
        return true;
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }
    
    void init_root(TreeNode *preset_root){
        root = preset_root;
    }
    
    bool search(int k){
        return search(root, k);
    }
};

int main(){
    BinarySearchTree bst;
    
    /*
     *       4
     *      / \
     *     2   5
     *    / \   \
     *   1   3   6
     */
    
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
    
    bst.init_root(root);
    
    int k = 5;
    cout << (bst.search(k) ? "true" : "false") << endl;
    
    return 0;
}

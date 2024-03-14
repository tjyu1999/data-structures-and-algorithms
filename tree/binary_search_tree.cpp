# include <iostream>
# include <vector>
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
    
    TreeNode* search(TreeNode *node, int k){
        if(!node) return nullptr;
        
        if(node->key > k) return search(node->left, k);
        else if(node->key < k) return search(node->right, k);
        
        return node;
    }
    
    TreeNode* insert(TreeNode *node, int k){
        if(!node) return new TreeNode(k);
        
        if(node->key > k) node->left = insert(node->left, k);
        else if(node->key < k) node->right = insert(node->right, k);
        
        return node;
    }
    
    TreeNode* remove(TreeNode *node, int k){
        if(!node) return nullptr;
        
        if(node->key > k) root->left = remove(node->left, k);
        else if(node->key < k) root->right = remove(node->right, k);
        else{
            if(!node->left) return node->right;
            if(!node->right) return node->left;
            
            TreeNode *min = get_min(node->right);
            node->right = remove(node->right, min->key);
            min->left = node->left;
            min->right = node->right;
            node = min;
        }
        
        return node;
    }
    
    TreeNode* get_min(TreeNode *node){
        while(node->left) node = node->left;
        return node;
    }

public:
    BinarySearchTree(){
        root = nullptr;
    }
    
    void init_root(TreeNode *preset_root){
        root = preset_root;
    }
    
    TreeNode* search(int k){
        return search(root, k);
    }
    
    void insert(int k){        
        insert(root, k);
    }
    
    void remove(int k){
        remove(root, k);
    }
    
    void levelorder_traversal(){
        if (!root) return;
        
        vector<int> res;
        queue<TreeNode*> q{{root}};
        
        while(!q.empty()){            
            for(int n = q.size(); n > 0; --n){
                TreeNode *node = q.front();
                q.pop();
                res.push_back(node->key);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        
        for(int key : res) cout << key << " ";
        cout << endl;
    }
};

int main(){
    /*
     *       4
     *      / \
     *     2   6
     *    / \   \
     *   1   3   7
     */
    
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    
    BinarySearchTree bst;
    bst.init_root(root);
    
    int k = 5;
    bst.insert(k);
    bst.levelorder_traversal();
    cout << (bst.search(k) ? "true" : "false") << endl;
    bst.remove(k = 2);
    bst.levelorder_traversal();
    cout << (bst.search(k) ? "true" : "false") << endl;
    
    return 0;
}

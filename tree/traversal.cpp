/*
 * inorder: LVR
 * preorder: VLR
 * postorder: LRV
 */

# include <iostream>
# include <vector>
# include <stack>
# include <algorithm>

using namespace std;

struct TreeNode{
    int key;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode():key(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : key(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):key(val), left(left), right(right){}
};

class BinaryTree{
private:
    TreeNode *root;

public:
    BinaryTree(){
        root = nullptr;
    }
    
    vector<int> inorder_traversal(TreeNode *root){        
        vector<int> res;
        stack<TreeNode*> st;
        
        while(root || !st.empty()){
            while(root){
                st.push(root);
                root = root->left;                
            }
            
            root = st.top();
            st.pop();
            res.push_back(root->key);
            root = root->right;
        }
        
        return res;
    }
    
    vector<int> preorder_traversal(TreeNode *root){
        if(!root) return {};
        
        vector<int> res;
        stack<TreeNode*> st{{root}};
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            res.push_back(root->key);
            
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
        }
        
        return res;
    }
    
    vector<int> postorder_traversal(TreeNode *root){
        if(!root) return {};
        
        vector<int> res;
        stack<TreeNode*> st{{root}};
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            res.push_back(root->key);
            
            if(root->left) st.push(root->left);
            if(root->right) st.push(root->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    BinaryTree bt;
    
    /*
     *       1
     *      / \
     *     2   3
     *    / \   \
     *   4   5   6
     */
    
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    vector<int> res = bt.inorder_traversal(root);
    for(int key : res) cout << key << " ";
    cout << endl;
    
    res = bt.preorder_traversal(root);
    for(int key : res) cout << key << " ";
    cout << endl;
    
    res = bt.postorder_traversal(root);
    for(int key : res) cout << key << " ";
    cout << endl;
    
    return 0;
}

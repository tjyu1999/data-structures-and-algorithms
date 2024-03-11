/*
 * inorder: LVR
 * preorder: VLR
 * postorder: LRV
 */

# include <iostream>
# include <vector>
# include <stack>
# include <queue>
# include <algorithm>

using namespace std;

struct TreeNode{
    int key;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode():key(0), left(nullptr), right(nullptr){}
    TreeNode(int val):key(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right):key(val), left(left), right(right){}
};

class BinaryTree{
private:
    TreeNode *root;

public:
    BinaryTree(){
        root = nullptr;
    }
    
    vector<vector<int>> levelorder_traversal(TreeNode *root){
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode*> q{{root}};
        
        while(!q.empty()){
            vector<int> level;
            
            for(int n = q.size(); n > 0; --n){
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->key);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            
            res.push_back(level);
        }
        
        return res;
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
    
    vector<vector<int>> levelorder_res = bt.levelorder_traversal(root);
    for(vector<int> vec : levelorder_res){
        for(int key : vec) cout << key << " ";
    }
    cout << endl;
    
    vector<int> inorder_res = bt.inorder_traversal(root);
    for(int key : inorder_res) cout << key << " ";
    cout << endl;
    
    vector<int> preorder_res = bt.preorder_traversal(root);
    for(int key : preorder_res) cout << key << " ";
    cout << endl;
    
    vector<int> postorder_res = bt.postorder_traversal(root);
    for(int key : postorder_res) cout << key << " ";
    cout << endl;
    
    return 0;
}

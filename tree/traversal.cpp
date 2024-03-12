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
    
    void init_root(TreeNode *preset_root){
        root = preset_root;
    }
    
    vector<int> levelorder_traversal(){
        if (!root) return {};
        
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
        
        return res;
    }
    
    vector<int> inorder_traversal(){
        TreeNode *node = root;
        vector<int> res;
        stack<TreeNode*> st;
        
        while(node || !st.empty()){
            while(node){
                st.push(node);
                node = node->left;                
            }
            
            node = st.top();
            st.pop();
            res.push_back(node->key);
            node = node->right;
        }
        
        return res;
    }
    
    vector<int> preorder_traversal(){
        if(!root) return {};
        
        TreeNode *node = root;
        vector<int> res;
        stack<TreeNode*> st{{node}};
        
        while(!st.empty()){
            node = st.top();
            st.pop();
            res.push_back(node->key);
            
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        
        return res;
    }
    
    vector<int> postorder_traversal(){
        if(!root) return {};
        
        TreeNode *node = root;
        vector<int> res;
        stack<TreeNode*> st{{node}};
        
        while(!st.empty()){
            node = st.top();
            st.pop();
            res.push_back(node->key);
            
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

void print_vector(vector<int> res){
    for(int key : res) cout << key << " ";
    cout << endl;
}

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
    
    bt.init_root(root);
    
    print_vector(bt.levelorder_traversal());
    print_vector(bt.inorder_traversal());
    print_vector(bt.preorder_traversal());
    print_vector(bt.postorder_traversal());
    
    return 0;
}

/*
 *  inorder: LVR
 *  preorder: VLR
 *  postorder: LRV
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

class BinarySearchTree{
private:
    TreeNode *root;
    
    TreeNode* insert(TreeNode *node, int k){
        if(!node) return new TreeNode(k);
        
        if(node->key > k) node->left = insert(node->left, k);
        else if(node->key < k) node->right = insert(node->right, k);
        
        return node;
    }

public:
    BinarySearchTree():root(nullptr){}
    
    ~BinarySearchTree(){
        destroy(root);
    }
    
    void init(vector<int> &keys){
        for(int k : keys) root = insert(root, k);
    }
    
    void destroy(TreeNode *node){
        if(node){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }
    
    vector<int> levelorder_traversal(){
        if (!root) return {};
        
        vector<int> res;
        queue<TreeNode*> q{{root}};
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            res.push_back(node->key);
            
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
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
    /*
     *      4
     *     / \
     *    2   6
     *   / \   \
     *  1   3   7
     */
    
    vector<int> keys = {4, 2, 1, 3, 6, 7};
    BinarySearchTree bst;
    
    bst.init(keys);
    
    print_vector(bst.levelorder_traversal());
    print_vector(bst.inorder_traversal());
    print_vector(bst.preorder_traversal());
    print_vector(bst.postorder_traversal());
    
    return 0;
}

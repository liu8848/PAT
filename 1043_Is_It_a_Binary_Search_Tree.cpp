#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode
{
    int val_;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val_(val),left(nullptr),right(nullptr){};
    TreeNode(int val,TreeNode*l,TreeNode*r):val_(val),left(l),right(r){}
};

TreeNode* buildBST(TreeNode*root,int val){
    if(root==nullptr){
        root=new TreeNode(val);
        return root;
    }
    if(val<root->val_){
        root->left=buildBST(root->left,val);
    }else{
        root->right=buildBST(root->right,val);
    }
    return root;
}


void preorder(vector<int>&pre,TreeNode*root){
    if(!root) return;
    pre.push_back(root->val_);
    preorder(pre,root->left);
    preorder(pre,root->right);
}

void reverse_preorder(vector<int>&pre,TreeNode*root){
    if(!root) return;
    pre.push_back(root->val_);
    reverse_preorder(pre,root->right);
    reverse_preorder(pre,root->left);
}



void postOrder(vector<int>&post,TreeNode*root){
    if(!root) return;
    postOrder(post,root->left);
    postOrder(post,root->right);
    post.push_back(root->val_);
}
void reverse_postOrder(vector<int>&post,TreeNode*root){
    if(!root) return;
    reverse_postOrder(post,root->right);
    reverse_postOrder(post,root->left);
    post.push_back(root->val_);
}

int main(){
    int N;
    cin>>N;
    vector<int> nums(N);
    TreeNode*root=nullptr;
    for(int i=0;i<N;i++){
        cin>>nums[i];
        root=buildBST(root,nums[i]);
    }
    vector<int> seq1,seq2;
    preorder(seq1,root);
    reverse_preorder(seq2,root);
    bool is_seq1=(seq1==nums),is_seq2=(seq2==nums);
    if(!is_seq1&&!is_seq2){
        cout<<"NO";
        return 0;
    }
    vector<int> post;
    if(is_seq1)
        postOrder(post,root);
    else
        reverse_postOrder(post,root);
    cout<<"YES"<<endl;
    for(int i=0;i<post.size();i++){
        if(i==post.size()-1) {
            cout<<post[i];
            continue;
        }
        cout<<post[i]<<" ";
    }
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
struct TreeNode
{
    int Val;
    TreeNode*left;
    TreeNode*right;
    TreeNode(int val):Val(val),left(nullptr),right(nullptr){}
    TreeNode(int val,TreeNode*l,TreeNode*r):Val(val),left(l),right(r){}
};

TreeNode*constructTree(vector<int>&nums,int&pos,int root_index,const int&N){
    if(root_index>N){
        return nullptr;
    }
    TreeNode*root=new TreeNode(0);
    int left=2*root_index,right=2*root_index+1;
    root->left=constructTree(nums,pos,left,N);
    root->Val=nums[pos++];
    root->right=constructTree(nums,pos,right,N);
    return root;

}
string levelOrder(TreeNode*root){
    if(!root) return "";
    string ans;
    queue<TreeNode*>que;
    que.push(root);
    while(!que.empty()){
        TreeNode*p=que.front();
        que.pop();
        ans+=to_string(p->Val)+" ";
        if(p->left) que.push(p->left);
        if(p->right) que.push(p->right);
    }
    return ans.substr(0,ans.size()-1);
}

int main(){
    int N;
    cin>>N;
    int val;
    vector<int>nums(N);
    for(int i=0;i<N;++i){
        cin>>nums[i];
    }
    sort(nums.begin(),nums.end());
    int pos=0;
    TreeNode*root=constructTree(nums,pos,1,N);
    cout<<levelOrder(root)<<endl;
    return 0;
}

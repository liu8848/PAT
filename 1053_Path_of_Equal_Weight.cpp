#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int weight;
    vector<int>children;
    TreeNode(int weight_):weight(weight_),children(){}
};

void dfs(unordered_map<int,TreeNode*>&tree,int root,int target,vector<vector<int>>&ans,vector<int>&path,vector<int>&weights){
    target-=weights[root];
    path.push_back(weights[root]);
    if(target<0) return;
    if(tree[root]==nullptr){
        if(target==0){
            ans.push_back(path);
        }
        // path.pop_back();
        return;
    }
    for(auto&child:tree[root]->children){
        dfs(tree,child,target,ans,path,weights);
        path.pop_back();
    }
}

bool compare(const vector<int>&lhs,const vector<int>&rhs){
    int m=lhs.size(),n=rhs.size();
    int len=min(m,n);
    for(int i=0;i<len;i++){
        if(lhs[i]==rhs[i]) continue;;
        return lhs[i]>rhs[i];
    }
    return m>n;
}

int main(){
    int node_num,non_leaf_num,target;
    cin>>node_num>>non_leaf_num>>target;
    vector<int> weights(node_num);
    unordered_map<int,TreeNode*> tree;
    for(int i=0;i<node_num;i++){
        cin>>weights[i];
    }
    int root=0;
    int node_id,child_num;
    for(int i=0;i<non_leaf_num;i++){
        cin>>node_id>>child_num;
        TreeNode *p=new TreeNode(weights[node_id]);
        tree[node_id]=p;
        int child_id;
        for(int j=0;j<child_num;j++){
            cin>>child_id;
            p->children.push_back(child_id);
            if(tree[child_id]!=nullptr) continue;
            tree[child_id]=nullptr;
        }
    }

    vector<vector<int>> ans;
    vector<int>path;
    dfs(tree,0,target,ans,path,weights);
    sort(ans.begin(),ans.end(),compare);

    for(auto&vec:ans){
        for(int i=0;i<vec.size();i++){
            if(i==0) {
                cout<<vec[i];
                continue;
            }
            cout<<" "<<vec[i];
        }
        cout<<endl;
    }

    return 0;
}
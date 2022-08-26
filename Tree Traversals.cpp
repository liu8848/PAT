#include <iostream>
#include <vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value):val(value),left(nullptr),right(nullptr){}
};
TreeNode *buildTree(vector<int> &post, int pbegin, int pend,
                    vector<int> &inorder, int ibegin, int iend)
{
    if(pbegin > pend || ibegin > iend) return nullptr;
    TreeNode*root=new TreeNode(post[pend]);
    int i;
    for (i = ibegin; i <= iend; i++)
    {
        if (inorder[i] == post[pend])
            break;
    }
    int leftinend = i - 1, rightinbegin = i + 1;
    int leftpend = pbegin + (leftinend - ibegin);
    root->left=buildTree(post, pbegin, leftpend,
            inorder, ibegin, leftinend);
    root->right=buildTree(post, leftpend + 1, pend - 1,
            inorder, rightinbegin, iend);
    return root;
}

int main()
{
    int len;
    cin >> len;
    vector<int> post(len);
    vector<int> inorder(len);
    for (int i = 0; i < len; i++)
    {
        int num;
        cin >> num;
        post[i] = num;
    }
    for (int i = 0; i < len; i++)
    {
        int num;
        cin >> num;
        inorder[i] = num;
    }
    TreeNode*root=buildTree(post,0,len-1,inorder,0,len-1);
    queue<TreeNode*>que;
    que.push(root);
    while(!que.empty()){
        TreeNode*p=que.front();
        que.pop();
        cout<<p->val<<" ";
        if(p->left) que.push(p->left);
        if(p->right) que.push(p->right);
    }
    cout << endl;
    return 0;
}
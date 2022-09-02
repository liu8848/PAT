#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    int M,N,K;
    cin>>M>>N>>K;
    vector<int> st(M+1,-1);
    vector<int>nums(N+1,0);
    int top=0,buttom=0;
    for(int i=0;i<K;i++){
        for(int j=1;j<=N;j++){
            cin>>nums[j];
        }
        fill(st.begin(),st.end(),-1);
        top=0;
        int cur=1;
        int num=1;
        while (num<=N)
        {
            if(top!=0&&st[top]==nums[cur]){
                st[top]=-1;
                top--;
                cur++;
                continue;
            }
            if((++top)>M) {
                // cout<<"No"<<endl;
                break;
            }
            st[top]=num++;
        }
        while(top!=0){
            if(st[top]!=nums[cur]){
                // cout<<"No"<<endl;
                break;
            }
            st[top]=-1;
            top--;
            cur++;
        }
        if(cur>=N) cout<<"YES"<<endl;
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
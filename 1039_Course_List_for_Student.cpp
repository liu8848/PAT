#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    unordered_map<string,vector<int>> stu_cor_list;
    for(int i=0;i<K;i++){
        int cor_index,Ni;
        cin>>cor_index>>Ni;
        string name;
        for(int j=0;j<Ni;j++){
            cin>>name;
            stu_cor_list[name].push_back(cor_index);
        }
    }

    string query;
    for(int i=0;i<N;i++){
        cin>>query;
        cout<<query;
        cout<<" "<<stu_cor_list[query].size();
        sort(stu_cor_list[query].begin(),stu_cor_list[query].end());
        for(auto&cor:stu_cor_list[query]){
            cout<<" "<<cor;
        }
        cout<<endl;
    }
    return 0;
}
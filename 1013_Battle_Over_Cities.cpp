#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

void dfs(vector<vector<int>>&graph,vector<int>&vis,int lose,int cur){
    if(cur==lose||vis[cur]==1) return;
    vis[cur]=1;
    for(int i=0;i<graph[cur].size();i++){
        dfs(graph,vis,lose,graph[cur][i]);
    }
}


int main(){
    int N,M,K;
    string line;
    istringstream s;
    getline(cin,line);
    s.str(line);

    s>>N>>M>>K;

    vector<vector<int>>graph(N+1);
    vector<int> vis(N+1,0);
    for(int i=0;i<M;i++){
        getline(cin,line);
        s.clear();
        s.str(line);
        int c1,c2;
        s>>c1>>c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    
    getline(cin,line);
    s.clear();
    s.str(line);
    int lose;
    while(s>>lose){
        fill(vis.begin(),vis.end(),0);
        int cnt=0;
        for(int i=1;i<=N;i++){
            if(!vis[i]&&i!=lose){
                dfs(graph,vis,lose,i);
                cnt++;
            }
        }
        cout<<cnt-1<<endl;
    }
    return 0;
    
}
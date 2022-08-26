#include<iostream>
#include<vector>
#include<sstream>
#include<string>
using namespace std;

static int maxRescue=0;
static int cnt=0;
static int minLen=INT_MAX;
void dfs(vector<vector<int>>&graph,vector<int>&vis,vector<int>rescue,int start,int end,int Rescue,int len){
    if(vis[start]==1) return;
    vis[start]=1;
    Rescue+=rescue[start];
    if(start==end){
        if(len<minLen){
            minLen=len;
            cnt=1;
            maxRescue=max(Rescue,maxRescue);
        }else if(len==minLen){
            cnt++;
            maxRescue=max(Rescue,maxRescue);
        }
        vis[start]=0;
        return;
    }
    for(int i=0;i<graph.size();i++){
        if(i==start||vis[i]==1||graph[start][i]==0) continue;
        dfs(graph,vis,rescue,i,end,Rescue,len+graph[start][i]);
        vis[i]=0;
    }
    vis[start]=0;
}

int main(){
    int N,M,start,end;
    string line;
    getline(cin,line);
    istringstream s(line);
    s>>N>>M>>start>>end;
    vector<vector<int>> graph(N,vector<int>(N,0));
    vector<int>vis(N,0);
    vector<int> rescue(N,0);
    s.clear();
    getline(cin,line);
    s.str(line);
    for(int i=0;i<N;i++){
        s>>rescue[i];
    }
    int c1,c2,l;
    for(int i=0;i<M;i++){
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>c1>>c2>>l;
        graph[c1][c2]=l;
        graph[c2][c1]=l;
    }
    dfs(graph,vis,rescue,start,end,0,0);
    cout<<cnt<<" "<<maxRescue; 
    return 0;
}
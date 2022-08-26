#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

static int mincost=INT_MAX;
static int mindis=INT_MAX;


void dfs(vector<vector<pair<int,int>>>&cities,vector<int>&vis,vector<int>&path,vector<int>&temp,int cur,int target,int dis,int cost){
    if(vis[cur]==1) return;
    vis[cur]=1;
    temp.push_back(cur);
    if(cur==target){
        if(dis<mindis){
            mindis=dis;
            mincost=cost;
            path.assign(temp.begin(),temp.end()); 
        }else if(dis==mindis){
            if(cost<mincost){
                mindis=dis;
                mincost=cost;
                path.assign(temp.begin(),temp.end()); 
            }
        }
        return;
    }
    for(int i=0;i<cities[cur].size();i++){
        if(cities[cur][i].first>0){
            if(vis[i]==1) continue;
            dfs(cities,vis,path,temp,i,target,dis+cities[cur][i].first,cost+cities[cur][i].second);
            vis[i]=0;
            temp.pop_back();
        }
    }
}

int main(){
    string line;
    istringstream s;
    int N,M,start,des;
    getline(cin,line);
    s.str(line);
    s>>N>>M>>start>>des;
    vector<int>vis(N,0);
    vector<vector<pair<int,int>>>cities(N,vector<pair<int,int>>(N));
    for(int i=0;i<M;i++){
        int begin,end,dis,cost;
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>begin>>end>>dis>>cost;
        cities[begin][end].first=dis;
        cities[begin][end].second=cost;
        cities[end][begin].first=dis;
        cities[end][begin].second=cost;
    }
    vector<int>path;
    vector<int> temp;
    dfs(cities,vis,path,temp,start,des,0,0);
    for(auto c:path){
        cout<<c<<" ";
    }
    cout<<mindis<<" "<<mincost;
    return 0;
}
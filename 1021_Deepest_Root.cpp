#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

void dfs_vis(vector<vector<int>> &graph, vector<int> &vis, int cur)
{
    vis[cur] = 1;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (graph[cur][i] > 0 && vis[graph[cur][i]] == 0)
        {
            dfs_vis(graph, vis, graph[cur][i]);
        }
    }
}

int dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int>&deep,int d,int root,int cur)
{
    vis[cur] = 1;
    int maxdepth=0;
    for (int i = 0; i < graph[cur].size(); i++)
    {
        if (graph[cur][i] > 0 && vis[graph[cur][i]] == 0)
        {
            deep[root]=max(deep[root],d+1);
            dfs(graph, vis, deep,d+1,root,graph[cur][i]);
        }
    }
    return maxdepth;
}

int main()
{
    string line;
    istringstream s;
    int N;
    getline(cin, line);
    s.str(line);
    s >> N;
    vector<int> vis(N + 1, 0);
    vector<vector<int>> graph(N + 1);
    int c1, c2;
    for (int i = 0; i < N - 1; i++)
    {
        getline(cin, line);
        s.clear();
        s.str(line);
        s >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    int connect_graph = 0;
    for (int i = 1; i <= N; i++)
    {
        if (vis[i] == 0)
        {
            dfs_vis(graph, vis, i);
            connect_graph++;
        }
    }

    if (connect_graph > 1)
    {
        cout << "Error: " << connect_graph << " components";
        return 0;
    }

    vector<int> deep(N+1,1);
    for(int i=1;i<=N;i++){
        fill(vis.begin(), vis.end(), 0);
        dfs(graph,vis,deep,1,i,i);
    }
    auto it=max_element(deep.begin(),deep.end());
    for(int i=1;i<=N;i++){
        if(deep[i]==*it){
            cout<<i<<endl;
        }
    }

    return 0;
}
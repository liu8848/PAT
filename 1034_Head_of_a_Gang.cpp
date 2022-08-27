#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string head;
int cnt,total;  //每次遍历的点数和总权值
map<string,int> weight;//此处记录每个接地点的权值
map<string,bool> visit; //是否访问
map<string,vector<string>> adjlist;//用临接表来存图
map<string,int> res;
void DFS(string start){
    visit[start] = true;
    cnt++;  //遍历的点数
    total += weight[start];
    if(weight[start] > weight[head])head = start;
    for(vector<string>::iterator it = adjlist[start].begin();it != adjlist[start].end();it++){
        if(visit[*it] == false)
            DFS(*it);
    }
}
int main(){
    int N, K, T,i = 0;
    cin >> N >> K;
    string member1,member2;
    while (i < N){
        cin >> member1 >> member2 >> T;
        weight[member1] += T;
        weight[member2] += T;
        adjlist[member1].push_back(member2);
        adjlist[member2].push_back(member1);
        visit[member1] = false;
        visit[member2] = false;
        i++;
    }
    for (map<string,bool>::iterator it = visit.begin();it != visit.end();it++) {
        if(it->second == false){
            total = 0,cnt = 0,head = it->first;
            DFS(it->first);
        }
        if(cnt > 2 && total/2 > K)res[head] = cnt;
    }
    cout<<res.size() << endl;
    for (map<string,int>::iterator it = res.begin();it != res.end();it++) {
        cout << it-> first << " " << it->second << endl;
    }
    return 0;
}

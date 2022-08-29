#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

int main(){
    string line;
    int num;
    getline(cin,line);
    int N;
    istringstream s(line);
    s>>N;
    unordered_map<int,pair<int,int>>mp;
    int i=0;
    while(s>>num){
        mp[num].first=i++;
        mp[num].second++;
    }
    int ans=-1;
    for(auto&[n,p]:mp){
        if(p.second==1){
            if(ans==-1) {
                ans=n;
                continue;
            }
            if(mp[ans].first>p.first){
                ans=n;
            }
        }
    }
    if(ans==-1) cout<<"None";
    else cout<<ans;
    return 0;
}
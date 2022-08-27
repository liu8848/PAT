#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
#include<string>
using namespace std;

static unordered_map<char,char> mp{{'1','@'},{'0','%'},{'l','L'},{'O','o'}};

int main(){
    vector<pair<string,string>> account;
    int N;
    cin>>N;
    string user,password;
    for(int i=0;i<N;i++){
        cin>>user>>password;
        int cnt=0;
        for(auto&c:password){
            if(c=='1'||c=='0'||c=='l'||c=='O'){
                c=mp[c];
                cnt++;
            }
        }
        if (cnt>0)
        {
            account.push_back({user,password});
        }
    }
    if(account.size()<=0){
        if(N>1)
            cout<<"There are "<<N<<" accounts and no account is modified"<<endl;
        else if(N==1){
            cout<<"There is "<<N<<" account and no account is modified"<<endl;
        }
        return 0;
    }
    cout<<account.size()<<endl;
    for(int i=0;i<account.size();i++){
       cout<<account[i].first<<" "<<account[i].second<<endl; 
    }
    return 0;
}
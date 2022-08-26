#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<char,string>mp({
        {'0',"zero"},{'1',"one"},{'2',"two"},{'3',"three"},{'4',"four"},{'5',"five"},
        {'6',"six"},{'7',"seven"},{'8',"eight"},{'9',"nine"}
    });
    string line;
    getline(cin,line);
    int sum=0;
    for(auto&c:line){
        int num=c-'0';
        sum+=num;
    }
    string result=to_string(sum);
    string ans="";
    for(auto&c:result){
        ans+=mp[c]+" ";
    }
    ans=ans.substr(0,ans.size()-1);
    cout<<ans;
    return 0;
}
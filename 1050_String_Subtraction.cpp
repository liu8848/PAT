#include<iostream>
#include<vector>
#include<unordered_map>
#include<sstream>
#include<stdio.h>
using namespace std;

int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    // unordered_map<char,int>mp;
    vector<bool> flag(256,true);
    for(auto&c:s2){
        flag[c]=false;
    }

    for(auto&c:s1){
        if(!flag[c]) continue;
        // s.push_back(c);
        printf("%c",c);
    }
    cout<<endl;
    return 0;
}
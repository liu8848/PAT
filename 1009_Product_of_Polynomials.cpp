#include<iostream>
#include<sstream>
#include<string>
#include<map>
#include<functional>
#include<stdio.h>
using namespace std;

int main(){
    map<int,double,greater<int>> mp1;
    map<int,double,greater<int>> mp2;
    map<int,double,greater<int>> ans;

    string line;
    istringstream s;
    getline(cin,line);
    s.str(line);
    int n,index;
    double num;
    s>>n;
    for(int i=0;i<n;i++){
        s>>index>>num;
        mp1[index]=num;
    }

    getline(cin,line);
    s.clear();
    s.str(line);

    s>>n;
    for(int i=0;i<n;i++){
        s>>index>>num;
        mp2[index]=num;
    }

    for(auto&[i1,n1]:mp1){
        for(auto&[i2,n2]:mp2){
            int i=i1+i2;
            double nu=n1*n2;
            ans[i]+=nu;
            if(ans[i]==0){
                ans.erase(i);
            }
        }
    }
    cout<<ans.size();
    for(auto it=ans.begin();it!=ans.end();it++){
        printf(" %d %.1f",it->first,it->second);
    }
    return 0;
}
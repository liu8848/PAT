#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<set>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
    int N,K;
    // map<int,set<string>> courses;
    map<int,vector<string>>courses;
    scanf("%d %d",&N,&K);
    string name;
    int class_num,class_id;
    for(int i=0;i<N;++i){
        cin>>name>>class_num;
        // scanf("%s",&name);
        for(int j=0;j<class_num;++j){
            scanf("%d",&class_id);
            courses[class_id].push_back(name);
        }
    }
    for(int i=1;i<=K;i++){
        cout<<i<<" "<<courses[i].size()<<endl;
        sort(courses[i].begin(),courses[i].end());
        for(auto&stu_name:courses[i]){
            printf("%s\n",stu_name.c_str());
        }
    }
    return 0;
}
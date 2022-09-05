#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

int main(){
    string line;
    getline(cin,line);
    for(auto&c:line){
        if(c=='.') c=' ';
    }
    istringstream s(line);
    vector<vector<int>>nums(2,vector<int>(3,0));
    for(int i=0;i<2;++i){
        for(int j=0;j<3;++j){
            s>>nums[i][j];
        }
    }
    vector<int> ans(3,0);
    int tag=0;
    int sum=nums[0][2]+nums[1][2];
    ans[2]=sum%29;
    tag=sum/29;
    sum=nums[0][1]+nums[1][1]+tag;
    ans[1]=sum%17;
    tag=sum/17;
    ans[0]=nums[0][0]+nums[1][0]+tag;
    cout<<ans[0]<<"."<<ans[1]<<"."<<ans[2]<<endl;
    return 0;
}
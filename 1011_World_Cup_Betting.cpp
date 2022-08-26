#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<stdio.h>
using namespace std;

int main(){
    string line;
    float maxO[3]={0,0,0};
    vector<string> dic{"W","T","L"};
    int midx[3]={0,0,0};
    istringstream s;
    for(int i=0;i<3;i++){
        getline(cin,line);
        s.clear();
        s.str(line);
        for(int j=0;j<3;j++){
            float ood;
            s>>ood;
            if(maxO[i]<ood){
                maxO[i]=ood;
                midx[i]=j;
            }
        }
    }
    float result=(maxO[0]*maxO[1]*maxO[2]*0.65-1)*2;
    printf("%s %s %s %.2f",dic[midx[0]].c_str(),dic[midx[1]].c_str(),dic[midx[2]].c_str(),result);
    return 0;
}
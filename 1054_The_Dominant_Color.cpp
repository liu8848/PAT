#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int M,N;
    cin>>M>>N;
    long long capacity=M*N/2;

    long long pixel;
    long long domain;
    unordered_map<long long,long long> mp;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>pixel;
            mp[pixel]++;
            if(mp[pixel]>=capacity) {
                domain=pixel;
            }
        }
    }
    cout<<domain<<endl;
    return 0;
}
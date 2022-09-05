#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main(){
    long long N;
    cin>>N;
    vector<int> prime(500000,1);
    for(int i=2;i*i<500000;i++){
        for(int j=2;j*i<500000;j++){
            prime[j*i]=0;
        }
    }
    cout<<N<<"=";
    if(N==1) cout<<1;
    bool state=false;

    for(int i=2;N>=2;i++){
        int cnt=0,flag=0;
        while(prime[i]==1&&N%i==0){
            cnt++;
            N/=i;
            flag=1;
        }
        if(flag){
            if (state)
            {
                cout<<"*";
            }
            cout<<i;
            state=true;
        }
        if(cnt>=2){
            cout<<"^"<<cnt;
        }
    }
    return 0;
}
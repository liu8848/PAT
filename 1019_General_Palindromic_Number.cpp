#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void convert(vector<long long>&res,long long num,long long radix){
    while (num>0)
    {
        res.emplace_back(num%radix);
        num/=radix;
    }
}

long long recover(vector<long long>&res,long long radix){
    long long ans=0;
    for(int i=0;i<res.size();i++){
        ans=ans*radix+res[i];
    }
    return ans;
}

int main(){
    long long num,radix;
    cin>>num>>radix;
    vector<long long> res;
    convert(res,num,radix);
    long long num1=recover(res,radix);
    if(num!=num1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    for(int i=res.size()-1;i>=0;i--){
        if(i==0){
            cout<<res[i];
        }else{
            cout<<res[i]<<" ";
        }
    }
    return 0;
}
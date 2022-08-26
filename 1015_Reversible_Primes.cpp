#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int reversNum(int num,int radix){
    vector<int> res;
    while (num>0)
    {
        res.push_back(num%radix);
        num/=radix;
    }
    int ans=0;
    for(int i=0;i<res.size();i++){
        ans=ans*radix+res[i];
    }
    return ans;
}


int main(){
    string line;
    istringstream s;
    int num,d;
    while(1){
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>num>>d;
        if(num<0) break;
        if(!isPrime(num)){
            cout<<"No"<<endl;
            continue;
        }
        num=reversNum(num,d);
        if(isPrime(num)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
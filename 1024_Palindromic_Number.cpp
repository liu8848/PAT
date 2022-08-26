#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool isPalindromic(vector<int>&num,vector<int>&res){
    for(int i=0;i<num.size();i++){
        if(num[i]!=res[i])
            return false;
    }
    return true;
}

void plus_(vector<int>&num,vector<int>&res){
    int tag=0;
    for(int i=num.size()-1;i>=0;i--){
        int sum=num[i]+res[i]+tag;
        num[i]=sum%10;
        tag=sum/10;
    }
    if(tag>0){
        num.insert(num.begin(),tag);
    }
}

int main(){
    string n;
    int K;
    cin>>n>>K;
    vector<int> nums;
    for(auto&c:n){
        nums.emplace_back(c-'0');
    } 
    int step=0;
    while(step<K){
        vector<int>res(nums.begin(),nums.end());
        reverse(res.begin(),res.end());
        if(isPalindromic(nums,res)) break;
        plus_(nums,res);
        step++;
    }
    for(auto i:nums){
        cout<<i;
    }
    cout<<endl;
    cout<<step;
    return 0;
}
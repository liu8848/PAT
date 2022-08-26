#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int main(){
    long long num;
    cin>>num;
    set<int> num_set;
    vector<int> tmp;
    int tag=0;
    while(num>0){
        int number=num%10;
        num/=10;
        num_set.insert(number);
        int sum=2*number+tag;
        tmp.push_back(sum%10);
        tag=sum/10;
    }
    for(auto&n:tmp){
        if(num_set.find(n)==num_set.end()){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=tmp.size()-1;i>=0;i--){
        cout<<tmp[i];
    }
    return 0;
}
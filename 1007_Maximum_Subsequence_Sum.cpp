#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main(){
    string line;
    istringstream s;
    getline(cin,line);
    int n;
    s.str(line);
    s>>n;
    vector<int> nums(n);
    getline(cin,line);
    s.clear();
    s.str(line);
    int maxi=0,maxj=0;
    int temp=0;
    int tempj=0,sum=-1;
    for(int i=0;i<n;i++){
        s>>nums[i];
        temp+=nums[i];
        if(temp<0){
            tempj=i+1;
            temp=0;
        }else if(temp>sum){
            sum=temp;
            maxi=tempj;
            maxj=i;
        }
    }
    if(sum<0) sum=0;
    cout<<sum<<" "<<nums[maxi]<<" "<<nums[maxj];

    return 0;
}
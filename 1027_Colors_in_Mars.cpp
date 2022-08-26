#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

static map<int,char> mp({{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},
                    {6,'6'},{7,'7'},{8,'8'},{9,'9'},{10,'A'},{11,'B'},{12,'C'}});

string convert(int num,int radix){
    string res;
    while(num>0){
        int m=num%radix;
        res.push_back(mp[m]);
        num/=radix;
    }
    reverse(res.begin(),res.end());
    if(res.size()<=1){
        res.insert(res.begin(),'0');
    }
    return res;
}

int main(){
    int red,green,blue;
    cin>>red>>green>>blue;
    cout<<'#'<<(red==0?"00":convert(red,13))<<(green==0?"00":convert(green,13))<<(blue==0?"00":convert(blue,13));
    return 0;
}
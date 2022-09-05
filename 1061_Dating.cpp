#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using  namespace std;

unordered_map<char,string>mp{{'A',"MON"},{'B',"TUE"},{'C',"WED"},{'D',"THU"},{'E',"FRI"},
                                    {'F',"SAT"},{'G',"SUN"}};

int main(){
    string day1,day2,hour,minute;
    cin>>day1>>day2>>hour>>minute;
    int len=min(day1.size(),day2.size());
    int i=0;
    for(;i<len;++i){
        if(day1[i]==day2[i]){
            if(mp.find(day1[i])!=mp.end()){
                cout<<mp[day1[i]]<<" ";
                i++;
                break;
            }
        }
    }
    for(int j=0;i<len;++j,++i){
        if(day1[i]==hour[j]){
            if(day1[i]>='0'&&day1[i]<='9'){
                cout<<day1[i]<<":";
                i++;
                break;
            }
            else if(day1[i]>='A'&&day1[i]<='N'){
                cout<<(9+day1[i]-'A')<<":";
                i++;
                break;
            }
        }
    }
    for(int j=0;j<len;++j){
        
    }

}
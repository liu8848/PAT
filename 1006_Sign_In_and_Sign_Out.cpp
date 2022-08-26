#include<iostream>
#include<string>
#include<set>
#include<ctime>
#include<sstream>
using namespace std;

class mytime{
public:
    int h;
    int m;
    int s;
    mytime():h(0),m(0),s(0){};
    mytime(int hour,int minute,int second):h(hour),m(minute),s(second){}
    // bool operator>(const mytime&rhs){
    //     if(this->h>rhs.h){
    //         return true;
    //     }else if(this->h<rhs.h){
    //         return false;
    //     }else{
    //         if(this->m>rhs.m) return true;
    //         else if(this->m<rhs.m) return false;
    //     }
    //     return this->s>rhs.s;
    // }

    mytime*operator=(mytime*val){
        return val;
    }
    mytime operator*(){
        return *this;
    }
};

bool operator>(const mytime&lhs,const mytime&rhs){
    if(lhs.h>rhs.h){
            return true;
    }else if(lhs.h<rhs.h){
            return false;
    }else{
            if(lhs.m>rhs.m) return true;
            else if(lhs.m<rhs.m) return false;
            else return false;
    }
    return lhs.s>rhs.s;

}

int main(){
    string line;
    int N;
    istringstream s;
    istringstream s1;
    getline(cin,line);
    s.str(line);
    s>>N;
    string firstUser="",lastUser="";
    mytime*openTime,*closeTime;
    for(int i=0;i<N;i++){
        s.clear();
        getline(cin,line);
        s.str(line);
        string user,begin,end;
        s>>user>>begin>>end;
        int hour=0,minute=0,second=0;
        s1.clear();
        s1.str(begin);
        s1>>hour>>minute>>second;
        mytime *t1=new mytime(hour,minute,second);

        s1.clear();
        s1.str(end);
        hour=0,minute=0,second=0;
        s1>>hour>>minute>>second;
        mytime *t2=new mytime(hour,minute,second);
        if(firstUser==""){
            firstUser=user;
            lastUser=user;
            openTime=t1;
            closeTime=t2;
            continue;
        }
        if(*openTime>*t1){
            firstUser=user;
            openTime=t1;
        }
        if(*t2>(*closeTime)){
            lastUser=user;
            closeTime=t2;
        }
    }
    cout<<firstUser<<" "<<lastUser;
    return 0;
}
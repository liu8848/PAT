#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
#include<set>
#include<algorithm>
#include<time.h>
using namespace std;

class customer
{
public:
    int hh = 0;
    int mm = 0;
    int ss = 0;
    int ser = 0;
    customer() = default;
    customer(int hour, int minute, int second, int serve) : hh(hour), mm(minute), ss(second), ser(serve>=60?60:serve) {}
    bool operator<(const customer&val){
        if(this->hh<val.hh){
            return true;
        }else if(this->hh>val.hh){
            return false;
        }else{
            if(this->mm<val.mm){
                return true;
            }else if(this->mm>val.mm){
                return false;
            }else{
                return this->ss<val.ss;
            }
        }
        return true;
    }
};

struct person
{
    int arrival_time;
    int serve_time;
    person(int hour,int minute,int second,int t){
        arrival_time=3600*hour+minute*60+second;
        serve_time=t>=60?3600:t*60;
    }
};

bool operator<(const person&lhs,const person &rhs){
    return lhs.arrival_time<rhs.arrival_time;
}

bool operator<(const customer &lhs, const customer &rhs)
{
    if (lhs.hh < rhs.hh)
    {
        return true;
    }
    else if (lhs.hh > rhs.hh)
    {
        return false;
    }
    else
    {
        if (lhs.mm < rhs.mm)
        {
            return true;
        }
        else if (lhs.mm > rhs.mm)
        {
            return false;
        }
        else
        {
            return lhs.ss < rhs.ss;
        }
    }
}

float operator-(const customer&lhs,const customer&rhs){
    int hour=lhs.hh-rhs.hh-1;
    int minute=lhs.mm-rhs.mm+60-1;
    int second=lhs.ss-rhs.ss+60;
    return hour*60+minute+second*1.0/60;
}

int main()
{
    string line, time;
    istringstream s, t;
    int N,K;
    getline(cin, line);
    s.str(line);
    s>>N>>K;
    int servtime;
    // set<customer> customer_set;
    set<person> person_set;
    for(int i=0;i<N;i++){
        getline(cin,line);
        s.clear();
        s.str(line);
        s >> time >> servtime;
        int hour = 0, minute = 0, second = 0;
        for(auto&c:time){
            c=c==':'?' ':c;
        }
        t.clear();
        t.str(time);
        t >> hour >> minute >> second;
        person p(hour,minute,second,servtime);
        person_set.insert(p);
        // customer c(hour, minute, second, servtime);
        // customer_set.insert(c);
    }
    // vector<customer> window(K,customer(8,0,0,0));
    vector<person> window(K,person(8,0,0,0));

    float waiting=0;
    int cnt=0;
    // const customer end_c(17,0,0,0);
    const person end_p(17,0,0,1);
    for(auto it=person_set.begin();it!=person_set.end();it++){
        if(end_p<*it) break;
        cnt++;
        auto vec_it=min_element(window.begin(),window.end());
        int index=vec_it-window.begin();
        if(window[index].arrival_time>(*it).arrival_time){
            waiting+=(window[index].arrival_time-(*it).arrival_time);
            window[index].arrival_time=window[index].arrival_time+(*it).serve_time;
        }else{
            window[index].arrival_time=(*it).arrival_time+(*it).serve_time;
        }
        // int ser_minute=window[index].mm+(*it).ser;
        // window[index].hh=window[index].hh+ser_minute/60;
        // window[index].mm=ser_minute%60;       
    }
    printf("%.1f",waiting/cnt/60);
    return 0;
}
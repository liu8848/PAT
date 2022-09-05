#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct person
{
    string ID;
    int VG;
    int TG;
    int Total;
    int Type;
    person()=default;
    person(string id,int vg,int tg,int H):ID(id),VG(vg),TG(tg){
        Total=vg+tg;
        if(VG>=H&&TG>=H) {
            Type=1;
        }
        else if(VG>=H&&TG<H) {
            Type=2;
        }
        else if((VG<H&&TG<H)&&VG>=TG) {
            Type=3;
        }
        else {
            Type=4;
        }
    };
};


int main(){
    int N,L,H;
    cin>>N>>L>>H;
    string id;
    int vg,tg;
    vector<person> list;
    for(int i=0;i<N;++i){
        cin>>id>>vg>>tg;
        if(vg<L||tg<L) continue;
        person p(id,vg,tg,H);
        list.emplace_back(p);
    }
    sort(list.begin(),list.end(),[&H](const person&lhs,const person&rhs){
        switch (lhs.Type)
        {
        case 1:{
            switch (rhs.Type)
            {
            case 1:
                if(lhs.Total==rhs.Total){
                    if(lhs.VG==rhs.VG)
                        return lhs.ID<rhs.ID;
                    return lhs.VG>rhs.VG;
                } 
                return lhs.Total>rhs.Total;
                break;
            default:
                return true;
                break;
            }
        }
        break;
        case 2:{
            switch (rhs.Type)
            {
            case 1:
                return false;
                break;
            case 2:
                if(lhs.Total==rhs.Total){
                    if(lhs.VG==rhs.VG)
                        return lhs.ID<rhs.ID;
                    return lhs.VG>rhs.VG;
                } 
                return lhs.Total>rhs.Total;
            default:
                return true;
                break;
            }
        }
        case 3:{
            switch (rhs.Type)
            {
            case 1:
                return false;
                break;
            case 2:
                return false;
            case 3:
                if(lhs.Total==rhs.Total){
                    if(lhs.VG==rhs.VG)
                        return lhs.ID<rhs.ID;
                    return lhs.VG>rhs.VG;
                } 
                return lhs.Total>rhs.Total;
            default:
                return true;
                break;
            }
        }
        case 4:
            switch (rhs.Type)
            {
            case 4:
                if(lhs.Total==rhs.Total){
                    if(lhs.VG==rhs.VG)
                        return lhs.ID<rhs.ID;
                    return lhs.VG>rhs.VG;
                } 
                return lhs.Total>rhs.Total;
            default:
                return false;
                break;
            }
        }
    });

    cout<<list.size()<<endl;
    for(auto&p:list){
        cout<<p.ID<<" "<<p.VG<<" "<<p.TG<<endl;
    }
    return 0;
}
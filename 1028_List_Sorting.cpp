#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;

struct recode
{
    string ID;
    string NAME;
    int socre;
    recode(int id,string name,int s):NAME(name),socre(s){
        string id_=to_string(id);
        string zero(6-id_.size(),'0');
        ID=zero+id_;
    }
};
bool sortByID(const recode&lhs,const recode&rhs){
    return lhs.ID<rhs.ID;
}
bool sortByName(const recode&lhs,const recode&rhs){
    if(lhs.NAME==rhs.NAME) return lhs.ID<rhs.ID;
    for(int i=0;i<lhs.NAME.size()&&i<rhs.NAME.size();i++){
        if(lhs.NAME[i]<rhs.NAME[i]) return true;
        else if(lhs.NAME[i]>rhs.NAME[i]) return false;
        else continue;
    }
    return lhs.NAME.size()<rhs.NAME.size();
    
}
bool sortByScore(const recode&lhs,const recode&rhs){
    if(lhs.socre==rhs.socre) return lhs.ID<rhs.ID;
    return lhs.socre<rhs.socre;
}

int main(){
    string line;
    istringstream s;
    int N,C;
    getline(cin,line);
    s.str(line);
    s>>N>>C;
    vector<recode> recodes;
    for(int i=0;i<N;i++){
        int id,socre;
        string name;
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>id>>name>>socre;
        recode rec(id,name,socre);
        recodes.emplace_back(rec);
    }
    using func=bool(*)(const recode&,const recode&);
    vector<func> funcs({sortByID,sortByName,sortByScore});
    sort(recodes.begin(),recodes.end(),funcs[C-1]);

    for(auto&rec:recodes){
        cout<<rec.ID<<" "<<rec.NAME<<" "<<rec.socre<<endl;
    }

    return 0;


}
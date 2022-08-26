#include<iostream>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct client
{
    string id_;
    int score_;
    int loc_num;
    int final_rank=0;
    int local_rank=0;
    client(string id,int score,int loc):id_(id),score_(score),loc_num(loc){}
};


int findSort(vector<int>&s,int target){
    auto it=find(s.begin(),s.end(),target);
    int n=it-s.begin()+1;
    return n;
}

int main(){
    int loc;
    string line;
    istringstream s;
    getline(cin,line);
    s.str(line);
    s>>loc;
    vector<vector<int>> loc_score(loc);
    vector<int> total_score;
    vector<client> vec;
    int n;
    for(int i=0;i<loc;i++){
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>n;
        string id;
        int score;
        for(int j=0;j<n;j++){
            getline(cin,line);
            s.clear();
            s.str(line);
            s>>id>>score;
            loc_score[i].push_back(score);
            total_score.push_back(score);
            client c(id,score,i);
            vec.push_back(c);
        }
        sort(loc_score[i].begin(),loc_score[i].end(),greater<int>());
    }
    sort(total_score.begin(),total_score.end(),greater<int>());
    sort(vec.begin(),vec.end(),[](const client&lhs,const client&rhs){
        return lhs.id_<rhs.id_;
    });
    for(int i=0;i<vec.size();i++){
        vec[i].local_rank=findSort(loc_score[vec[i].loc_num],vec[i].score_);
        vec[i].final_rank=findSort(total_score,vec[i].score_);
    }
    sort(vec.begin(),vec.end(),[](const client&lhs,const client &rhs){return (lhs.final_rank<rhs.final_rank);});
    cout<<vec.size()<<endl;
    for(auto&c:vec){
        cout<<c.id_<<" "<<c.final_rank<<" "<<c.loc_num+1<<" "<<c.local_rank<<endl;
    }
    return 0;
}
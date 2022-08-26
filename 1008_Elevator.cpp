#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    string line;
    istringstream s;
    getline(cin,line);
    s.str(line);
    int cost=0;
    int prelevel=0;
    int level;
    int N;
    s>>N;
    for(int i=0;i<N;i++){
        s>>level;
        if(level>prelevel){
            cost+=(6*(level-prelevel));
        }else{
            cost+=(4*(prelevel-level));
        }
        prelevel=level;
        cost+=5;
    }

    cout<<cost;

    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct person
{
    char* Name;
    int Age;
    long long Net_Worth;
    // person():Name(""),Age(0),Net_Worth(0){}
    person()=default;
    person(char* name,int age,long long net_worth):Name(name),Age(age),Net_Worth(net_worth){}
};

bool operator<(const person&lhs,const person&rhs){
    if(lhs.Net_Worth==rhs.Net_Worth){
        if(lhs.Age==rhs.Age){
            int com=strcmp(lhs.Name,rhs.Name);
            return com<0;
        }
        return lhs.Age<rhs.Age;
    }
    return lhs.Net_Worth>rhs.Net_Worth;
}

int main(){
    int N,K;
    cin>>N>>K;
    vector<person> vec(N);
    int age;
    long long net_worth;
    for(int i=0;i<N;++i){
        char* name=new char[9];
        scanf("%s%d%lld",name,&vec[i].Age,&vec[i].Net_Worth);
        vec[i].Name=name;
    }
    sort(vec.begin(),vec.end());
    
    vector<int>book(210,0);
    vector<person> vec1;
    for(int i=0;i<N;++i){
        if(book[vec[i].Age]<=100){
            book[vec[i].Age]++;
            vec1.emplace_back(vec[i]);
        }
    }

    int M,Amin,Amax;
    for(int i=0;i<K;++i){
        scanf("%d%d%d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i+1);
        bool tag=false;
        for(int j=0;j<vec1.size();++j){
            if(vec1[j].Age>=Amin&&vec1[j].Age<=Amax&&M>0){
                printf("%s %d %lld\n",vec1[j].Name,vec1[j].Age,vec1[j].Net_Worth);
                M--;
                tag=true;
            }
        }
        if(!tag) printf("None\n");
    }
    return 0;
}
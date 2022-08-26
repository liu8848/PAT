#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct book
{
    string ID;
    string title;
    string author;
    vector<string> keyword;
    string publisher;
    int year;
    book(string id,string t,string a,string words,string p,int y):ID(id),title(t),author(a),publisher(p),year(y){
        istringstream s(words);
        string word;
        while(s>>word){
            keyword.emplace_back(word);
        }
    }
};

int main(){
    string line;
    istringstream s;
    int N;
    getline(cin,line);
    s.str(line);
    s>>N;
    vector<book> books;
    string id,title,author,keyword,publisher;
    int year;
    for(int i=0;i<N;i++){
        for(int i=1;i<7;i++){
            switch (i)
            {
            case 1:
                getline(cin,id);
                break;
            case 2:
                getline(cin,title);
                break;
            case 3:
                getline(cin,author);
                break;
            case 4:
                getline(cin,keyword);
                break;
            case 5:
                getline(cin,publisher);
                break;
            case 6:
                getline(cin,line);
                year=atoi(line.c_str());
            }
        }
        book b(id,title,author,keyword,publisher,year);
        books.push_back(b);
    }
    sort(books.begin(),books.end(),[](book lhs,book rhs){return lhs.ID<rhs.ID;});
    int M;
    getline(cin,line);
    M=atoi(line.c_str());
    for(int i=0;i<M;i++){
        getline(cin,line);
        cout<<line<<endl;
        int op=atoi(line.substr(0,1).c_str());
        string query=line.substr(3,line.size()-3);
        int cnt=0;
        switch (op)
        {
        case 1:
            
            for(auto&b:books){
                if(b.title==query){
                    cnt++;
                    cout<<b.ID<<endl;
                }
            }
            if(!cnt) cout<<"Not Found"<<endl;
            break;
        case 2:
            
            for(auto&b:books){
                if(b.author==query){
                    cnt++;
                    cout<<b.ID<<endl;
                }
            }
            if(!cnt) cout<<"Not Found"<<endl;
            break;
        case 3:
            
            for(auto&b:books){
                if(find(b.keyword.begin(),b.keyword.end(),query)!=b.keyword.end()){
                    cnt++;
                    cout<<b.ID<<endl;
                }
            }
            if(!cnt) cout<<"Not Found"<<endl;
            break;
        case 4:
            
            for(auto&b:books){
                if(b.publisher==query){
                    cnt++;
                    cout<<b.ID<<endl;
                }
            }
            if(!cnt) cout<<"Not Found"<<endl;
            break;
        case 5:
            
            for(auto&b:books){
                if(b.year==atoi(query.c_str())){
                    cnt++;
                    cout<<b.ID<<endl;
                }
            }
            if(!cnt) cout<<"Not Found"<<endl;
        }
    }
    return 0;
}

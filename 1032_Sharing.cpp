#include<string>
#include<iostream>
#include<sstream>
#include<unordered_map>
using namespace std;

struct Node
{
    string address_;
    string val_;
    string n_address_;
    Node(){};
    Node(string address,string val,string n_address):address_(address),val_(val),n_address_(n_address){}
};


int main(){
    unordered_map<string,Node> mp;
    string line;
    istringstream s;
    string head1,head2;
    int N;
    getline(cin,line);
    s.str(line);
    s>>head1>>head2>>N;
    string address,val,next;
    for(int i=0;i<N;i++){
        s.clear();
        getline(cin,line);
        s.str(line);
        s>>address>>val>>next;
        Node node(address,val,next);
        mp[address]=node;
    }
    string p1=head1,p2=head2;
    while(p1!=p2){
        p1=(p1=="-1")?head2:(mp[p1].n_address_);
        p2=(p2=="-1")?head1:(mp[p2].n_address_);
    }
    cout<<p1;
    return 0;

}
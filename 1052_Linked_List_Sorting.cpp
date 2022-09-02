#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode
{
    string ID;
    int Key;
    string Next;
    ListNode() : ID("00000"), Key(0), Next("-1"){};
    ListNode(string id, int key, string next) : ID(id), Key(key), Next(next){};
};

bool operator<(const ListNode &lhs, const ListNode &rhs)
{
    return lhs.Key < rhs.Key;
}

int main()
{
    int N;
    string head;
    cin >> N >> head;

    vector<ListNode> list;
    unordered_map<string, ListNode> mp;
    string id, next;
    int key;
    for (int i = 0; i < N; i++)
    {
        cin >> id >> key >> next;
        ListNode l(id, key, next);
        mp[id]=l;
    }
    while(head!="-1"){
        list.push_back(mp[head]);
        head=mp[head].Next;
    }

    sort(list.begin(), list.end());
    if(list.size()==0){
        // cout << list.size() << " " << "-1"<< endl;
        printf("%d %s\n",list.size(),"-1");
        return 0;
    }
    // cout << list.size() << " " << list[0].ID << endl;
    printf("%d %s\n",list.size(),list[0].ID.c_str());
    for (int i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            // cout << list[i].ID << " " << list[i].Key << " "<< "-1" << endl;
            printf("%s %d %s\n",list[i].ID.c_str(),list[i].Key,"-1");
            break;
        }
        // cout << list[i].ID << " " << list[i].Key << " " << list[i + 1].ID << endl;
        printf("%s %d %s\n",list[i].ID.c_str(),list[i].Key,list[i+1].ID.c_str());
    }
    return 0;
}

// string sortList(unordered_map<string,ListNode>&mp,string head){
//     if(head=="-1"||mp[head].Next=="-1") return head;
//     string fast=mp[head].Next;
//     string slow=head;
//     while(fast!="-1"&&mp[fast].Next!="-1"){
//         slow=mp[slow].Next;
//         fast=mp[mp[fast].Next].Next;
//     }
//     string tmp=mp[slow].Next;
//     mp[slow].Next="-1";
//     string left=sortList(mp,head);
//     string right=sortList(mp,tmp);

//     ListNode dummy("0",0,"-1");
//     string res=dummy.ID;
//     if(left!="-1"&&right!="-1"){
//         if(mp[left].Key<mp[right].Key){
//             res=left;
//             left=mp[left].Next;
//         }else{
//             res=right;
//             right=mp[right].Next;
//         }
//         dummy.Next=res;
//     }
//     while(left!="-1"&&right!="-1"){
//         if(mp[left].Key<mp[right].Key){
//             mp[res].Next=left;
//             left=mp[left].Next;
//         }else{
//             mp[res].Next=right;
//             right=mp[right].Next;
//         }
//         res=mp[res].Next;
//     }
//     mp[res].Next=(left!="-1")?left:right;
//     return dummy.Next;
// }

// int main(){
//     int N;
//     string head;
//     cin>>N>>head;
//     unordered_map<string,ListNode> mp;
//     string id,next;
//     int key;
//     for(int i=0;i<N;i++){
//         cin>>id>>key>>next;
//         ListNode l(id,key,next);
//         mp[id]=l;
//     }
//     head=sortList(mp,head);
//     cout<<N<<" "<<head<<endl;
//     while(head!="-1"){
//         cout<<head<<" "<<mp[head].Key<<" "<<mp[head].Next<<endl;
//         head=mp[head].Next;
//     }
//     return 0;
// }
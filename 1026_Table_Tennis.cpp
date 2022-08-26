#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

struct player
{
    int arrival;
    int playtime;
    int vip;
    player(int hour,int minute,int second,int t,int v):vip(v){
        arrival=hour*3600+minute*60+second;
        playtime=t<120?t*60:120*60;
    }
};

struct table
{
    int usefultime;
    int vip;
    table():usefultime(8*3600),vip(0){}
    table(int hour,int minute,int second,int v):vip(v){
        usefultime=hour*3600+minute*60+second;
    }
};


int main(){
    string line;
    istringstream s;
    int N;
    getline(cin,line);
    s.str(line);
    s>>N;
    vector<player> players;
    for(int i=0;i<N;i++){
        string arrival;
        int palytime,vip;
        getline(cin,line);
        s.clear();
        s.str(line);
        s>>arrival>>palytime>>vip;
        for(auto&c:arrival){
            c=c==':'?' ':c;
        }
        int hour=0,minute=0,second=0;
        s.clear();
        s.str(arrival);
        s>>hour>>minute>>second;
        player p(hour,minute,second,palytime,vip);
        players.emplace_back(p);
    }
    sort(players.begin(),players.end(),[](const player&lhs,const player&rhs){return lhs.arrival<rhs.arrival;});
    getline(cin,line);
    s.clear();
    s.str(line);
    int K,M;
    s>>K>>M;
    vector<table> tables(K);
    getline(cin,line);
    s.clear();
    s.str(line);
    int no;
    for(int i=0;i<M;i++){
        s>>no;
        tables[no-1].vip=1;
    }
    bool haveVip=false;
    while(!players.empty()){
        auto min_it=min(tables.begin(),tables.end(),[](const table&lhs,const table&rhs){return lhs.usefultime<rhs.usefultime;});
        auto it=players.begin();
        for(;it!=players.end();it++){
            if(*it->arrival>*min_it->usefultime) break;
            if(*it->vip) {
                haveVip=true;
                break;
            }
        }
        if(haveVip){
            int wait_time=(*min_it).usefultime-(*it).arrival;
            (*min_it).usefultime=(*min_it).usefultime+(*it).playtime;
            
        }

    }
    return 0;
}


// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cmath>
// using namespace std;
// const int startTime = 8 * 3600;	// 开门时间：08:00:00
// const int endTime = 21 * 3600;	// 关门时间：21:00:00

// struct Player {					// 玩家
// 	int arriveTime;				// 来的时间
// 	int waitTime;				// 等待空桌子的时间
// 	int getTableTime;			// 分配到桌子的时间
// 	int playTime;				// 玩多长时间
// 	int vip;					// 是不是vip玩家
// };
// struct Table
// {
// 	int finishTime;				// 这张桌子什么时候空闲，即正在使用桌子的玩家什么时候结束使用
// 	int cnt;					// 有多少玩家使用了这张桌子
// 	int vip;					// 这是不是vip桌子
// };

// // 按玩家先来后到排序
// bool cmpByArriveTime(Player& a, Player& b) {
// 	return a.arriveTime < b.arriveTime;
// }
// // 按分配到桌子的时间排序
// bool cmpByGetTableTime(Player& a, Player& b) {
// 	return a.getTableTime < b.getTableTime;
// }
// // 选择一个桌子，返回桌子下标
// int select(vector<Table>& table, int arriveTime, int vip)
// {
// 	// 如果是vip玩家，先找有没有空闲的vip桌子，找到则return
// 	if (vip) {
// 		for (int i = 1; i < table.size(); i++) {
// 			if (table[i].finishTime <= arriveTime && table[i].vip == 1)
// 				return i;
// 		}
// 	}

// 	// 找一个空闲的桌子(如果vip玩家没有找到空闲的vip桌子，那么再找到的空闲桌子就是普通的了)
// 	for (int i = 1; i < table.size(); i++) {
// 		if (table[i].finishTime <= arriveTime)
// 			return i;
// 	}

// 	// 如果没有空闲的桌子，则寻找一个最先空闲的桌子
// 	int choice = 1;
// 	for (int i = 2; i < table.size(); i++) {
// 		if (table[i].finishTime < table[choice].finishTime)
// 			choice = i;
// 	}
// 	return choice;
// }

// int main()
// {
// 	int n, k, m;
// 	scanf("%d", &n);
// 	vector<Player> players(n);
// 	for (int i = 0; i < n; i++)
// 	{
// 		int hh, mm, ss, playtime, vip;
// 		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &playtime, &vip);
// 		players[i].arriveTime = hh * 3600 + mm * 60 + ss;
// 		players[i].playTime = playtime * 60;
// 		if (players[i].playTime > 2 * 3600)
// 			players[i].playTime = 2 * 3600;
// 		players[i].waitTime = -1;
// 		players[i].vip = vip;
// 	}

// 	scanf("%d %d", &k, &m);
// 	vector<Table> tables(k + 1, { startTime,0 ,0 });
// 	for (int i = 0; i < m; i++)
// 	{
// 		int temp;
// 		scanf("%d", &temp);
// 		tables[temp].vip = 1;
// 	}

// 	// 把玩家先来后到进行排序
// 	sort(players.begin(), players.end(), cmpByArriveTime);
// 	// 依次为每一个玩家寻找桌子										
// 	for (int i = 0; i < n; i++)
// 	{
// 		// 如果这个玩家还没有被安排（可能会有vip玩家插队的情况）
// 		if (players[i].waitTime == -1) {
// 			// 根据玩家来的时间以及vip身份找桌子											
// 			int index = select(tables, players[i].arriveTime, players[i].vip);
// 			// 将要被安排的玩家
// 			int who = i;
// 			// 如果找到的是vip桌子，则看看在桌子空闲之前有没有vip玩家在排队了
// 			if (tables[index].vip == 1)
// 			{
// 				// 注意这里是从这个玩家i开始往后找
// 				for (int j = i; j < players.size() && players[j].arriveTime <= tables[index].finishTime; j++)
// 				{
// 					// 如果队列此时存在vip，且没有被安排，则该桌子被vip抢走
// 					// 如果i就是vip，那么桌子还是它的																
// 					if (players[j].vip == 1 && players[j].waitTime == -1) {
// 						who = j;
// 						break;
// 					}
// 				}
// 			}


// 			// 如果玩家来时已经有桌子空闲，不需要等，分配到桌子的时间就是来的时间；`
// 			// 否则等的时间为 [桌子finishTime] -  [玩家arriveTime]，分配到桌子的时间是[桌子finishTime] 
// 			players[who].waitTime = max(0, tables[index].finishTime - players[who].arriveTime);
// 			players[who].getTableTime = max(tables[index].finishTime, players[who].arriveTime);
// 			// 桌子下一次空闲的时间：
// 			tables[index].finishTime = players[who].getTableTime + players[who].playTime;

// 			if (who != i)	// 如果i的桌子被vip玩家抢走了
// 				--i;		// 真惨，下次循环再给i找桌子

// 			// 如果玩家在关门前得到了桌子，桌子的使用人数+1
// 			if (players[who].getTableTime < endTime)
// 				tables[index].cnt++;
// 		}
// 	}

// 	sort(players.begin(), players.end(), cmpByGetTableTime);
// 	for (auto e : players) {
// 		if (e.getTableTime >= endTime)
// 			break;
// 		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", e.arriveTime / 3600, (e.arriveTime / 60) % 60, e.arriveTime % 60, e.getTableTime / 3600, (e.getTableTime / 60) % 60, e.getTableTime % 60, (int)round((double)e.waitTime / 60));
// 	}
// 	for (int i = 1; i < tables.size(); i++)
// 	{
// 		if (i == 1)
// 			printf("%d", tables[i].cnt);
// 		else
// 			printf(" %d", tables[i].cnt);
// 	}
// }




//法二：AC了
#include<cstdio>
#include<algorithm>
using namespace std;
 
int a[100005], dis[100005];     //dis记录每个点到初始点(1号)的距离
 
int main() {
	int n, sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum += a[i];
		dis[i + 1] = sum;         //因为是记录到第一个点的距离，就从第二个点开始，所以下标为 i + 1
	}
	int m, k;
	k = sum / 2;
	scanf("%d", &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x > y)
            swap(x, y);
		int sum0 = dis[y] - dis[x];         //直接求出两点之间的距离
		printf("%d\n", sum0 < k ? sum0 : sum - sum0);
	}
		
	return 0;
}
/*最少点覆盖问题
树形DP解决
对于任意一个节点i来说，可以放士兵和不放士兵两种可能，dp[i][0]表示i点不放士兵，
dp[i][1]表示i放士兵。
状态转移方程：dp[i][1]=sum(min(dp[k][0],dp[k][1])) 由于本节点放士兵，
所以把k节点放士兵和不放士兵的较小值加起来,k为i的子节点 
dp[i][0]=sum(dp[k][1])由于本节点不放士兵，所以子节必须放士兵，不然这条边将没有士兵看守，把子节点放士兵的加起来 
最后所有数量最少的士兵取dp[0][0]和dp[0][1]的较小值 
*/
#include<iostream>
#include<vector>
using namespace std;
const int maxn=1600;
int dp[maxn][2];
int n;

vector<int> tree[maxn];
int min(int a,int b){
	if(a<b)return a;
	else return b;
}
void dfs(int old,int now){
	dp[now][0]=0;
	dp[now][1]=1;
	int len=tree[now].size();
	int i;
	for(i=0;i<len;i++){
		int t=tree[now].at(i);
		if(t!=old){
			dfs(now,t);
			dp[now][0]+=dp[t][1];
			dp[now][1]+=min(dp[t][0],dp[t][1]);	
			} 
		}
	}

int main(){
	int a,b,j,x;
	while(cin>>n){
		int i;
		for(i=0;i<n;i++)
			tree[i].clear();
		for(i=0;i<n;i++){
			
			scanf("%d:(%d)",&a,&b);
			for(j=0;j<b;j++){
				cin>>x;
				tree[a].push_back(x);
				tree[x].push_back(a);
			}
		}
		dfs(-1,0);
		cout<<min(dp[0][0],dp[0][1])<<endl;
	}
	return 0;
} 

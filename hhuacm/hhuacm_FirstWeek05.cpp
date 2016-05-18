/*���ٵ㸲������
����DP���
��������һ���ڵ�i��˵�����Է�ʿ���Ͳ���ʿ�����ֿ��ܣ�dp[i][0]��ʾi�㲻��ʿ����
dp[i][1]��ʾi��ʿ����
״̬ת�Ʒ��̣�dp[i][1]=sum(min(dp[k][0],dp[k][1])) ���ڱ��ڵ��ʿ����
���԰�k�ڵ��ʿ���Ͳ���ʿ���Ľ�Сֵ������,kΪi���ӽڵ� 
dp[i][0]=sum(dp[k][1])���ڱ��ڵ㲻��ʿ���������ӽڱ����ʿ������Ȼ�����߽�û��ʿ�����أ����ӽڵ��ʿ���ļ����� 
��������������ٵ�ʿ��ȡdp[0][0]��dp[0][1]�Ľ�Сֵ 
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

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn=3005;
int tree[maxn];
void build(int rt,vector<int>a,vector<int>b)//递归建树
{
    if(a.size()==0) return ;//递归出口
    int p=0;
    for(int i=0;i<b.size();i++)//找出根
        if(b[i]==a[a.size()-1]) p=i;
    vector<int>al,ar,bl,br;
    for(int i=0;i<p;i++) al.push_back(a[i]);//左子树的后序遍历序列
    for(int i=p;i<a.size()-1;i++) ar.push_back(a[i]);//右子树的后序遍历序列
    for(int i=0;i<p;i++) bl.push_back(b[i]);//左子树的中序遍历序列
    for(int i=p+1;i<b.size();i++) br.push_back(b[i]);//右子树的中序遍历序列
    tree[rt]=b[p];//建根
    build(rt<<1,al,bl);//递归建左子树
    build(rt<<1|1,ar,br);//递归建右子树
}
void bfs()//用bfs层次遍历
{
    queue<int>q;
    int root=1;
    q.push(root);
    int f=0;
    while(q.size())
    {
        if(f++) cout<<" ";
        root=q.front();
        cout<<tree[root];
        q.pop();
        if(tree[root<<1]!=-1) q.push(root<<1);
        if(tree[root<<1|1]!=-1) q.push(root<<1|1);
    }
    cout<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    int n,x;
    while(cin>>n)
    {
        memset(tree,-1,sizeof(tree));
        vector<int>a,b;
        for(int i=0;i<n;i++) cin>>x,a.push_back(x);
        for(int i=0;i<n;i++) cin>>x,b.push_back(x);
        build(1,a,b);
        bfs();
    for (int i = 0; i < n; ++i)
	{
		printf("%d ", tree[i]);
	}
    }
    return 0;
}

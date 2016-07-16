#include <iostream>  
#include <vector>  
#include <queue>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>
using namespace std;
int tree[3005];	
void build(int root,vector<int> a,vector<int> b){
	if(a.size()==0)return;
	int p=0;
	for (int i = 0; i < b.size(); ++i)
	{
		if(b[i]==a[a.size()-1])p=i;
	}
	vector<int>al,ar,bl,br;
	for (int i = 0; i < p; ++i)//左子树的后序遍历
	{
		al.push_back(a[i]);
	}
	for (int i = p; i < a.size()-1; ++i)//右子树的后序遍历
	{
		ar.push_back(a[i]);
	}
	for (int i = 0; i <p ; ++i)//左子树的中序遍历
	{
		bl.push_back(b[i]);
	}
	for (int i = p+1; i < b.size(); ++i)//右子树的中序遍历
	{
		br.push_back(b[i]);
	}
	tree[root]=b[p];
	build(2*root,al,bl);//创建左子树
	build(2*root+1,ar,br);//创建右子树

}
void bfs(){
	queue<int>q;
	int root=1;
	q.push(root);
	while(q.size()){	
		root=q.front();
		if(root!=1)printf(" ");
		
		printf("%d", tree[root]);
		q.pop();
		if(tree[2*root]!=-1)q.push(2*root);
		if(tree[2*root+1]!=-1)q.push(2*root+1);
	}
	printf("\n");

}
int main(){
	int n,i,j,x;
	memset(tree,-1,sizeof(tree));

	scanf("%d",&n);
/*	for (int i = 0; i < n; ++i)
	{
		printf("%d ", tree[i]);
	}*/
	vector<int> a,b;
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		a.push_back(x);		
	}
	for ( i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		b.push_back(x);		
	}
	build(1,a,b);
	bfs();
	return 0;
}
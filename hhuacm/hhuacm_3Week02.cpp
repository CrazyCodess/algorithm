/*Ïß¶ÎÊ÷*/ 
#include<iostream>
#include<cstring>
using namespace std;
struct node{
	int l;
	int r;
	int v;
}t[150011];
int ans;
void  build(int k,int l,int r){
	
	if(l==r){
		t[k].l=l;
		t[k].r=r;
		t[k].v=0;
		return;
	}
		t[k].l=l;
		t[k].r=r;
		t[k].v=0;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void insert(int v,int d,int k){
	if(t[k].l==t[k].r&&t[k].l==d){
		t[k].v+=v;
		return ;
	}
	int mid;
	mid=(t[k].l+t[k].r)>>1;
	if(d<=mid)insert(v,d,2*k);
	else insert(v,d,2*k+1);
	t[k].v=t[2*k].v+t[2*k+1].v;
}
void serach(int k,int i,int j){
	if(t[k].l==i&&t[k].r==j){
		ans+=t[k].v;
		return ;
	}
	int mid;
	mid=(t[k].l+t[k].r)>>1;
	if(mid>=j)serach(2*k,i,j);
	else if(i>mid)serach(2*k+1,i,j);
	else{
		serach(2*k,i,mid);
		serach(2*k+1,mid+1,j);
	}
	
}
int main(){
	int tt,i,j,n,temp,a,b;
	char s[6];
	cin>>tt; 
		for(j=1;j<=tt;j++){
			cin>>n;
			build(1,1,n);
			for(i=1;i<=n;i++){
				cin>>temp;
				insert(temp,i,1);
			}
			cout<<"Case "<<j<<":"<<endl;
			while(cin>>s&&strcmp(s,"End")!=0){
				cin>>a>>b;
				if(strcmp(s,"Add")==0)insert(b,a,1);
				else if(strcmp(s,"Sub")==0)insert(-b,a,1);
				else{
					ans=0;
					serach(1,a,b);
					cout<<ans<<endl;
				}
			} 
		}
	
	return 0;
} 

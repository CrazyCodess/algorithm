#include<iostream>
#include<cstdio>
#include<cstring> 
using namespace std;
struct edge{
	int nodes[210];
	int links;
}edges[500]; 
int n,m;
int match[500][500];
int MaxMatch(){
	int path[210];
	int filled[500]; 
	int visited[500];
	int epoch = 0;
	int node;
	int cnt = 0;
	memset(filled,0,sizeof(filled));
	bool  f= false;
	bool all = false;
	int search[210];
	memset(search,0,sizeof(search));
	while(true){
		memset(visited,0,sizeof(visited));
		cnt =0;
		memset(path,-1,sizeof(path));
		all = false;
		for(int i=0;i<n;i++){
			if(!filled[i] && !search[i]){
				node = i;
				visited[node] = 1;
				search[node] = 1;
				path[cnt] = node; 
				all = true;
				break;
			}
		}
		if(!all){
			break;
		}
		while(true){
			f = false;
			if(node>=0&&node<n){
				for(int i=0;i<edges[node].links;i++){
					if(!match[node][edges[node].nodes[i]] && !visited[edges[node].nodes[i]]){
						//printf("epoch :%d %d -> %d\n",epoch,node,edges[node].nodes[i]);
						node = edges[node].nodes[i];
						visited[node] = 1;		
						cnt++;
						path[cnt] = node;
						f = true;
						break;
					}
				}				
			}
			if(!filled[node]){
				//printf("%d exit\n",node); 
				break;
			}
			if(!f){
				if(cnt>=2){
					path[cnt] = -1;
					cnt--;
					path[cnt] = -1;	
					cnt--;
					node = path[cnt];	
					//cout<<"cnt : "<<cnt<<"node:"<<node<<endl;	
				}
					
			}

			if(node>=n){
				for(int i=0;i<edges[node].links;i++){
					if(match[node][edges[node].nodes[i]]&& !visited[edges[node].nodes[i]]){
						//printf("epoch :%d %d -> %d\n",epoch,node,edges[node].nodes[i]);
						node = edges[node].nodes[i];
						visited[node] = 1;	
						cnt++;
						path[cnt] = node;
						
						break;			
					}
				}
			}
		}
		//memset(filled,0,sizeof(filled));
		//printf("path : "); 
		for(int i=0;i<cnt;i++){
			filled[path[i]] = filled[path[i+1]] = 1;
			//printf("%d -> %d ",path[i],path[i+1]);
			match[path[i]][path[i+1]] = 1 - match[path[i]][path[i+1]];
			match[path[i+1]][path[i]] = 1 - match[path[i+1]][path[i]];
		}
		//printf("\n");
		if(!all)break;
		epoch++;
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<edges[i].links;j++){
			if(match[i][edges[i].nodes[j]]){
				ans++;
				break;
			}
		}
	} 
	return ans;
}

int main(){
	int s = 0;
	int stall = 0;
	int ans = 0;
	//freopen("testcases.txt","r",stdin);
	//freopen("result.txt","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(match,0,sizeof(match));  
		memset(edges,0,sizeof(edges));
		for(int i =0;i<n;i++){
			scanf("%d",&s);
			edges[i].links = 0;
			for(int j=0;j<s;j++){
				scanf("%d",&stall);
				edges[i].nodes[edges[i].links] = stall +n - 1;
				edges[stall +n - 1].nodes[edges[stall +n - 1].links] = i;
				edges[i].links += 1;
				edges[stall +n - 1].links +=1;
			}
		}
		ans = MaxMatch();
		printf("%d\n",ans);
	} 

	return 0;
}

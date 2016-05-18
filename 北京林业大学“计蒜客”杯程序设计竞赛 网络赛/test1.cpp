#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;

char mp[120][120];
int n,m;
struct node{
    int x,y,dis;
};
int sx,sy,ex,ey;
int dir[8][2]={
    1,2,1,-2,2,1,2,-1,-1,2,-1,-2,-2,1,-2,-1
};
int vis[120][120];
void bfs(){
    cle(vis);
    queue<node>q;
    node u={sx,sy,0};
    q.push(u);
    int mark=0;
    while(!q.empty()){
        node u=q.front();
        q.pop();
        if(u.x==ex&&u.y==ey){
            if(u.dis==0)break;
            cout<<u.dis<<endl;
            mark=1;
            break;
        }
        node v;
        for(int i=0;i<8;i++){
            v.x=u.x+dir[i][0];
            v.y=u.y+dir[i][1];
            int nx=u.x+dir[i][0]/2;
            int ny=u.y+dir[i][1]/2;
            if(mp[nx][ny]=='#')continue;
            if(v.x<n&&v.x>=0&&v.y>=0&&v.y<m&&(mp[v.x][v.y]!='#')&&!vis[v.x][v.y]){
                v.dis=u.dis+1;
                q.push(v);
                vis[v.x][v.y]=1;
            }
        }

    }
    if(mark==0){
        cout<<-1<<endl;
    }
}
int main()
{
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mp[i][j];
                if(mp[i][j]=='s'){
                    sx=i,sy=j;
                }
                else if(mp[i][j]=='e'){
                    ex=i;ey=j;
                }
            }
        }
        bfs();
    }
    return 0;
}

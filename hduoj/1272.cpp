#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int> vect;
int pre[100005];
void makeset(){
    int i;
    for(i=0;i<100005;i++)
        pre[i]=-1;
}
int find(int x){
    if(pre[x]==-1){
        return x;
    }
    return find(pre[x]);
}
void uniun(int x,int y){
    pre[y]=x;
}
int main(){
    int a,b,fa,fb,flag,i,j,cnt,len;
    flag=true;
    makeset();
    cnt=0;
    vect.clear();
    while(scanf("%d%d",&a,&b)){
        
        if(a==-1&&b==-1)break;
        if(a==0&&b==0){
            if(flag){
                len=vect.size();
                for(i=0;i<len;i++){
                    for(j=i+1;j<len;){
                        if(vect.at(i)==vect.at(j)){
                            vect.erase(vect.begin()+j);
                            len=vect.size();
                        }
                        else j++;
                        
                    }
                }
                 for(i=0;i<vect.size();i++){
                     if(pre[vect.at(i)]==-1)cnt++;
                 }
                 if(cnt<=1)printf("Yes\n");
                 else printf("No\n");
                 
            }else{

                printf("No\n");
            }
            
            cnt=0;
            vect.clear();
            flag=true;
            makeset();    
            continue;
        }
        
        vect.push_back(a);
        vect.push_back(b);
        fa=find(a);
        fb=find(b);
        if(fa==fb){
            flag=false;
            //continue;
        }
        if(flag){
            uniun(fa,fb);
        }
        
    }
    return 0;
} 

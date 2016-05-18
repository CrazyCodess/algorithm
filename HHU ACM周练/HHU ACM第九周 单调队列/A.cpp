#include<iostream>
#include<cstdio>
using namespace std;
#define N 1000001
typedef struct {
	int value;
	int index;
}que;
que min_que[N],max_que[N];
int num[N];
int Scan()     //输入外挂
 {
      int res=0,ch,flag=0;
      if((ch=getchar())=='-')
          flag=1;
      else if(ch>='0'&&ch<='9')
          res=ch-'0';
      while((ch=getchar())>='0'&&ch<='9'){
      	//if(ch==' ')break;
      	res=res*10+ch-'0';
      }
        
     return flag?-res:res;
 }
 void Out(int a)    //输出外挂
 {
 	if(a<0){
 		putchar('-');
 		a=0-a;
 	}
 	
     if(a>9)
         Out(a/10);
     putchar(a%10+'0');
	//putchar(' ');	
 }


int delete_rear_min(int f,int r,int d){
	int mid;
	while(f<=r){
		mid=(f+r)/2;
		if(min_que[mid].value==d)
			return mid;
		if(min_que[mid].value<d)
			f=mid+1;
		else 
			r=mid-1;
	}
	return f;
}
int delete_rear_max(int f,int r,int d){
	int mid;
	while(f<=r){
		mid=(f+r)/2;
		if(max_que[mid].value==d)
			return mid;
		if(max_que[mid].value>d)
			f=mid+1;
		else 
			r=mid-1;
	}
	return f;
}
int main(){
	int n,k;
	int i;
	int front,rear;
	while(scanf("%d%d",&n,&k)!=EOF){
		for(i=1;i<=n;i++){
			//num[i]=Scan();
			scanf("%d",&num[i]);
		}
		//for(i=1;i<=n;i++){
		//	printf("%d ",num[i]);
		//}
		//printf("/\n");
		front=rear=1;
		min_que[1].value=num[1];
		min_que[1].index=1;
		for(i=2;i<=k;i++){
			rear=delete_rear_min(front,rear,num[i]);
			min_que[rear].value=num[i];
			min_que[rear].index=i;
		}
		Out(min_que[front].value);
		//printf("%d ",min_que[front].value);
		putchar(' ');//printf(" ");
		for(i=k+1;i<=n;i++){
			rear=delete_rear_min(front,rear,num[i]);
			min_que[rear].value=num[i];
			min_que[rear].index=i;
			if(i-min_que[front].index>=k)
				front++;
			Out(min_que[front].value);
			//printf("%d ",min_que[front].value);
			putchar(' ');//printf(" ");
		}
		printf("\n");
		
		
		max_que[1].value=num[1];
		max_que[1].index=1;
		front=rear=1;
		for(i=2;i<=k;i++){
			rear=delete_rear_max(front,rear,num[i]);
			max_que[rear].value=num[i];
			max_que[rear].index=i;
		}
		Out(max_que[front].value);
		//printf("%d ",max_que[front].value);
		putchar(' ');//printf(" ");
		for(i=k+1;i<=n;i++){
			rear=delete_rear_max(front,rear,num[i]);
			max_que[rear].value=num[i];
			max_que[rear].index=i;
			if(i-max_que[front].index>=k)
				front++;
			Out(max_que[front].value);
			//printf("%d ",max_que[front].value);
			putchar(' ');//printf(" ");
		}
		putchar('\n');
	}	
	return 0;
}


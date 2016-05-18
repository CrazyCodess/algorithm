#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
struct node{
	char a[20];
	int  para;
	int pri;
	long int time; 
};
typedef struct node * PNode;
struct PriorityQueue{
	PNode *pq;
	int n;
};
typedef struct PriorityQueue *PPriorityQueue;
void add_heap(PPriorityQueue papq,PNode p){
	int i;
		for(i=papq->n;i>0&&((papq->pq[(i-1)/2]->pri>p->pri)||(papq->pq[(i-1)/2]->pri==p->pri&&papq->pq[(i-1)/2]->time>p->time));i=(i-1)/2){
			papq->pq[i]=papq->pq[(i-1)/2];
		}
		papq->pq[i]=p;
		papq->n++;
}
void removeMin_heap(PPriorityQueue papq){
	
	if(papq->n!=0){
		int s,child=1,i=0;
		PNode q;
		s=--papq->n;
		q=papq->pq[s];
		while(child<s){
			if(child<s-1&&papq->pq[child]->pri>papq->pq[child+1]->pri)
			child++;
			if(child<s-1&&papq->pq[child]->pri==papq->pq[child+1]->pri&&papq->pq[child]->time>papq->pq[child+1]->time)
			child++;
			if((q->pri>papq->pq[child]->pri)||(q->pri==papq->pq[child]->pri&&q->time>papq->pq[child]->time)){
				papq->pq[i]=papq->pq[child];
				i=child;
				child=2*i+1;
			}
			else break;
		}
		papq->pq[i]=q;
	}
}
void get(PPriorityQueue papq){
	if(papq->n==0){
		cout<<"EMPTY QUEUE!"<<endl;
	}
	else{
		
		cout<<papq->pq[0]->a<<" "<<papq->pq[0]->para<<endl;
		removeMin_heap(papq);
	}
}
int main(){
	long int time=0;
	PPriorityQueue papq=(PPriorityQueue)malloc(sizeof(struct PriorityQueue));
	papq->n=0;
	papq->pq=(PNode *)malloc(sizeof(struct node)*60003);
	
	string s;
	while(cin>>s){
		if(s.compare("GET")==0){
			get(papq);
		}
		if(s.compare("PUT")==0){
			PNode q=(PNode)malloc(sizeof(struct node));
			cin>>q->a>>q->para>>q->pri;
			q->time=time;
			add_heap(papq,q);
			time++;
		}
	}
	return 0;
}

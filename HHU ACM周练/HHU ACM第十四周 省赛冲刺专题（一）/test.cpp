#include<iostream>
#include<cstdio>
using namespace std;
int a[205][205];
int m,n,t;
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void res0(){
    int i,j;
    for(i=0;i<n/2;i++){
        for(j=0;j<m;j++){
            swap(&a[j][i],&a[j][n-i-1]);
        }
    }
}
void res1(){
    int i,j;
    for(i=0;i<m/2;i++){
        for(j=0;j<n;j++){
            swap(&a[i][j],&a[m-i-1][j]);
        }
    }
}
int main(){
    int i,j;
    while(scanf("%d%d%d",&m,&n,&t)!=EOF){
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)scanf("%d",&a[i][j]);
        if(t==0)res0();
        else if(t==1)res1();
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

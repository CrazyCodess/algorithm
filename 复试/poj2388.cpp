#include <iostream>
#include <cstdio>
using namespace std;
int cows[10010];
void swap(int *j,int *k){
	if(*j!=*k){
		int temp=*j;
		*j=*k;
		*k=temp;
	}
	return;
}
int partition(int a[],int low,int high){
	int pivotpos = low;
	int pivot = a[low];
	for (int i = low+1; i <=high; ++i)
	{	
		if(a[i]<pivot)swap(&a[i],&a[++pivotpos]);
	}
	swap(&a[low],&a[pivotpos]);
	//cout<<pivotpos<<endl;	
	return pivotpos;

}
void qsort(int a[],int left,int right){
	if(left<right){
		int pivotpos=partition(a,left,right);
		qsort(a,left,pivotpos-1);
		qsort(a,pivotpos+1,right);
		
	}
}

int main(){
	int n,cow;
	while(scanf("%d",&n)!=EOF){
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&cow);
			cows[i]=cow;

		}
		//for (int i = 0; i < n; ++i)cout<<cows[i]<<endl;
		qsort(cows,0,n-1);
		printf("%d\n", cows[n/2]);

	}

}
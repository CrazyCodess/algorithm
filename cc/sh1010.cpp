#include <iostream>
using namespace std;

int main(){
    
    int num;
    cin>>num;
    int count = 0;//�������� 
    while(num--){

        int n;//������Ŀ 
        cin>>n; 
        int a,b;//����a���������b���� 
        cin>>a>>b;
        int l;//�ܾ���
        cin>>l;
        int start,end,k=1;
        int dis[100001];
        
        for(int i=0;i<=l;i++){
            dis[i]=0;
        }
        while(n--){
            cin>>start>>end;
            if(start != 0){
                dis[0] = b;
            }
            else
                dis[0] = -a;
            for(int i=k;i<start;i++){
                dis[i] = dis[i-1]+b;
            }
            for(int i=start;i<end;i++){
                dis[i] = dis[i-1]-a;
            }
            k = end;
        } 
        
        int min = 99999;
        for(int i=0;i<end;i++){
            //cout<<dis[i]<<' '<<endl;
            if(min>dis[i])
                min = dis[i];
        }
        
        if(min>0)
            min = 0;
        else
            min = -min;
            
        count++; 
        cout<<"Case #"<<count<<": "<<min<<endl;
    }
    return 0;
} 
#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXN = 30001; /*�����Ŀ����*/
int pa[MAXN];    /*p[x]��ʾx�ĸ��ڵ�*/
int rank[MAXN];    /*rank[x]��x�ĸ߶ȵ�һ���Ͻ�*/
int num[MAXN];/*num[]�洢�ü�����Ԫ�ظ��������ڼ��Ϻϲ�ʱ����num[]����*/

void make_set(int x)
{/*����һ����Ԫ��*/
    pa[x] = x;
    rank[x] = 0;
    num[x] = 1;
}

int find_set(int x)
{/*��·��ѹ���Ĳ���*/
    /*��������ҵ���*/
    int r = x, temp;
    /*�ҵ����ڵ�*/
    while(pa[r] != r) r = pa[r];
    while(x != r)
    {
        temp = pa[x];
        pa[x] = r;
        x = temp;
    }
    return x;
    //if(x != pa[x]) //ע�͵�����ʵҲ�ǿ��Եģ����������õݹ�������
    //    pa[x] = find_set(pa[x]);
    //return pa[x];
}

/*���Ⱥϲ�x��y���ڵļ���*/
void union_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y)return ;
    if(rank[x] > rank[y])/*��rank�Ƚϸߵ���Ϊ�����*/
    {
        pa[y] = x;
        num[x] += num[y];
    }
    else 
    {
        pa[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
        num[y] += num[x];
    }
}

//answer to 1611 
int main()
{
    int n, m, x, y, i, t, j;
    while(scanf("%d%d", &n, &m))
    {
        if(m==n && n == 0) break;
        if(m == 0)
        {
            cout << "1\n"; continue;
        }
        for(i = 0; i < n; i++)
            make_set(i);
        for(i = 0; i < m; i++)
        {
            scanf("%d", &t);
            scanf("%d", &x);
            for(j = 1; j < t; j++){
                scanf("%d", &y);
                union_set(x, y);
                x = y;
            }
        }
        x = find_set(0);/*�ҵ�0���ڵ���������*/
        //int ans = 0;
        //for(i = 0; i < n; i++)
        //    if(pa[i] == x)
        //        ans++;
        //cout << ans << endl;
        cout << num[x] << endl;
    }
    return 0;
}

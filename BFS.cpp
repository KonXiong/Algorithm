/*****************************************************************************
File name: BFS
Description: BFS算法学习
Author: 熊康
Version: V1.0
Date: 2022.3.26
*****************************************************************************/
//#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int a[100][100],v[100][100];
struct point
{
    int x;
    int y;
    int step;
};
queue<point> r;  //申请队列
int dx[4] = {0,1,0,-1};  //四个方向，右，下，左，上
int dy[4] = {1,0,-1,0};
int flag = 0;

int main(){

/*
5 4
1 1 2 1
1 1 1 1
1 1 2 1
1 2 1 1
1 1 1 2
1 1 4 3
*/
    //输入
    int n,m,startx,starty,p,q;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            scanf("%d", &a[i][j]);

    scanf("%d%d%d%d",&startx,&starty,&p,&q);

    //BFS
    point start;
    start.x = startx;
    start.y = starty;
    start.step = 0;
    r.push(start); //将起点入队
    v[startx][starty] = 1;

    while(!r.empty())
    {
        int x = r.front().x, y = r.front().y;
        if(x==p && y==q)
        {
            flag = 1;
            printf("%d",r.front().step);
            break;
        }
        for(int k=0; k<=3; k++)
        {
            int tx,ty;
            tx = x + dx[k];
            ty = y + dy[k];
            if(a[tx][ty] == 1 && v[tx][ty] == 0)
            {
                //入队
                point temp;
                temp.x = tx;
                temp.y = ty;
                temp.step = r.front().step + 1;
                r.push(temp);
                v[tx][ty] = 1;
            }
        }
        r.pop();  //拓展完后将首元素出队
    }
    if(flag == 0) 
        printf("no answer!\n");
    return 0;

}
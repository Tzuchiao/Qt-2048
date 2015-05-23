//
//  data.cpp
//  C++2048
//
//  Created by TzuChiao Yeh on 2015/5/15.
//  Copyright (c) 2015年 TzuChiao Yeh. All rights reserved.
//

#include "data.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <time.h>
using namespace std;


int Data::arr[4][4] = {0};

void Data::init()
{
    for(int r=0;r<4;r++)
    {
        for(int c=0;c<4;c++)
        {
            arr[r][c] = 0;
        }
    }
    fullcount = 1;
    score = 0;
    final = 0;
    srand(time(NULL));
    int x=(rand()%4);
    int y=(rand()%4);
    arr[x][y] = 2;
}

void Data::create()
{
    while(fullcount!=16)
    {
    srand(time(NULL));
    int x=(rand()%4);
    int y=(rand()%4);
    if(arr[x][y]==0)
    {
    arr[x][y] = 2;
    fullcount++;
    break;
    }
    }
}

void Data::move(int in)
{
    switch(in)
    {
        case 1:
            stack(1);
             stack(1);
            for(int col=0;col!=4;col++)
            {
                for(int now = 0;now<3;now++)
                {
                    if(arr[now][col]==0)
                        continue;

                    for(int row = now+1;row<4;row++)
                    {
                        if(arr[now][col]==arr[row][col])
                        {
                        arr[row][col]*=2;
                        score+=arr[row][col];
                        arr[now][col] = 0;
                        fullcount--;
                        if(arr[row][col]==2048)
                            final = 1;
                        }
                        else if(arr[now][col]!=arr[row][col])
                        {
                            break;

                    }
                }
            }

            }
            stack(1);
        break;
    case 2:
        stack(2);
        stack(2);
        for(int col=0;col!=4;col++)
        {
            for(int now = 3;now!=0;now--)
            {
                if(arr[now][col]==0)
                    continue;
                for(int row = now-1;row>=0;row--)
                {
                    if(arr[now][col]==arr[row][col])
                    {
                    arr[row][col]*=2;
                    score+=arr[row][col];
                    arr[now][col] = 0;
                    fullcount--;
                    if(arr[row][col]==2048)
                        final = 1;

                    }
                    else if(arr[now][col]!=arr[row][col])
                    {
                        break;
                    }
                }
            }
        }
        stack(2);
        break;
    case 3:
        stack(3);
        stack(3);

        for(int row=0;row!=4;row++)
        {
            for(int now = 0;now!=3;now++)
            {
                if(arr[row][now]==0)
                    continue;
                for(int col=now+1;col<4;col++)
                {
                    if(arr[row][now]==arr[row][col])
                    {
                    arr[row][now]*=2;
                    score+=arr[row][now];
                    arr[row][col] = 0;
                    fullcount--;
                    if(arr[row][now]==2048)
                        final = 1;
                    }
                    else if(arr[row][now]!=arr[row][col])
                    {
                        break;
                    }
                }
            }
        }
        stack(3);
        break;
    case 4:
        stack(4);
        stack(4);

        for(int row=0;row!=4;row++)
        {
            for(int now = 3;now>0;now--)
            {
                if(arr[row][now]==0)
                    continue;
                for(int col = now-1;col>=0;col--)
                {
                    if(arr[row][now]==arr[row][col])
                    {
                        arr[row][now]*=2;
                        score+=arr[row][now];
                        arr[row][col] = 0;
                        fullcount--;
                        if(arr[row][now]==2048)
                            final = 1;
                    }
                    else if(arr[row][now]!=arr[row][col])
                    {
                        break;
                    }
                }
            }
        }
        stack(4);
        break;
    }
    
}

void Data::swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Data::stack(int in)
{
    if(in == 2)
    {
        for(int col=0;col!=4;col++)
        {
            for(int now = 0;now!=3;now++)
            {
                for(int row = now;row!=4;row++)
                {
                    if(arr[row][col]==0)
                    {
                        swap(&arr[row][col] , &arr[row-1][col]);
                    }
                }
            }
        }
    }
    else if(in == 1)
    {
        for(int col=0;col!=4;col++)
        {
            for(int now = 3;now>0;now--)
            {
                for(int row = now;row>=0;row--)
                {
                    if(arr[row][col]==0)
                    {
                    swap(&arr[row][col] , &arr[row+1][col]);
                    }
                }
            }
        }
    }
    else if(in == 4)
    {
        for(int row=0;row!=4;row++)
        {
            for(int now = 3;now>0;now--)
            {
                for(int col = now;col>0;col--)
                    {
                    if(arr[row][col]==0)
                    {
                        swap(&arr[row][col] , &arr[row][col-1]);
                    }
                }
            }
        }
    }
    else if(in == 3)
    {
    for(int row=0;row!=4;row++)
    {
        for(int now = 0;now!=3;now++)
        {

            for(int col=now;col<3;col++)
            {
                if(arr[row][col]==0)
                {
                    swap(&arr[row][col] , &arr[row][col+1]);
            }
            }
        }
    }
    }
    
}

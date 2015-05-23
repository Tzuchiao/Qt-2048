//
//  data.h
//  C++2048
//
//  Created by TzuChiao Yeh on 2015/5/15.
//  Copyright (c) 2015年 TzuChiao Yeh. All rights reserved.
//

#ifndef __C__2048__data__
#define __C__2048__data__

#include <stdio.h>

class Data
{
public:
    Data(){};
    ~Data(){};
    void move(int in);
    void init();
    void create();
    void stack(int in);
    static int arr[4][4];
    int score;
    int final;
    
private:
    void swap(int *,int *);
    int fullcount;

};


#endif /* defined(__C__2048__data__) */

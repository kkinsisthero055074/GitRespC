#pragma once
#include <stdio.h>
//随机变量随着时间而变化
#include <stdlib.h>
#include <time.h>


//符号定义
#define ROW 3
#define COL 3

//函数的声明
//初始化棋盘
void InitBoard(char arr[ROW][COL], int row, int col);  //数组中行可以省略，但是列不能省略

//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row,int col);

//玩家下棋
void PlayerMover(char board[ROW][COL],int row,int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断是否赢了游戏 1玩家赢* 2电脑赢# 3平局Q 4游戏继续C
char IsWin(char board[ROW][COL],int row,int col);
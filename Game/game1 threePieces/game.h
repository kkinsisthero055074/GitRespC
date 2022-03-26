#pragma once
#include <stdio.h>
//符号定义
#define ROW 3
#define COL 3

//函数的声明
//初始化棋盘
void InitBoard(char arr[ROW][COL], int row, int col);  //数组中行可以省略，但是列不能省略

//打印棋盘
void DisplayBoard(char arr[ROW][COL], int row,int col);
#pragma once
#include <iostream>
#include <string>
using namespace std;

int find(string zhao);//将汉字转化为数字
void find(int num);//将数字转化为汉字
int find(const string& pipei, int);//用于分析语句的意思并返回值
//find函数重载

void dingyi(int& money, string& wen);//初始化钱包
void jianfa(int& money, string& wen);//减法操作
void jiafa(int& money, string& wen);//加法操作
//功能函数

const char shu[11][3] = { "零","一", "二","三","四","五","六","七","八","九","十" };
//对基本的汉字进行定义
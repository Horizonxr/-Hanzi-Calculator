#pragma once
#include <iostream>
#include <string>
using namespace std;

int find(string zhao);//������ת��Ϊ����
void find(int num);//������ת��Ϊ����
int find(const string& pipei, int);//���ڷ���������˼������ֵ
//find��������

void dingyi(int& money, string& wen);//��ʼ��Ǯ��
void jianfa(int& money, string& wen);//��������
void jiafa(int& money, string& wen);//�ӷ�����
//���ܺ���

const char shu[11][3] = { "��","һ", "��","��","��","��","��","��","��","��","ʮ" };
//�Ի����ĺ��ֽ��ж���
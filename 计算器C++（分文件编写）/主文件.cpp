#include  <fstream>
#include "汉语言计算头文件.h"

int main() {
	int money = 100;
	string a;
	ifstream ifs;
	ifs.open("test01.txt", ios::in);
	while (getline(ifs,a)) {//通过返回值类型判断要执行哪个操作
		switch (find(a, 1)) {
		case 1://定义钱包初始数额
			dingyi(money, a); break;
		case 2://看看钱包还有多少数额
			find(money); break;
		case 3://对钱包做加法运算
			jiafa(money, a); break;
		case 4://对钱包做减法运算
			jianfa(money, a); break;
		default://异常状况
			cout << "非法输入" << endl;
		}
		if (find(a, 1) == 2) break;
		else continue;
	}
	ifs.close();
	return 0;
}
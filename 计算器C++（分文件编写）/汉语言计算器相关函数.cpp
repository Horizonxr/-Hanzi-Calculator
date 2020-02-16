#include "汉语言计算头文件.h"

//汉字转化为数字
int find(string zhao) {
	int len = zhao.length();
	int sum = 0;
	int i, flag = 0,fu = 1;
	string yuan;
	//针对负数的情况
	if (zhao.compare(0, 2, "负") == 0) {
		fu = 0;
		len -= 2;
		zhao = zhao.substr(2, len);
	}
	//三个汉字
	if (len == 6) {
		for (i = 0; i < 11; i++) {
			if (zhao.compare(0, 2, shu[i]) == 0) {
				sum += 10 * i;
				flag = 1;
				break;
			}
			if (flag == 0 && i == 10) return -1;
		}
		flag = 0;
		for (i = 0; i < 11; i++) {
			if (zhao.compare(4, 2, shu[i]) == 0) {
				sum += i;
				flag = 1;
				break;
			}
			if (flag == 0 && i == 10) return -1;
		}
	}
	//两个汉字
	else if (len == 4) {
		sum = 1;
		for (i = 0; i < 11; i++) {
			if (zhao.compare(0, 2, shu[i]) == 0) {
				flag = 1;
				break;
			}
		}
		if (i == 10) {
			for (i = 0; i < 11; i++) {
				if (zhao.compare(2, 2, shu[i]) == 0) {
					flag = 1;
					break;
				}
			}
			sum = 10 + i;
		}
		else if (i < 10 && i>0) {
			sum = i * 10;
		}
		else if (flag == 0 && i == 10) return -1;
	}
	//一个汉字
	else if (len == 2) {
		for (i = 0; i < 11; i++) {
			if (zhao.compare(0, 2, shu[i]) == 0) {
				sum += i;
				flag = 1;
				break;
			}
			if (flag == 0 && i == 10) return -1;
		}
	}
	if (fu == 0) {
		sum *= -1;
	}
	return sum;
}

//数字转化为汉字
void find(int num) {
	if (num < 0) {
		cout << "负";
		num *= -1;
	}
	if (num <= 10 && num >= 0) {
		cout << shu[num] << endl;
	}
	else if (num > 10 && num < 100) {
		cout << shu[num / 10] << "十" << shu[num % 10] << endl;
	}
	else if (num >= 100 && num <= 999) {
		cout << shu[num / 100] << "百";
		if (num / 10 % 10 != 0) {
			cout << shu[num / 10 % 10] << "十";
		}
		else if (num % 10 != 0)cout << "零";
		if (num % 10 != 0) {
			cout << shu[num % 10];
		}
		cout << endl;
	}
}

//寻找匹配的字符串
int find(const string& pipei, int) {
	string kankan = "看看 钱包";
	string yuan = "整数 钱包 等于";
	string jia = "钱包 增加";
	string jian = "钱包 减少";
	string temp;
	//定义钱包初始数额
	if (pipei.compare(0, 13, yuan, 0, 13) == 0) return 1;
	//看看钱包的余额
	else if (pipei.compare(0, 9, kankan, 0, 9) == 0) return 2;
	//对余额进行加法操作
	else if (pipei.compare(0, 9, jia, 0, 9) == 0) return 3;
	//对余额进行减法操作
	else if (pipei.compare(0, 9, jian, 0, 9) == 0) return 4;
	//异常处理
	else return -1;
}

//定义钱包初始数额
void dingyi(int& money, string& wen) {
	int len = wen.length();
	string temp = wen.substr(15, len);
	if (find(temp) != -1) {
		money = find(temp);
	}
	else {
		printf("非法输入\n");//异常处理
	}
}

//对钱包做加法运算
void jianfa(int& money, string& wen) {
	//printf("4");
	int len = wen.length();
	string temp = wen.substr(10, len);
	if (find(temp) != -1) {
		money -= find(temp);
	}
	else {
		printf("非法输入\n");//异常处理
	}
}

//对钱包做减法运算
void jiafa(int& money, string& wen) {
	//printf("3");
	int len = wen.length();
	string temp = wen.substr(10, len);
	if (find(temp) != -1) {
		money += find(temp);
	}
	else {
		printf("非法输入\n");//异常处理
	}
}
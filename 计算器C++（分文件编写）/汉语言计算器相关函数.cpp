#include "�����Լ���ͷ�ļ�.h"

//����ת��Ϊ����
int find(string zhao) {
	int len = zhao.length();
	int sum = 0;
	int i, flag = 0,fu = 1;
	string yuan;
	//��Ը��������
	if (zhao.compare(0, 2, "��") == 0) {
		fu = 0;
		len -= 2;
		zhao = zhao.substr(2, len);
	}
	//��������
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
	//��������
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
	//һ������
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

//����ת��Ϊ����
void find(int num) {
	if (num < 0) {
		cout << "��";
		num *= -1;
	}
	if (num <= 10 && num >= 0) {
		cout << shu[num] << endl;
	}
	else if (num > 10 && num < 100) {
		cout << shu[num / 10] << "ʮ" << shu[num % 10] << endl;
	}
	else if (num >= 100 && num <= 999) {
		cout << shu[num / 100] << "��";
		if (num / 10 % 10 != 0) {
			cout << shu[num / 10 % 10] << "ʮ";
		}
		else if (num % 10 != 0)cout << "��";
		if (num % 10 != 0) {
			cout << shu[num % 10];
		}
		cout << endl;
	}
}

//Ѱ��ƥ����ַ���
int find(const string& pipei, int) {
	string kankan = "���� Ǯ��";
	string yuan = "���� Ǯ�� ����";
	string jia = "Ǯ�� ����";
	string jian = "Ǯ�� ����";
	string temp;
	//����Ǯ����ʼ����
	if (pipei.compare(0, 13, yuan, 0, 13) == 0) return 1;
	//����Ǯ�������
	else if (pipei.compare(0, 9, kankan, 0, 9) == 0) return 2;
	//�������мӷ�����
	else if (pipei.compare(0, 9, jia, 0, 9) == 0) return 3;
	//�������м�������
	else if (pipei.compare(0, 9, jian, 0, 9) == 0) return 4;
	//�쳣����
	else return -1;
}

//����Ǯ����ʼ����
void dingyi(int& money, string& wen) {
	int len = wen.length();
	string temp = wen.substr(15, len);
	if (find(temp) != -1) {
		money = find(temp);
	}
	else {
		printf("�Ƿ�����\n");//�쳣����
	}
}

//��Ǯ�����ӷ�����
void jianfa(int& money, string& wen) {
	//printf("4");
	int len = wen.length();
	string temp = wen.substr(10, len);
	if (find(temp) != -1) {
		money -= find(temp);
	}
	else {
		printf("�Ƿ�����\n");//�쳣����
	}
}

//��Ǯ������������
void jiafa(int& money, string& wen) {
	//printf("3");
	int len = wen.length();
	string temp = wen.substr(10, len);
	if (find(temp) != -1) {
		money += find(temp);
	}
	else {
		printf("�Ƿ�����\n");//�쳣����
	}
}
#include  <fstream>
#include "�����Լ���ͷ�ļ�.h"

int main() {
	int money = 100;
	string a;
	ifstream ifs;
	ifs.open("test01.txt", ios::in);
	while (getline(ifs,a)) {//ͨ������ֵ�����ж�Ҫִ���ĸ�����
		switch (find(a, 1)) {
		case 1://����Ǯ����ʼ����
			dingyi(money, a); break;
		case 2://����Ǯ�����ж�������
			find(money); break;
		case 3://��Ǯ�����ӷ�����
			jiafa(money, a); break;
		case 4://��Ǯ������������
			jianfa(money, a); break;
		default://�쳣״��
			cout << "�Ƿ�����" << endl;
		}
		if (find(a, 1) == 2) break;
		else continue;
	}
	ifs.close();
	return 0;
}
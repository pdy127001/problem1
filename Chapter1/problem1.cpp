#include<iostream>
#include"problem1.h"
using namespace std;
int main() {
	int status[4] = {};
	int potion[2] = {};
	int act = 0;
	int potion_recovery_amount = 20;
	int skill_MP_cost = 50;
	cout << "HP�� MP�� �Է����ּ���:";
	cin >> status[0] >> status[1];
	if(status[0] <= 50 || status[1] <= 50) {
		cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
		cin >> status[0] >> status[1];
	}

	cout << "���ݷ°� ������ �Է����ּ��� : ";
	cin >> status[2] >> status[3];
	if(status[2] <= 0 || status[3] <= 00) {
		cout << "���ݷ°� ������ ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
		cin >> status[2] >> status[3];
	}
	setPotion(5, &potion[0], &potion[1]);	
	cout << "*������ ���޵Ǿ����ϴ�.(HP, MP���� �� 5��)" << endl;
	cout << "=======================================================================" << endl;
	cout << "<���� ���� �ý���>"<<endl;
	cout<<"1.HP ȸ��\n"<<
		"2.MP ȸ��\n"<<
		"3.HP ��ȭ\n"<<
		"4.MP ��ȭ\n"<<
		"5.���� ��ų ���\n"<<
		"6. �ʻ�� ���\n"<<
		"7. ������"<<endl;
	for (;;) {
		cout << "��ȣ�� �������ּ���:";
		cin >> act;
		switch (act) {
		case 1:
			if (verifyPotion(&potion[0])) {
				status[0] += potion_recovery_amount;
				potion[0]--;
				cout << "*HP�� " << potion_recovery_amount << "��ŭ ȸ���Ǿ����ϴ�.������ 1�� �����˴ϴ�." << endl;
				cout << "���� HP: " << status[0] << endl;
				cout << "���� HP ���� ��: " << potion[0] << endl;
			}
			break;
		case 2:
			if (verifyPotion(&potion[1])) {
				status[1] += potion_recovery_amount;
				potion[1]--;
				cout << "*MP�� " << potion_recovery_amount << "��ŭ ȸ���Ǿ����ϴ�.������ 1�� �����˴ϴ�." << endl;
				cout << "���� MP: " << status[1] << endl;
				cout << "���� MP ���� ��: " << potion[1] << endl;
			}
			break;
		case 3:
			cout << " * HP�� 2��� �����Ǿ����ϴ�." << endl;
			status[0] *= 2;
			cout << "���� HP: " << status[0] << endl;
			break;
		case 4:
			cout << " * MP�� 2��� �����Ǿ����ϴ�." << endl;
			status[1] *= 2;
			cout << "���� HP: " << status[1] << endl;
			break;
		case 5:
			cout << "*��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�." << endl;
			if (status[1] < skill_MP_cost) {
				cout << "MP�� �����մϴ�. ��ų�� ����� �� �����ϴ�." << endl;
			} else {
				status[1] -= skill_MP_cost;
				cout << "���� MP: " << status[1] << endl;
			}
			break;
		case 6:
			cout << "*��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�." << endl;
			if (status[1]<=1) {
				cout << "MP�� �����մϴ�. ��ų�� ����� �� �����ϴ�." << endl;
			} else {
				status[1] /=2;
				cout << "���� MP: " << status[1] << endl;
			}
			break;
		case 7:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���." << endl;
			break;
		}
	}
	
	return 0;
}
void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
	return;
}
bool verifyPotion(int* p_Potion) {
	if (*p_Potion <= 0) {
		cout << "������ �����մϴ�." << endl;
		return false;
	}
	return true;
}
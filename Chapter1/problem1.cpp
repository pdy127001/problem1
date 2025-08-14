#include<iostream>
#include"problem1.h"
using namespace std;
int main() {
	int status[4] = {};
	int potion[2] = {};
	int act = 0;
	int potion_recovery_amount = 20;
	int skill_MP_cost = 50;
	cout << "HP와 MP를 입력해주세요:";
	cin >> status[0] >> status[1];
	if(status[0] <= 50 || status[1] <= 50) {
		cout << "HP와 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		cin >> status[0] >> status[1];
	}

	cout << "공격력과 방어력을 입력해주세요 : ";
	cin >> status[2] >> status[3];
	if(status[2] <= 0 || status[3] <= 00) {
		cout << "공격력과 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
		cin >> status[2] >> status[3];
	}
	setPotion(5, &potion[0], &potion[1]);	
	cout << "*포션이 지급되었습니다.(HP, MP포션 각 5개)" << endl;
	cout << "=======================================================================" << endl;
	cout << "<스탯 관리 시스템>"<<endl;
	cout<<"1.HP 회복\n"<<
		"2.MP 회복\n"<<
		"3.HP 강화\n"<<
		"4.MP 강화\n"<<
		"5.공격 스킬 사용\n"<<
		"6. 필살기 사용\n"<<
		"7. 나가기"<<endl;
	for (;;) {
		cout << "번호를 선택해주세요:";
		cin >> act;
		switch (act) {
		case 1:
			if (verifyPotion(&potion[0])) {
				status[0] += potion_recovery_amount;
				potion[0]--;
				cout << "*HP가 " << potion_recovery_amount << "만큼 회복되었습니다.포션이 1개 차감됩니다." << endl;
				cout << "현재 HP: " << status[0] << endl;
				cout << "남은 HP 포션 수: " << potion[0] << endl;
			}
			break;
		case 2:
			if (verifyPotion(&potion[1])) {
				status[1] += potion_recovery_amount;
				potion[1]--;
				cout << "*MP가 " << potion_recovery_amount << "만큼 회복되었습니다.포션이 1개 차감됩니다." << endl;
				cout << "현재 MP: " << status[1] << endl;
				cout << "남은 MP 포션 수: " << potion[1] << endl;
			}
			break;
		case 3:
			cout << " * HP가 2배로 증가되었습니다." << endl;
			status[0] *= 2;
			cout << "현재 HP: " << status[0] << endl;
			break;
		case 4:
			cout << " * MP가 2배로 증가되었습니다." << endl;
			status[1] *= 2;
			cout << "현재 HP: " << status[1] << endl;
			break;
		case 5:
			cout << "*스킬을 사용하여 MP가 50 소모되었습니다." << endl;
			if (status[1] < skill_MP_cost) {
				cout << "MP가 부족합니다. 스킬을 사용할 수 없습니다." << endl;
			} else {
				status[1] -= skill_MP_cost;
				cout << "현재 MP: " << status[1] << endl;
			}
			break;
		case 6:
			cout << "*스킬을 사용하여 MP가 50% 소모되었습니다." << endl;
			if (status[1]<=1) {
				cout << "MP가 부족합니다. 스킬을 사용할 수 없습니다." << endl;
			} else {
				status[1] /=2;
				cout << "현재 MP: " << status[1] << endl;
			}
			break;
		case 7:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다. 다시 시도해주세요." << endl;
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
		cout << "포션이 부족합니다." << endl;
		return false;
	}
	return true;
}
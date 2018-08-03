
//uva166
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#define CNUM 6
#define cinF 1000000000
#define DOL 501

using namespace std;

int main() {
	int price[CNUM] = {5, 10, 20, 50, 100, 200};
	int coin[CNUM], dpShop[DOL], dpUser[DOL];
	int ans;
	double money;

	while(1) {
		// read data
		money = 0;
		for(int i = 0; i < CNUM; i++) {
			cin >> coin[i];
			money += coin[i];
		}
		if(money == 0)
			break;
		cin >> money;
		money *= 100;	// ���H100�H��K�p��

		// initialize
		for(int i = 0; i < DOL; i++) {
			dpShop[i] = cinF;	// dpShop[i] = �Ӯa�b���Ȭ� i �ɪ��ֵ̤w�����`�M
			dpUser[i] = cinF;	// dpUser[i] = �ϥΪ̦b���Ȭ� i �ɪ��ֵ̤w�����`�M
		}
		dpShop[0] = 0;
		dpUser[0] = 0;
		ans = cinF;

		// �Ӯa�L���ϥεw��
		for(int i = 0; i < CNUM; i++) {
			for(int j = 0; j < DOL; j+=5) {
				if(j - price[i] >= 0 && dpShop[j - price[i]] != cinF)
					dpShop[j] = min(dpShop[j], dpShop[j - price[i]] + 1);
			}
		}

		// �ϥΪ̦����ϥεw��
		for(int i = 0; i < CNUM; i++) {
			for(int j = 0; j < coin[i]; j++) {
				for(int k = DOL - 1; k >= 0; k-=5) {
					if(k - price[i] >= 0)
						dpUser[k] = min(dpUser[k], dpUser[k - price[i]] + 1);
				}
			}
		}

		// ��X�ֵ̤w����
		for(int i = (int)(money + 0.5); i < DOL; i++)	// + 0.5 �� double �� int ����
			ans = min(ans, dpShop[i - (int)(money + 0.5)] + dpUser[i]);
		cout << setw(3) << ans << endl;
	}

	return 0;
}

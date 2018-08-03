
//uva11085
#include<iostream>
#include <stdio.h>
using namespace std;
int num = 0;
int ans[100][8], temp[8];
bool row[8] = {false};
bool left_go[15] = {false};
bool right_go[15] = {false};
void eightQueen(int c){
	if(c == 8){
		for(int i = 0; i < 8; i++)
			ans[num][i] = temp[i] + 1;
		num++;
		return;
	}
	for(int i = 0; i < 8; i++){
		int ll = c - i + 7;
		int rr = c + i;
		if((!row[i]) && (!left_go[ll]) && (!right_go[rr])){
			row[i] = left_go[ll] = right_go[rr] = 1;
			temp[c] = i;
			eightQueen(c + 1);
			row[i] = left_go[ll] = right_go[rr] = 0;
		}
	}
}

int main(){
	eightQueen(0);
	int case_n, i, j, input[8], min;
	case_n = 1;
	while(cin >> input[0]){
		for(i = 1; i < 8; i++)
			cin>>input[i];
		min = 99999;
		for(i=0;i<num;i++){
			int moveCount = 0;
			for(j=0;j<8;j++){
				if(ans[i][j] != input[j]){
					moveCount ++;
				}
			}
			if(moveCount < min)
                min = moveCount;
		}
		cout << "Case " << case_n << ": " << min << endl;
		case_n++;
	}
	return 0;
}

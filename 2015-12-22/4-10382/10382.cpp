
//uva10382
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct segment {
	double leftEnd, rightEnd;
};

int cmp(segment a, segment b) {
	return a.leftEnd < b.leftEnd;
}

segment sprinter[10005];
int main() {
	int n, l, w;  // �x�����ƥ� n ,��a���B�e: l,w
	while(scanf("%d %d %d", &n, &l, &w) == 3) {
		double sp, sr;      // �x��������m�B�M�x���b�|
		int esNum = 0;        
		for(int i = 0; i < n; i++) {
			scanf("%lf %lf", &sp, &sr);   //Ū�J�x��������m�M�x���b�|
			if(2 * sr <= w)
				continue;                 //�p�G�x�����|�p���a�e�סB���x�������p�]�л\���׬��s
			double eLength = sqrt(sr * sr - w * w / 4.0);
			sprinter[esNum].leftEnd = sp - eLength;
			sprinter[esNum++].rightEnd = sp + eLength; //�x�������л\���u�q�����B�k���I
		}
		sort(sprinter, sprinter + esNum, cmp);
		int ans = 0, flag = 0;
		if(sprinter[0].leftEnd > 0) {
			printf("-1\n");    //���䥼��[�\�B�L��,��X-1
			continue;
		}
		double coveredLeftEnd = 0, coveredRightEnd = 0;
		int sl = 0;
		while(coveredLeftEnd < l) {    //�w�[�\�����ݭY���p���a���׫h�̳g���k�ѥN���x�������}�C�ѥ���k��ܯ�N�����л\�̦h���x�����ç�s�w�[�\�����B�k��
			for(int i = sl; i < esNum; i++) {
				if(sprinter[i].leftEnd <= coveredLeftEnd && sprinter[i].rightEnd > coveredRightEnd) {
					coveredRightEnd = sprinter[i].rightEnd;
					sl = i;
				}
			}
			if(coveredLeftEnd == coveredRightEnd) {
				flag = 1;
				break;
			}
			coveredLeftEnd = coveredRightEnd;
			ans++;
		}
		if(!flag)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
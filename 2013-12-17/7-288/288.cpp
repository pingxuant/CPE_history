
//uva288
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MYDIG	100

int lastchar = -1;
struct longnum {
	int *n;
	int sign;
	int msd;
};

typedef struct longnum LNUM;
char runops[128] = {0};
char op = 0;
LNUM num[128], mytmp, myexp;
int sp = 0;

void showans() {
	LNUM* a = num;
	int k;
	char dump[4000], *p = dump;
	int i, len;
	if(a -> sign == -1)p += sprintf(p, "-");
	p += sprintf(p, "%d", a -> n[a -> msd-1]);
	for(k = a -> msd-2; k >= 0; --k)
		p += sprintf(p, "%02d", a -> n[k]);
	len = p - dump;
	
	for(i = 0; len > 75; len -= 75, i += 75)
		printf("%.75s\\\\\n", dump + i);
	printf("%s", dump + i);
	putchar('\n');
	free(a -> n);
}

void domul(LNUM *a, LNUM *b){
	if(a -> msd == 1 && a -> n[0] == 0) return;
	if(b -> msd == 1 && b -> n[0] == 0) {
		a -> msd = 1;
		a -> sign = 1;
		a -> n[0] = 0;
		return;
	}
	if(b -> msd == 1 && b -> n[0] == 1) return;
	LNUM *t = &mytmp;
	LNUM *c, *d;
	int i, k, j;
	int newsign = a -> sign*b -> sign;
	if(a -> msd > b -> msd) {
		c = a;
		d = b;
	}
	else {
		c = b;
		d = a;
	}
	int *tn = (int*)malloc(sizeof(int) * (a -> msd + b -> msd));
	int cy, sum;
	for(i = cy = 0; i < d -> msd - 1; ++i) {
		for(sum = cy, k = 0; k <= i; k++)
			sum = sum + c -> n[i - k] * d -> n[k];
		tn[i] = sum % MYDIG;
		cy = sum / MYDIG;
	}
	for(; i < c -> msd; ++i) {
		for(sum = cy, k = 0; k < d -> msd; k++)
			sum = sum + c -> n[i - k] * d -> n[k];
		tn[i] = sum % MYDIG;
		cy = sum / MYDIG;
	}
	for(j = 1; i < c -> msd + d -> msd - 1; ++i, ++j) {
		for(sum = cy, k = j; k < d -> msd; k++)
			sum = sum + c -> n[i - k] * d -> n[k];
		tn[i] = sum % MYDIG;
		cy = sum / MYDIG;
	}
	if(cy > 0) tn[i++] = cy;
	a -> msd = i;
	free(a -> n);
	a -> n = tn;
	a -> sign = newsign;
}

void doadd(LNUM *a, LNUM *b) {
	LNUM *c;
	int min, max;
	if(a -> msd > b -> msd) {
		c = a;
		max = a -> msd;
		min = b -> msd;
	}
	else {
		c = b;
		max = b -> msd;
		min = a -> msd;
	}
	int *tn = (int*)malloc(sizeof(int) * (max + 1));
	int i, cy, sum;
	for(cy = i = 0; i < min; ++i){
		sum = cy + a -> n[i] + b -> n[i];
		tn[i] = sum % MYDIG;
		cy = sum / MYDIG;
	}
	for(; i < max; ++i){
		sum = cy + c -> n[i];
		tn[i] = sum % MYDIG;
		cy = sum / MYDIG;
	}
	if(cy > 0) tn[i++] = cy;
	a -> msd = i;
	free(a -> n);
	a -> n = tn;
}

void doexp(LNUM *a, LNUM *b){
	if(a -> msd == 1 && a -> n[0] == 1)
		return;
	if(b -> msd == 1 && b -> n[0] == 0) {
		a -> msd = 1;
		a -> sign = 1;
		a -> n[0] = 1;
		return;
	}
	if(b -> msd == 1 && b -> n[0] == 1)
		return;
#define MYEXPSHIFT 16
#define MYEXPMASK 0xffff
	unsigned long v[100];
	int i, j, vlen = 0,  sum,  cy;
	for(i = 0; i < 100; ++i) v[i] = 0;
	for(i = b -> msd - 1; i >= 0;--i) {
		for(sum = b -> n[i], cy = j = 0; j <= vlen; j++){
			sum += v[j] * MYDIG + cy;
			v[j] = sum & MYEXPMASK;
			cy = sum >> MYEXPSHIFT;
			sum = 0;
		}
		if(cy){
			v[j++] = cy;
			vlen++;
		}
	}
	int *tn = (int*)malloc(sizeof(int) * 1);
	LNUM*e = &myexp;
	e -> n = a -> n;
	e -> sign = a -> sign;
	e -> msd = a -> msd;
	a -> sign = 1;
	a -> msd = 1;
	a -> n = tn;
	a -> n[0] = 1;
	for(i = 0; i <= vlen; ++i) {
		for(j = 0; j < 16; ++j) {
			if((v[i] & 1) == 1) domul(a, e);
			v[i] >>= 1;
			if(i == vlen && v[i] == 0) break;
			domul(e, e);
		}
	}
}

void dosub(LNUM *a, LNUM *b){
	LNUM *c, *d;
	int i, flag;
	if(a -> msd > b -> msd) flag = 1;
	else if(a -> msd < b -> msd) flag = 0;
	else {
		for(i = a -> msd-1; i >= 0 && a -> n[i] == b -> n[i]; i--);
		if(i < 0) {
			a -> n[0] = 0;
			a -> sign = 1;
			a -> msd = 1;
			return;
		}
		flag = a -> n[i] > b -> n[i] ? 1 : 0;
	}
	if(flag) c = a, d = b;
	else c = b, d = a;
	
	int max = c -> msd;
	int cy, sum;
	int *tn = (int*)malloc(sizeof(int) * max);
	for(cy = i = 0; i < max; ++i){
		if(i < d -> msd)
		  sum = c -> n[i] - d -> n[i] - cy;
		else
		  sum = c -> n[i] - cy;
		if(sum < 0) {
		  sum = sum + MYDIG;
		  cy = 1;
		}
		else cy = 0;
		tn[i] = sum;
	}
	for(i--; i > 0 && tn[i] == 0; --i);
	a -> msd = i + 1;
	if(flag == 0)
		a -> sign = c -> sign;
	free(a -> n);
	a -> n = tn;
}

void docal(){
	LNUM*a = num + sp - 2;
	LNUM*b = num + sp - 1;
	char opcode = runops[--op];
	switch(opcode) {
	case '+':
		if(a -> sign == b -> sign) doadd(a, b);
		else dosub(a, b);
		--sp;
		break;
	case '-':
		b -> sign *= -1;
		if(a -> sign == b -> sign) doadd(a, b);
		else dosub(a, b);
		--sp;
		break;
	case '*':
		domul(a, b);
		--sp;
		break;
	case '^':
		doexp(a, b);
		--sp;
		break;
	}
}
int checkop(){
	char flag = lastchar;
	char last;
	if(lastchar == 0 || lastchar == '\n' || lastchar == EOF) flag='$';
	else {
		char lastchar2 = getchar();
		if(lastchar == '*' && lastchar2 == '*'){
			flag='^';
			lastchar = getchar();
		}
		else lastchar = lastchar2;
	}
	while(op > 0) {
		last = runops[op-1];
		if(flag == '+' || flag == '-') {
			docal();
			continue;
		}
		else if(flag == '*') {
			if(last == '^' || last == '*') {
				docal();
				continue;
			}
		}
		else if(flag == '^')
			break;
		else{
			docal();
			continue;
		}
		break;
	}
	runops[op++] = flag;
	return flag == '$' ? 0 : 1;
}			
int checkexp(){
	for(;;){
		if(lastchar == EOF) return 1;
		if('0' <= lastchar && lastchar <= '9' || lastchar == '-' || lastchar == '+') return 0;
		lastchar = getchar();
	}
}
void loadlnum(){
	int i;
	char buf[1004];
	char *p, *s;
	LNUM *a = num + sp;
	++sp;
	int mysign = 1;
	if(lastchar == '-') {
		mysign = -1;
		lastchar = getchar();
	}
	else if(lastchar == '+') {
		mysign = 1;
		lastchar = getchar();
	}
	for(s = buf; '0' <= lastchar && lastchar <= '9'; ++s){
		*s = lastchar;
		lastchar = getchar();
	}
	char *t = buf;
	while(*t == '0') t++;
	if(t == s) t--;
	a -> n = (int*)malloc(sizeof(int) * ((s - t + 2) >> 1));
	for(i = 0, s--, p = t; s >= p; s -= 2, ++i)
		a -> n[i] = *s - '0' + (s - p - 1 >= 0 ? (*(s-1) - '0') * 10 : 0);
	if(i == 1 && a -> n[0] == 0) mysign = 1;
	a -> sign = mysign;
	a -> msd = i;
}

int main(void) {
	lastchar = getchar();
	int i;
	for(i = 0; ; ++i) {
		for(op = sp = 0;;) {
			loadlnum();
			if(checkop() == 0) break;
		}
		if(i)
			printf("\n");
		showans();
		if(checkexp() == 1) break;
	}
	return 0;
}

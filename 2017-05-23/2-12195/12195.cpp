
//uva12195
#include <stdio.h>
#include <stdlib.h>

double symbol(char s);

int main(void) {
    int num = 0;
    double duration = 0, sum = 0;
    char c;
	
    while (1) {
	    c = getchar();
	    if (c == 0xA) {
		    printf("%d\n", num);
		    num = 0;
	    }
	    else if (c == 0x2A)
		    break;
	
	    duration = symbol(c);
	    if (duration == 0) {
		    if (sum == 1)
			    num++;
			
		    sum = 0;
	    }
	    else
		    sum = sum + duration;
	    }
	return 0;
}

double symbol(char s) {
    double duration;
    switch (s) {
	    case 'W':
		    duration = 1;
		    break;
	    case 'H':
		    duration = 0.5;
		    break;
	    case 'Q':
		    duration = 0.25;
		    break;
	    case 'E':
		    duration = 0.125;
		    break;
	    case 'S':
		    duration = 0.0625;
		    break;
	    case 'T':
		    duration = 0.03125;
		    break;
	    case 'X':
		    duration = 0.015625;
		    break;
	    case '/':
		    duration = 0;
		    break;
    }
    return duration;
}

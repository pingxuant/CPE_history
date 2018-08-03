
//uva10090
#include <iostream>
#include <cmath>
// ¬éå¾¸å­¸è«ï¼http://tutorial92.wordpress.com/2012/09/17/uva-10090-marbles-tutorial/

using namespace std;

// æ±å¤§å¬å¸çï¼¨è¼¾è½¸é¤æ¹æ§æ n1 * m1 + n2 * m2 = gcd(n1, n2)  m1, m2 
// (¸é¥èï¼https://zh.wikipedia.org/wiki/%E6%89%A9%E5%B1%95%E6%AC%A7%E5%87%A0%E9%87%8C%E5%BE%97%E7%AE%97%E6%B3%95)
long long int GCD(long long int a, long long int b, long long int *x, long long int *y) {
	// ç¢ºä a å¤§æ b
	if(a < b) {
		long long int buf, *bufP;
		
		buf = a;
		a = b;
		b = buf;
		
		bufP = x;
		x = y;
		y = bufP;
	}
	
	// è¼¾è¸é¤æç®å®æ¢ä»
	if(b == 0) {
		*x = 1;
		*y = 0;
		return a;
	}

	long long int gcd, retX, retY;

	// è¿´ææ±ºæå¤§å¬å
	gcd = GCD(b, a % b, &retX, &retY);
	
	// è¨ç® m1, m2 
	*x = retY;
	*y = retX - (a / b) * retY;

	return gcd;
}

int main() {
	long long int total, cost1, num1, cost2, num2, box1, box2;

	while(cin >> total) {
		if(total == 0)
			break;

		long long int gcd, bufBox1, bufBox2, myCeil, myFloor, myCost;

		// get input
		cin >> cost1 >> num1 >> cost2 >> num2;

		// get GCD
		gcd = GCD(num1, num2, &bufBox1, &bufBox2);
		
		// N ä¸´é gcd è¡¨ç¤ºä¸ç®¡æéº¼æ½æä¸ºä
		if(total % gcd != 0)
			cout << "failed" << endl;
		else {
			//  n1 * m1 + n2 * m2 = gcd(n1, n2)  n1 * m1 + n2 * m2 = N
			bufBox1 *= (total / gcd);
			bufBox2 *= (total / gcd);
			
			// ceil(-m1 * gcd / n2) <= t <= floor(m2 * gcd / n1) - è©³é"¬éå¾¸å­¸è«"
			myCeil = (long long int)ceil(-(double)bufBox1 * gcd / num2);
			myFloor = (long long int)floor((double)bufBox2 * gcd / num1);
			
			// ceil() > floor()  t ä¸å­
			if(myCeil > myFloor)
				cout << "failed" << endl;
			else {
				// cost = c1 * m1 + c2 * m2 = c1 * ( m1 + n2 / gcd * t ) + c2 * ( m2  n1 / gcd * t)
				//		= c1 * m1 + c2 * m2 + t * (c1 * n2 / gcd  c2 * n1 / gcd)
				// ±æ c1 * m1 + c2 * m2 ä¸å½±é¿çï¼æ­¤é¨åä¾¿ç¥èç® - ç®å¼ç´°çè©³é"¬éå¾¸å­¸è«"
				myCost = (cost1 * num2 / gcd) - (cost2 * num1 / gcd);
				
				// å° box ¸å¨æ¥µç«¯äç½
				if(myCost * myCeil < myCost * myFloor) {
					box1 = bufBox1 + num2 / gcd * myCeil;
					box2 = bufBox2 - num1 / gcd * myCeil;
				}
				else {
					box1 = bufBox1 + num2 / gcd * myFloor;
					box2 = bufBox2 - num1 / gcd * myFloor;
				}
				
				// è¼¸åºæçµç­æ¡
				cout << box1 << ' ' << box2 << endl;
			}
		}
	}

	return 0;
}

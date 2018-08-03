
//uva11364
#include <iostream>

using namespace std;

int main()
{
	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; i++) {
		int numStores, minPosition = 100, maxPosition = -1;
		cin >> numStores;

		for (int j = 0; j < numStores; j++) {
			int position;
			cin >> position;

			if (position > maxPosition) {
				maxPosition = position;
			}

			if (position < minPosition) {
				minPosition = position;
			}
		}

		cout << (maxPosition - minPosition) * 2 << endl;
	}

	return 0;
}


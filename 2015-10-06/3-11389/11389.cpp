
//uva11389
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, d, r;
	int morning[105], night[105];
	while ((cin >> n >> d >> r) && (n || d || r)) {
		for (int i = 0; i < n; ++i)
			cin >> morning[i];
		for (int i = 0; i < n; ++i)
			cin >>night[i];

		sort(morning, morning + n);
		sort(night, night + n);

		int fine = 0;
		for (int i = 0; i < n; ++i)
			if (morning[i] + night[n - i - 1] > d)
				fine += ((morning[i] + night[n - i - 1] - d) * r);
		cout << fine << endl;
	}
	return 0;
}

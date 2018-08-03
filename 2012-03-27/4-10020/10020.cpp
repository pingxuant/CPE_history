
//uva10020
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/**
* Why can I use greedy?
*
* ---------a-
* -----b-
*           ---x-
*     ---------------y-
* ===========cover=
*
* While I greedily choose `a', I still can choose `y' next round.
*/

class Segment {
public:
	int left, right;
	
	Segment(int l, int r) : left(l), right(r) {}
	
	bool operator <(const Segment &s) const {
		return left < s.left;
	}
};

int CoverIt(int m, vector<Segment> &seg, vector<Segment> &res) {
	Segment cover(0, m);
	sort(seg.begin(), seg.end()); // Sort by left edge.

	for (int i = 0; i < seg.size(); i) {
		/**
		* Each time,
		* among the segments that left edge is equal or smaller
		* than the left edge of the `cover',
		* choose the one whose right edge is the biggest.
		*
		* If the left edge of the first segment is not satisfied,
		* no one can satisfied anymore.
		* --> This case fail.
		*/
		if (seg[i].left <= cover.left); else return 0;
		Segment *max = &seg[i];
		for (i++; i < seg.size(); i++) {
			if (seg[i].left <= cover.left); else break;
			if (seg[i].right > max->right) max = &seg[i];
		}

		res.push_back(*max);
		cover.left = max -> right;
		if (cover.left >= cover.right) return res.size();
	}
	/**
	* If going through all the segments, the `cover' is still not covered,
	* this case also fail.
	*/
	return 0;
}

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int m;
		scanf("%d", &m);
		
		int l, r;
		vector<Segment> seg;
		while (scanf("%d%d", &l, &r) != EOF) {
			if (l == 0 && r == 0) break;
			seg.push_back(Segment(l, r));
		}
		
		vector<Segment> res;
		if (CoverIt(m, seg, res) > 0) {
			printf("%d\n", res.size());
			for (int i = 0; i < res.size(); i++) {
				printf("%d %d\n", res[i].left, res[i].right);
			}
		} else {
			printf("0\n");
		}
		
		if (n > 0) printf("\n");
	}
	return 0;
}


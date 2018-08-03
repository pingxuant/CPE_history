
//uva10308
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

map<int, map<int,int>> tree;
map<int, int> list;

void dfs(int root, int value);
bool cmp(const map<int, int>::value_type &a, const map<int, int>::value_type &b);


int main(){

	while(cin){
		string input;
		tree.clear();

		while(getline(cin,input)){
			if(input.length() == 0)break;
			stringstream ss(input);
			int a, b, l;
			ss >> a >> b >> l;
			tree[a][b] = tree[b][a] = l;
		}

		list.clear();		
		dfs(1, 0);
		int root = max_element(list.begin(), list.end(), cmp) -> first;
		list.clear();
		dfs(root, 0);
		cout << max_element(list.begin(), list.end(), cmp) -> second << endl;;

	}

}
void dfs(int root, int value){
	if(list.find(root) != list.end()) 
		return; //Visited
	list[root] = value;

	for(map<int, int>::iterator it = tree[root].begin(); it!=tree[root].end(); ++it){
		dfs(it -> first, value + it -> second);
	}
}

bool cmp(const map<int, int>::value_type &a, const map<int, int>::value_type &b){
        return a.second < b.second;
}





//uva11336
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

map<string,int> nameTable;
map<int,string> nameTablei;
vector<pair<int,int>> roadList[2];
string mapName[2];
int oldmapN;

int getIdbyName(const string& name) {
	map<string,int>::iterator it = nameTable.find(name);
	if(it == nameTable.end())
		return -1;	
	return it -> second;
}

const string& getNamebyId(int id) {
	map<int,string>::iterator it = nameTablei.find(id);
	return it -> second;
}

int putName(const string& name) {
	int key = nameTable.size();
	nameTable.insert(pair<string, int>(name, key));
	nameTablei.insert(pair<int, string>(key, name));	
	return key;
}

void doCal();

int main(){
	string input;
	const int LOADMAP = 1;
	const int LOADSTREET = 2;
	int state = LOADMAP;
	int mapNo = 0;
	while(getline(cin,input)) {
		stringstream iss(input);
		if(state == LOADMAP){
			//Map name
			iss >> mapName[mapNo];
			if(mapNo == 0 && mapName[mapNo] == "END")
				return 0;
			state = LOADSTREET;
			continue;
		}
		
		if(strstr(input.c_str(),"* * *") != NULL){
			state = LOADMAP;
			if(mapNo == 1) {
				doCal();
				mapNo = 0;
				mapName[0].clear();
				mapName[1].clear();
				roadList[0].clear();
				roadList[1].clear();			
				nameTablei.clear();
				nameTable.clear();	
			}
			else {
				mapNo = 1;
				oldmapN = nameTable.size();
			}
			continue;
		}
		string place[2];	
		iss >> place[0] >> place[1];
		int placeId [2];
		for(int i = 0; i < 2; ++i) { //get PlaceID
			placeId[i] = getIdbyName(place[i]);
			if(placeId[i] == -1) {
				placeId[i] = putName(place[i]);
			}	
		}
		
		roadList[mapNo].push_back(pair<int, int>(placeId[0], placeId[1]));
	}

	return 0;
}

void doCal(){
	int martixSize = nameTable.size();
	
	int newMap[martixSize * martixSize];
	for(int i = 0; i < martixSize * martixSize; ++i) {
		newMap[i] = 0;	
	}

	for(int i = 0; i < roadList[1].size(); ++i) {
		int start = roadList[1][i].first, end = roadList[1][i].second ;
		newMap[start * martixSize + end] = newMap[end * martixSize + start] = 1;
	}
		
	for(int n = oldmapN; n < martixSize; ++n)
		for(int i = 0; i < martixSize; ++i)
			for(int j = 0; j < martixSize;++j)
				newMap[i * martixSize + j] |= newMap[i * martixSize + n] && newMap[n * martixSize + j];
	
	for(int i = 0; i < roadList[0].size(); ++i) {
		int start = roadList[0][i].first, end = roadList[0][i].second;
		if(newMap[(roadList[0][i].first) * martixSize + (roadList[0][i].second)] == 0 ) {
			//no route
			cout << "NO: " << mapName[1] << " is not a more detailed version of " << mapName[0] << "\n";
			return;
		}
	}
	
	cout << "YES: " << mapName[1] << " is a more detailed version of " << mapName[0] << "\n";
	return;
}


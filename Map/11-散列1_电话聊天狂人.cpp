#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;


int main() {
    map<string, int>Map;
    int N = 0;
    cin >> N;
    string str;
    for (int i = 0; i < N * 2; i++) {
        cin >> str;
        Map[str]++;
    }
    map<string, int>Visited;
    string MinMember = Map.begin()->first;
    int Maxcnt = 0;
    int Comin = 1;
    for (auto it = Map.begin(); it != Map.end(); it++) {

        if (Maxcnt < it->second) {//如果通话次数更大，更新最大值和成员编号
            Maxcnt = it->second;
            MinMember = it->first;
            Comin = 1;//重置计数
        }
		else if (Maxcnt == it->second && (!Visited[it->first])) {//如果通话次数相同，且未被访问过，计数加一
            Comin++;
        }
        Visited[it->first] = 1;
    }
    if (Comin == 1)
        cout << MinMember << " " << Maxcnt << endl;
    else
        cout << MinMember << " " << Maxcnt << " " << Comin << endl;

    return 0;
}
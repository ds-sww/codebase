#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

struct student_t {
	int id, yw, tot;
	inline bool operator< (const student_t& stu) const {
		if (tot != stu.tot) return tot > stu.tot;
		if (yw != stu.yw) return yw > stu.yw;
		return id < stu.id;
	}
} student[512];

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	register int i, j;
	for(i = 0; i < n; ++ i) {
		int x, y, z;
		cin >> x >> y >> z;
		student[i].id = i + 1;
		student[i].yw = x;
		student[i].tot = x + y + z;
	}
	sort(student, student + n);
	for(i = 0; i < 5; ++ i) {
		cout << student[i].id << " " << student[i].tot << endl;
	}
	return 0;
}


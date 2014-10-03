#include <iostream>
#include <algorithm>
#include <vector>
class stu{
public:
	int num, chn, sum;
	stu(int n, int a, int b, int c){
		num = n;
		chn = a;
		sum = a + b + c;
	}
};
bool lessthan(const stu &a,const stu &b){
	if (a.sum > b.sum)
		return 1;
	else if (a.sum < b.sum)
		return 0;
	else if (a.sum == b.sum){
		if (a.chn>b.chn)
			return 1;
		else if (a.chn < b.chn)
			return 0;
		else
			return a.num<b.num;
	}

}
int main(){
	using namespace std;
	int count;
	int a, b, c;
	cin >> count;
	vector<stu> students;
	for (int i = 1; i <= count; i++){
		cin >> a >> b >> c;
		stu* cp = new stu(i, a, b, c);
		students.push_back(*cp);
	}
	sort(students.begin(), students.end(), lessthan);
	for (int i = 0; i < 5; i++)
		cout << students[i].num << ' ' << students[i].sum << endl;
	return 0;
}
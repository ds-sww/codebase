#include <iostream>
#include <algorithm>

#define MAX 310

using namespace std;

class student
{
	public:
		int id, chinese, total;
		bool operator < (const student &t) const
		{
			if(total != t.total)
				return total > t.total;
			else if(chinese != t.chinese)
				return chinese > t.chinese;
			else
				return id < t.id;
		}
}stu[MAX];

int main() 
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int math, english;
		cin >> stu[i].chinese >> math >> english;
		stu[i].total = stu[i].chinese + math + english;
		stu[i].id = i + 1;
	}
	sort(stu, stu + n);
	for(int i = 0; i < 5; i++)
		cout << stu[i].id << ' ' << stu[i].total << endl;
	return 0;
}
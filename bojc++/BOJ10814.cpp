#include <iostream>
#include <algorithm>

using namespace std;

struct MemberInfo
{
	int index;
	int age;
	string name;
};

int main()
{
	int n;
	MemberInfo members[100000];
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		members[i].index = i;
		cin >> members[i].age >> members[i].name;
	}

	sort(members, members + n, [](const MemberInfo& a, const MemberInfo& b) -> bool { return a.age != b.age ? a.age < b.age : a.index < b.index; });

	for (int i = 0; i < n; i++)
		printf("%d %s\n", members[i].age, members[i].name.c_str());

	return 0;
}
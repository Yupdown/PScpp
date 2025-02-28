#include <iostream>

using std::endl;
using std::cout;
using std::cin;

const char* messages[] =
{
	R"(��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.)",
	R"("����Լ��� ������?")",
	R"("�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.)",
	R"(���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.)",
	R"(���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.")",
	R"("����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����")",
	R"(��� �亯�Ͽ���.)"
};

void function(int n, int i = 0)
{
	for (int j = 0; j < 7; ++j)
	{
		bool terminal = !(i < n);

		if (i && !j)
			continue;
		if (1 << j & 28 && terminal)
			continue;
		if (j == 5 && !terminal)
		{
			function(n, i + 1);
			continue;
		}
		for (int k = 0; k < i; ++k)
			cout << "____";
		cout << messages[j] << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	function(n);
	return 0;
}
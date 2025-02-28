long long sum(int* a, int n)
{
	return --n > 0 ? sum(a, n) + a[n] : a[n];
}
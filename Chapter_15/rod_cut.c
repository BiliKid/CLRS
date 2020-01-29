#include <stdio.h>
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rodcut(int *p, int n)
{
	if (n == 0) {
		return 0;
	}
	int q = INT_MIN;
	for (int i = 1;i <= n; i++) {
		q = MAX(q, p[i] + rodcut(p, n - i));
	}
	return q;
}

int main()
{
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	printf("%d\n", rodcut(p, 8));
	return 0;
}


	



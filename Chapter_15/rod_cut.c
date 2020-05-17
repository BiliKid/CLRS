#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int cache[100] = {0};
int bottomup_cache[100] = {0};

int rodcut_topdown_cached(int *p, int n)
{
	if (n == 0) {
		return 0;
	}

	if (cache[n] > 0) {
		return cache[n];
	}
	int q = INT_MIN;
	for (int i = 1;i <= n; i++) {
		q = MAX(q, p[i] + rodcut_topdown_cached(p, n - i));
	}
	cache[n] = q;
	return q;
}

int rodcut_bottomup_cached(int *p, int n)
{
	int i = 1;
	for (; i <= n; i++) {
		int q = INT_MIN;
		int j = 1;
		for (; j <= i; j++) {
			q = MAX(q, p[j] + bottomup_cache[i - j]);
		}
		bottomup_cache[j - 1] = q;
	}
	return bottomup_cache[n];
}

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


int main(int argc, char *argv[])
{
	int p[11] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
	int n = atoi(argv[1]);
	
	printf("Input n: %d\n", n);
	for (int i = 0; i < n; i++) {
		cache[i] = -1;
	}

	for (int i = 1; i < n; i++) {
		bottomup_cache[i] = -1;
	}

	printf("%d\n", rodcut_topdown_cached(p, n));
	printf("%d\n", rodcut_bottomup_cached(p, n));
	printf("%d\n", rodcut(p, n));
	return 0;
}


	



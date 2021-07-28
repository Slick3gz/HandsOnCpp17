#include <stdio.h>

int main(void)
{
	int i[2] = {42, 43};
	int *p = i;

	if (p) {
		printf("the answer is: %d and %d\n", i[0], p[0]);
		printf("the answer is: %d and %d\n", i[1], p[1]);

		printf("the answer is: %d and %d\n", *(i+0), *(p+0));
		printf("the answer is: %d and %d\n", *(i+1), *(p+1));
	}
}

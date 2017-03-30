#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int **p;















int main()
{
	printf("Determinant 行列式通用计算程序\n\n");

	printf("请输入行列式阶数：");
	scanf("%d", &N);

	int det[N][N];
	int i,j;

	p = det;

	printf("请输入%d个元素值（每个元素以空格隔开）：", N*N);

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &det[i][j]);
		}
	}

	for(i = 0; i < N; i++)
	{
		printf("▏\t");

		for(j = 0; j < N; j++)
		{
			printf("%d\t", det[i][j]);
		}

		printf("▏\n");
	}

	



	return EXIT_SUCCESS;
}

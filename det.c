#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int **det;












int det_get(int x, int y)
{
	return det[x][y];
}

void det_set(int x, int y, int num)
{
	det[x][y] = num;
}


int calc_inverse()
{
	int i,j;
	
	//列标序列组合结果（N × N种）
	int list_size = pow(N, N);
	
	//列标序列组
	int **c_list = (int **)malloc(list_size * sizeof(int *));
	//int **r_list = (int **)malloc(list_size * sizeof(int *));

	for(i = 0; i < list_size; i++)
	{
		//列标行标序列
		c_list[i] = (int *)malloc(N * sizeof(int));
		//r_list[i] = (int *)malloc(N * sizeof(int));

	}
	
	//列标行标数组
	int c[N];
	//int r[N];
	
	//初始化
	for(i = 0; i < N; i++)
	{
		c[i] = 0+1; 
		//r[i] = i+1;
	}
	


	for(i = 0; i < list_size; i++)
	{
		for(j = 0; j < N; j++)
		{
			c_list[i][j] = c[j];
			//r_list[i][j] = r[j]; 
		}
	}




	//销毁列标数组
	for(i = 0; i < list_size; i++)
	{
		free(list[i]);
	}

	free(list);

}

int calc_det()
{
	int result;
	
	if(N == 2)
	{
		result = det[0][0] * det[1][1] - det[0][1] * det[1][0];
	}
	else if(N == 3)
	{
		result = det[0][0] * det[1][1] * det[2][2] + det[0][1] * det[1][2] * det[2][0] + det[0][2] * det[1][0] * det[2][1] - det[2][0] * det[1][1] * det[0][2] - det[1][0] * det[0][1] * det[2][2] - det[0][0] * det[2][1] * det[1][2];
	}

	return result;
}


void init_det()
{
	int i;

	det = (int **)malloc(N * sizeof(int *));

	for(i = 0; i < N; i++)
	{
		det[i] = (int *)malloc(N * sizeof(int));
	}
}

void free_det()
{
	int i;

	for(i = 0; i < N; i++)
	{
		free(det[i]);
	}

	free(det);
}

int main()
{
	printf("Determinant 行列式通用计算程序\n\n");

	do
	{
		printf("请输入行列式阶数：");
		scanf("%d", &N);
		if(N < 2)
		{
			printf("请输入正确的阶数！\n\n");
		}
	}
	while(N < 2);


	int i,j;

	init_det();

	printf("请输入%d个元素值（每个元素以空格隔开）：", N*N);

	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%d", &det[i][j]);
		}
	}

	printf("图例如下：\n");
	for(i = 0; i < N; i++)
	{
		printf("▏\t");

		for(j = 0; j < N; j++)
		{
			printf("%d\t", det[i][j]);
		}

		printf("▏\n");
	}

	printf("计算结果为：%d\n", calc_det());

	

	free_det();

	return EXIT_SUCCESS;
}

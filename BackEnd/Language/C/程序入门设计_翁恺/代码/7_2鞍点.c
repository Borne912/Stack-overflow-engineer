#include <stdio.h>

int main(int argc, char const *argv[])
{
	/**
	 * 题目内容：
	 * 给定一个n*n矩阵A。
	 * 矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。
	 * 一个矩阵A也可能没有鞍点。
	 * 你的任务是找出A的鞍点。
	 *
	 * 输入格式：
	 * 输入的第1行是一个正整数n, （1<=n<=100），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
	 *
	 * 输出格式：
	 * 对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
	 * 如果找不到，就输出
	 * 
	 * NO
	 * 
	 * 题目所给的数据保证了不会出现多个鞍点。
	 */
	
	int dim = 0;

	// 读入矩阵的维度
	scanf("%d", &dim);

	int matrix[dim][dim];

	int element = 0;

	// 读人矩阵各元素值
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		{
			scanf("%d", &element);
			matrix[i][j] = element;
		}
	}

	// {
	// 	for (int i = 0; i < dim; ++i)
	// 	{
	// 		for (int j = 0; j < dim; ++j)
	// 		{
	// 			printf("%d", matrix[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// }
	int rowmaxindex = 0; // 一行中最大值所在列
	int colminindex = 0; // 一列中最小值所在行
	int ishassaddle = 0;
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j) // 搜索一行中的最大值
		{
			if(matrix[i][j] > matrix[i][rowmaxindex])
			{
				rowmaxindex = j;
			}
		}
		for (int k = 0; k < dim; ++k) // 搜索一行的最大元素所在列的最小值
		{
			if (matrix[k][rowmaxindex] < matrix[colminindex][rowmaxindex])
			{
				colminindex = k;
			}
		}

		if (colminindex == i) // 题目说的有且仅有一个鞍点，找到就跳出循环
		{
			ishassaddle = 1;
			break;
		}
	}

	if (ishassaddle)
	{
		printf("%d %d\n", colminindex, rowmaxindex);
	}
	else
	{
		printf("No");
	}


	return 0;
}
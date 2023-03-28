#include <stdio.h>

int main(int argc, char const *argv[])
{
	/**
	 * 题目内容：
	 * 一个多项式可以表达为x的各次幂与系数乘积的和，比如：
	 * 2x6+3x5+12x3+6x+20
	 * 现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
	 * 程序要处理的幂最大为100。
	 *
	 * 输入格式：
	 * 总共要输入两个多项式，每个多项式的输入格式如下：
	 * 每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。
	 * 第一行一定是最高幂，最后一行一定是0次幂。
	 * 注意第一行和最后一行之间不一定按照幂次降低顺序排列；
	 * 如果某个幂次的系数为0，就不出现在输入数据中了；
	 * 0次幂的系数为0时还是会出现在输入数据中。
	 *
	 * 输出格式：
	 * 从最高幂开始依次降到0幂，如：2x6+3x5+12x3-6x+20
	 * 注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。
	 */
	
	const int length = 100;

	int polynomial[length] = {0};

	int power = 0, factor = 0;
	int count = 0;	//	统计当前输入的情况,count = 0,输入第一个多项式;
	// int maxpower = 0;
	// scanf("%d %d", &power, &factor);
	// maxpower = power;
	while( count < 2 )
	{
		scanf("%d %d", &power, &factor);
		polynomial[power] += factor;
		if ( power == 0 )
		{
			count++;
		}
	}

	for (int i = length; i > 0; i--)
	{
		if ( polynomial[i - 1] != 0 )
		{

			if ( i - 2 == 0 ) // 循环的倒数第二轮 对应 x 一次幂项
			{
				printf("%dx", polynomial[i - 1]);
				printf("+");
			}
			else if (i - 1 == 0) // 循环的最后一轮 对应 x 0次幂项，即：常数项
			{
				printf("%d", polynomial[i - 1]);
			}
			else
			{
				printf("%dx%d", polynomial[i - 1], i - 1);
			
				printf("+");
			}

		}
	}


	return 0;
}
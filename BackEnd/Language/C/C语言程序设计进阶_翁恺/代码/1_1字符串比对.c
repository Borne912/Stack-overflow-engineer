#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	/**
	 * 题目内容：
	 * 题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，
	 * 而且第一个字符串的长度小于第二个字符串的。你的程序要找出第一个字符串在第二个字符串中出现的位置，
	 * 输出这些位置，如果找不到，则输出-1。
	 *
	 * 注意，第一个字符的位置是0。
	 * 注意，第一个字符串在第二个字符串中的位置可能不止一处。
	 * 注意，字符串中可能含有空格。
	 * 注意，两个字符串的长度一定大于0。
	 *
	 * 输入格式：
	 * 两个字符串，一行一个。
	 *
	 * 输出格式：
	 * 第一个字符串在第二个字符串中出现的位置，按照从小到到的顺序排列，每个数字后面有一个空格。
	 * 如果在第二个字符串中找不到第一个字符串，则输出-1。
	 *
	 * 输入样例：
	 * abba
	 * ababbba abbabbabbabbaacc
	 *
	 * 输出样例：
	 * 8 11 14 17
	 */
	
	const int maxstrlens = 10000;
	char str1[maxstrlens] = "";
	char str2[maxstrlens] = "";
	int str1appearinstr2loc[maxstrlens] = {0};

	/**
	 * 1.strlen(str1) < strlen(str2)
	 * 2.字符串中可能含有空格，所以不能用scanf去读
	 */
	// scanf("%s", str1);	//	读入第一个字符串
	// scanf("%s", str2);	// 读入第二个字符串
	 
	fgets(str1, maxstrlens, stdin);	//	读入第一个字符串
	fgets(str2, maxstrlens, stdin);	// 读入第二个字符串

	// printf("%s\n", str2);

	int str1lens = strlen(str1) - 1; // 减去 \n 的长度
	// printf("%d\n", str1lens);
	// printf("%lu\n", strlen(str2));

	char *q = str2;
	int idx = 0; // 记录字符串移动的位置
	int duplicationnumb = 0;	// 统计重复位置的个数
	while(*q!='\0')
	{
		char *p = str1, *r  = q;
		// printf("%c\n", *r);
		int isloc = 1;
		for (int i = 0; i < str1lens; ++i)
		{
			if(*p == *r)
			{
				// printf("idx:%d\n", idx);
				// printf("p:%c r:%c\n", *p, *r);
				p++;
				r++;
			}
			else
			{
				// printf("idx:%d\n", idx);
				isloc = 0;
				break;
			}
		}
		// printf("%d:%d\n",idx, isloc);
		if(isloc)
		{
			str1appearinstr2loc[duplicationnumb] = idx;
			duplicationnumb ++;
			// printf("%d ", idx);
		}
		q++;
		idx++;
	}

	if(duplicationnumb == 0) // 在第二个字符串中找不到第一个字符串
	{
		printf("%d", -1);
	}
	else
	{
		for (int i = 0; i < duplicationnumb; ++i)
		{
			if(i + 1 == duplicationnumb)	// 最后一个输出不带空格
			{
				printf("%d", str1appearinstr2loc[i]);
			}
			else
			{
				printf("%d ", str1appearinstr2loc[i]);
			}
		}
	}


	return 0;
}
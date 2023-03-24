#include <stdio.h>

int main()
{

    /**
     * 题目内容：
     * 我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。
     * 现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
     *
     * 输入格式：
     * 两个整数，第一个表示n，第二个表示m。
     *
     * 输出格式：
     * 一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。
     *
     */

    int n = 0, m = 0;
    scanf("%d %d", &n, &m);

    int sum = 0;
    int isprime = 1;
    int count = 0;
    int value = 2;
    while (count <= m)
    {
        for (int j = 2; j < value; j++)
        {
            if (value % j == 0)
            {
                isprime = 0;
                break;
            }
        }
        if (isprime)
        {
            count++;
            if (count >= n && count <= m)
            {
                sum = sum + value;
            }
        }
        isprime = 1;
        value++;
    }

    printf("%d", sum);

    return 0;
}
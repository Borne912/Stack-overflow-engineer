#include <stdio.h>

int main()
{

    /**
     * 题目内容：
     * 你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。
     * 如输入1234，则输出：
     * yi er san si
     * 注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
     * fu er san si yi
     *
     * 输入格式：
     * 一个整数，范围是[-100000,100000]。
     *
     * 输出格式：
     * 表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。
     */

    int n = -123456789;
    // scanf("%d", n);

    // 判断是否为负
    int isnegative = 0;
    if (n < 0)
    {
        isnegative = 1;
        n = -n;
    }

    int digits = 1;
    int t = n;
    int m = 1;
    while (t > 9)
    {
        t = t / 10;
        m = m * 10;
        digits++;
    }

    int digit = 0; // 存储每一位

    // 先输出符号，如果为负的话
    if (isnegative)
    {
        printf("fu ");
    }

    while (m != 0)
    {
        digit = n / m;
        n = n % m;
        m = m / 10;
        switch (digit)
        {
        case 0:
            printf("ling");
            break;
        case 1:
            printf("yi");
            break;
        case 2:
            printf("er");
            break;
        case 3:
            printf("san");
            break;
        case 4:
            printf("si");
            break;
        case 5:
            printf("wu");
            break;
        case 6:
            printf("liu");
            break;
        case 7:
            printf("qi");
            break;
        case 8:
            printf("ba");
            break;
        case 9:
            printf("jiu");
            break;
        default:
            printf("不是0~9之间的数?");
            break;
        }
        if (m > 0)
        {
            printf(" ");
        }
    }

    return 0;
}
#include <stdio.h>

int main()
{

    /**
     * 输入格式：
     * 一系列正整数，整数的范围是（0,100000）。如果输入-1则表示输入结束。
     * 输出格式：
     * 两个整数，第一个整数表示读入数据中的奇数的个数，第二个整数表示读入数据中的偶数的个数。两个整数之间以空格分隔。
     */

    int n = 0;

    scanf("%d", &n);

    int odd = 0, even = 0;
    while (n != -1)
    {
        if (n % 2 == 0) // 偶数
        {
            even++;
        }
        else // 奇数
        {
            odd++;
        }
        scanf("%d", &n);
    }

    printf("%d %d", odd, even);

    return 0;
}
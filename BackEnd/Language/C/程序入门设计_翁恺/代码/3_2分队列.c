#include <stdio.h>

int main()
{

    // 读入人数n
    int n = 0;
    scanf("%d", &n);

    // 按照1,3,5...进行输出
    for (int i = 1; i <= n - 2; i += 2)
    {
        printf("%d ", i);
    }
    // 判断n的奇偶性，解决最后一个输出后面没空格的情况
    if (n % 2 == 0)
    { // 偶数
        printf("%d", n - 1);
    }
    else
    {
        printf("%d", n);
    }
    return 0;
}
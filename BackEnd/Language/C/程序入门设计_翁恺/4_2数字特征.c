#include <stdio.h>
#include <math.h>

int main()
{

    /**
     * 题目内容：
     * 对数字求特征值是常用的编码算法，奇偶特征是一种简单的特征值。
     * 对于一个整数，从个位开始对每一位数字编号，个位是1号，十位是2号，以此类推。
     * 这个整数在第n位上的数字记作x，如果x和n的奇偶性相同，则记下一个1，否则记下一个0。
     * 按照整数的顺序把对应位的表示奇偶性的0和1都记录下来，就形成了一个二进制数字。
     * 比如，对于342315，这个二进制数字就是001101。
     *你的程序要读入一个非负整数，整数的范围是[0,1000000]，然后按照上述算法计算出表示奇偶性的那个二进制数字，输出它对应的十进制值。

     * 输入格式：
     * 一个非负整数，整数的范围是[0,1000000]。
     *
     * 输出格式：
     *一个整数，表示计算结果。

     */

    int n = 0;

    scanf("%d", &n);

    int count = 1; // 统计位数
    int value = 0; // 临时存储某一位的值
    int binary = 0;
    while (n != 0)
    {
        value = n % 10;                                                               // 取n的末位
        if ((value % 2 == 0 && count % 2 == 0) || (value % 2 != 0 && count % 2 != 0)) // 奇偶性相同
        {
            binary = binary * 10 + 1;
        }
        else
        {
            binary = binary * 10 + 0;
        }
        n = n / 10; //  丢掉n的末位
        count++;
    }
    // printf("%d\n", binary);
    // printf("%d\n", count);
    // 2进制转10进制
    int decimal = 0;
    count--; // 计数器矫正位数
    while (binary != 0)
    {
        count--;
        value = binary % 10;
        binary = binary / 10;
        decimal = decimal + value * pow(2, count);
    }

    printf("%d", decimal);

    return 0;
}
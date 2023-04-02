#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	/**
	 * 题目内容：
	 * NMEA-0183协议是为了在不同的GPS（全球定位系统）导航设备中建立统一的BTCM（海事无线电技术委员会）标准，
	 * 由美国国家海洋电子协会（NMEA-The National Marine Electronics Associa-tion）制定的一套通讯协议。
	 * GPS接收机根据NMEA-0183协议的标准规范，将位置、速度等信息通过串口传送到PC机、PDA等设备。
	 * 
	 * NMEA-0183协议是GPS接收机应当遵守的标准协议，也是目前GPS接收机上使用最广泛的协议，大多数常见的GPS接收机、GPS数据处理软件、导航软件都遵守或者至少兼容这个协议。
	 * 
	 * NMEA-0183协议定义的语句非常多，但是常用的或者说兼容性最广的语句只有$GPGGA、$GPGSA、$GPGSV、$GPRMC、$GPVTG、$GPGLL等。
	 *
	 * 其中$GPRMC语句的格式如下：
	 * $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
	 *
	 * 这里整条语句是一个文本行，行中以逗号“,”隔开各个字段，每个字段的大小（长度）不一，这里的示例只是一种可能，并不能认为字段的大小就如上述例句一样。
	 * 
	 * 字段0：$GPRMC，语句ID，表明该语句为Recommended Minimum Specific GPS/TRANSIT Data（RMC）推荐最小定位信息
	 * 字段1：UTC时间，hhmmss.sss格式
	 * 字段2：状态，A=定位，V=未定位
	 * 字段3：纬度ddmm.mmmm，度分格式（前导位数不足则补0）
	 * 字段4：纬度N（北纬）或S（南纬）
	 * 字段5：经度dddmm.mmmm，度分格式（前导位数不足则补0）
	 * 字段6：经度E（东经）或W（西经）
	 * 字段7：速度，节，Knots
	 * 字段8：方位角，度
	 * 字段9：UTC日期，DDMMYY格式
	 * 字段10：磁偏角，（000 - 180）度（前导位数不足则补0）
	 * 字段11：磁偏角方向，E=东W=西
	 * 字段12：校验值
	 *
	 * 这里，“*”为校验和识别符，其后面的两位数为校验和，代表了“$”和“*”之间所有字符（不包括这两个字符）的异或值的十六进制值。上面这条例句的校验和是十六进制的50，也就是十进制的80。
	 *
	 * 提示：^运算符的作用是异或。将$和*之间所有的字符做^运算(第一个字符和第二个字符异或，结果再和第三个字符异或，依此类推)之后的值对65536取余后的结果，
	 * 应该和*后面的两个十六进制数字的值相等，否则的话说明这条语句在传输中发生了错误。注意这个十六进制值中是会出现A-F的大写字母的。
	 *
	 * 现在，你的程序要读入一系列GPS输出，其中包含$GPRMC，也包含其他语句。在数据的最后，有一行单独的
	 *     END
	 * 表示数据的结束。
	 *
	 * 你的程序要从中找出$GPRMC语句，计算校验和，找出其中校验正确，并且字段2表示已定位的语句，从中计算出时间，换算成北京时间。
	 * 一次数据中会包含多条$GPRMC语句，以最后一条语句得到的北京时间作为结果输出。你的程序一定会读到一条有效的$GPRMC语句。
	 *
	 * 输入格式:
	 * 多条GPS语句，每条均以回车换行结束。最后一行是END三个大写字母。
	 *
	 * 输出格式：
	 * 6位数时间，表达为：
	 * 		hh:mm:ss
	 * 其中，hh是两位数的小时，不足两位时前面补0；mm是两位数的分钟，不足两位时前面补0；ss是两位数的秒，不足两位时前面补0。
	 *
	 * 输入样例：
	 * $GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
	 * END
	 *
	 * 输出样例：
	 * 10:48:13
	 */
	/**
	 * 题目分析：
	 * 
	 * $GPRMC, 024813.640, A, 3158.4608, N, 11848.3737, E, 10.05, 324.27, 150706, , ,A*50
	 * 
	 * 1.找出$GPRMC语句； ---> 字段0
	 * 2.计算校验和，找出其中校验正确； ---> 字段12 ($和*之间所有的字符做^运算)(第一个字符和第二个字符异或，结果再和第三个字符异或，依此类推)
	 * 3.并且字段2表示已定位的语句； ---> 字段2 A=定位，V=未定位
	 * 4.计算出时间，换算成北京时间； ---> 字段1 (hhmmss.sss) 北京时间：(hh + 8):mm:ss 
	 * 注意：一次数据中会包含多条$GPRMC语句，以最后一条语句得到的北京时间作为结果输出
	 *
	 * 统计需要取出的字段：字段0, 字段1, 字段2, 字段12
	 */

	const int maxlens = 151;
	const char endflag[] = "END"; 
	const char field0[] = "$GPRMC";
	const char * orientation = "A";
	int time [3] = {0};	//hh,mm,ss
	int commaloc = 0; // 记录逗号的位置
	int asteriskloc = 0;	// 记录星号的位置
	int verifyres = 0;	// 计算的校验结果
	int verifyval = 0;	// 字符串给出的校验值

	char *p = NULL; // 一个临时指针

	char str[maxlens];

	scanf("%150s", str);
	while(strcmp(str,endflag) != 0) // 没有出现终止符 END
	{
		if(strncmp(str, field0, strlen(field0)) == 0)	// 找出$GPRMC语句
		{
			// 计算校验和
			asteriskloc = strlen(str) - strlen(strchr(str, '*'));	// 可以作为一个套路，如何求一个字符的位置
			verifyres = str[1];
			for (int i = 2; i < asteriskloc; ++i)	// $和*之间所有的字符做^运算
			{
				verifyres = verifyres ^ str[i];
			}
			verifyres = verifyres % 65536;	

			// 将字符串类型的校验结果转换成 int 10 进制类型
			p = strchr(str, '*') + 1; 
			int power = strlen(p);
			while(*p!='\0')
			{
				int t = 0;
				power--; 
				switch(*p)
				{
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					t = *p - '0';
					break;
					case 'A':
					t = 10;
					break;
					case 'B':
					t = 11;
					break;
					case 'C':
					t = 12;
					break;
					case 'D':
					t = 13;
					break;
					case 'E':
					t = 14;
					break;
					case 'F':
					t = 15;
					break;
					default:
					printf("%s", "校验码有误！");
				}
				verifyval = verifyval + t * pow(16, power);
				p++;
			}

			if (verifyres ==  verifyval)		// 和末尾校验码比较判断是否出错
			{
				// 判断字段2是否已定位
				p = strchr(str, ',') + 1;	// 第一个逗号
				p = strchr(p, ',') + 1;		// 字段2
				
				if(strncmp(p,orientation,strlen(orientation)) == 0)	//定位判断
				{
					// 计算出时间，换算成北京时间 hhmmss.sss --> (hh + 8):mm:ss 
					p = strchr(str, ',') + 1;	// 指向字段1
					int count = 0;
					while( *p != '.')
					{
						if (count == 0)
						{
							time[count] = ((*p - '0') * 10 + (*(p+1) - '0') + 8) % 24;
						}
						else
						{
							time[count] = (*p - '0') * 10 + (*(p+1) - '0');
						}
						count++;
						p = p + 2;				// 每次处理时/分/秒
					}
				}
			}
		}
		scanf("%150s", str);
	}

	// 输出最后一条语句得到的北京时间
	int timearrlens = sizeof(time)/sizeof(time[0]);
	for (int i = 0; i < timearrlens; ++i)
	{
		if (i + 1 == timearrlens)
		{
			printf("%d", time[i]);
		}
		else
		{
			printf("%d:", time[i]);
		}
	}

	return 0;
}
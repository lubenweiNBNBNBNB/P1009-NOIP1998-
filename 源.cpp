#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void my_reverse(char bns[])
{
	int n = strlen(bns) - 1;
	int i;
	char ans[100] = { 0 };
	for (i = 0; i < n + 1; i++)
	{
		ans[i] = bns[i];
	}
	int lef = 0;
	int rit = n;
	char tmp;
	while (lef <= rit)
	{
		tmp = ans[lef];
		ans[lef] = ans[rit];
		ans[rit] = tmp;
		lef++;
		rit--;
	}
	printf("%s", ans);
}
int main()
{
	int n;
	scanf("%d", &n);
	int ii,jj;
	char ans[100] = { 0 };
	for (ii = 1; ii <= n; ii++) //每个阶乘
	{
		if (n == 1)
		{
			printf("1");
			break;
		}
		char a[100] = { 0 };	//两个乘数 a为总结果，b为下一个乘数
		char b[2] = { 0 };
		a[0] = '1';
		for (jj = 2; jj <= ii; jj++)
		{
			if (jj < 10)						//安排b
				b[0] = (char)(jj - 48);
			else
			{
				b[0] = (char)(jj / 10 - 48);
				b[1] = (char)(jj % 10 - 48);
			}
		
			//////////////高精
						
			int aw;
			int bw;
			int alen = strlen(a);
			int blen = strlen(b);
			int i, j = 0;
			int re;
			int ris = 0;
			char sum[100] = { 0 };
			int i1;
			int A1, B1;
			int alen1;
			int blen1;
			int sum0 = 0;
			int mid1 = 0;
			char ans[100] = { 0 };
			for (bw = blen - 1; bw >= 0; bw--)
			{				
				char sum1[100] = { 0 };
				i = 0 + j;
				for (aw = alen - 1; aw >= 0; aw--, i++)
				{
					re = ((int)a[aw] - 48) * ((int)b[bw] - 48) + ris;
					ris = 0;							
					if (re > 9)
					{
						ris = re / 10;				
						re -= ris * 10;					
						sum1[i] = (char)(re + 48);		
					}
					else
					{
						sum1[i] = (char)(re + 48);
					}
					if (aw == 0 && ris > 0)
					{
						sum1[i + 1] = (char)(ris + 48);
						ris = 0;
					}
				}
				//以上为一位乘
				//下面高精加一下

				alen1 = strlen(sum1);
				blen1 = strlen(sum);				
				for (i1 = j; i1 < 100; i1++)
				{
					sum0 = 0;
					A1 = (int)(sum1[i1] - 48);
					B1 = (int)(sum[i1] - 48);
					if (sum1[i1] == '\0')
					{
						sum0 = B1 + mid1;
					}
					else if (sum[i1] == '\0')
					{
						sum0 = A1 + mid1;
					}
					else
						sum0 = A1 + B1 + mid1;			
					mid1 = 0;				
					if (sum0 > 9)
					{
						mid1 = 1;
						sum0 -= 10;
						sum[i1] = (char)(sum0 + 48);
					}
					else
					{
						sum[i1] = (char)(sum0 + 48);
					}
					if (i1 >= alen1 - 1 && i1 >= blen1 - 1)
					{
						if (sum1[i1 + 1] != '\0')								
						{
							sum[i1 + 1] = (char)((int)sum1[i1 + 1] + mid1);
							if (sum[i1 + 1] > '9')							
							{
								sum[i1 + 2] = (char)(((int)sum[i1 + 1] - 48) / 10 + 48);
								sum[i1 + 1] = (char)(((int)sum[i1 + 1] - 48) % 10 + 48);		

								break;
							}
						}
						else if (sum1[i1 + 1] == '\0' && mid1 == 1)
						{
							sum[i1 + 1] = '1';
						}
						if (sum1[i1 + 2] != '\0')						
						{
							sum[i1 + 2] = sum1[i1 + 2];
						}
						break;
					}

				}
				j++;
				//结果汇总一下，sum加到ans里去
				alen1 = strlen(sum);
				blen1 = strlen(ans);
				for (i1 = j; i1 < 100; i1++)
				{
					sum0 = 0;
					A1 = (int)(sum[i1] - 48);
					B1 = (int)(ans[i1] - 48);
					if (sum[i1] == '\0')
					{
						sum0 = B1 + mid1;
					}
					else if (ans[i1] == '\0')
					{
						sum0 = A1 + mid1;
					}
					else
						sum0 = A1 + B1 + mid1;
					mid1 = 0;
					if (sum0 > 9)
					{
						mid1 = 1;
						sum0 -= 10;
						ans[i1] = (char)(sum0 + 48);
					}
					else
					{
						ans[i1] = (char)(sum0 + 48);
					}
					if (i1 >= alen1 - 1 && i1 >= blen1 - 1)
					{
						if (sum[i1 + 1] != '\0')
						{
							ans[i1 + 1] = (char)((int)sum[i1 + 1] + mid1);
							if (ans[i1 + 1] > '9')
							{
								ans[i1 + 2] = (char)(((int)ans[i1 + 1] - 48) / 10 + 48);
								ans[i1 + 1] = (char)(((int)ans[i1 + 1] - 48) % 10 + 48);

								break;
							}
						}
						else if (sum[i1 + 1] == '\0' && mid1 == 1)
						{
							ans[i1 + 1] = '1';
						}
						if (sum[i1 + 2] != '\0')
						{
							ans[i1 + 2] = sum1[i1 + 2];
						}
						break;
					}
			
				}

			}

		}

	}
	if(n!=1)
	my_reverse(ans);
	return 0;
}
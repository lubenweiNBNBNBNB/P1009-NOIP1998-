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
	int ii;
	char ans[100] = { 0 };
	ans[0] = '1';				//1!+2!+3!+...
	if (n == 1)
	{
		printf("1");
	}
	char a[100] = { 0 };
	a[0] = '1';
	for (ii = 2; ii <= n; ii++) //ÿ���׳�			1+1*2+1*2*3+1*2*3*4 ��������ÿ��ֱ�ӳ���һ�εĽ��
	{							//��֮ÿ�ν׳������Ϊsum��sum�ӵ�ans�С�
		//char a[100] = { 0 };	//�������� aΪ�ܽ�����ܽ����������bΪ��һ������
		char b[3] = { 0 };		
		
			if (ii < 10)						//����b : 2 -> 3 -> 4 -> 5
				b[0] = (char)(ii + 48);
			else
			{
				b[0] = (char)(ii / 10 + 48);
				b[1] = (char)(ii % 10 + 48);
			}
		
			//////////////�߾��˷� �ӷ�///////////////////////////////////////////////////////////////////////////////////////////////////////
						
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
			char sum1[100] = { 0 };
			for (bw = blen - 1; bw >= 0; bw--)
			{
				//�����ʼ��
				memset(sum1, 0, 1);
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
				//����Ϊ[һλ��]
				//ÿ�γ˻��Ľ��sum1
				//����߾��ӵ�sum��

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
			}
			
			strcpy(a, sum);//�ø�a����һ�°�������
			int left = 0;
			int right = strlen(a)-1;
			char change;
			while(left <= right)
			{
				change = a[right];
				a[right] = a[left];
				a[left] = change;
				right--;
				left++;
			}
				//�������һ�£�ÿ�εĽ׳˽��sum�ӵ�ans��ȥ/////////////////////////////////////
				alen1 = strlen(sum);
				blen1 = strlen(ans);
				int max;
				if (alen1 > blen1) max = alen1;
				else max = blen1;
				for (i = 0; i < max; i++)
				{
					if (sum[i] == '\0')				//ii==34�ӵ�ʱ��������ˣ���һ����λ9�����ǵ����
					{
						ans[i] = (char)(ans[i] + ris);  ris = 0;
						if (ans[i] > '9')
						{
							ans[i] = '0';
							ris = 1;
						}
					}
					else if (ans[i] == '\0')
					{
						ans[i] = (char)(sum[i] + ris); ris = 0;
						if (ans[i] > '9')
						{
							ans[i] = '0';
							ris = 1;
						}
					}
					else
						//����mid1��ÿλ֮�Ͱ� , ris����λ
					{
						mid1 = sum[i] - 48 + ans[i] - 48 + ris;
						ris = 0;
						if (mid1 > 9)
						{
							ris = 1;
							mid1 -= 10;
							ans[i] = (char)(mid1 + 48);
							//���ans���ˣ���λŪ��1
							if (i == blen1 - 1)				//���￼���ˣ���
							{
								ans[i + 1] = '1';
								ris = 0;
							}
						}
						else
						{
							ans[i] = (char)(mid1 + 48);
						}
					}
					if (i == max - 1 && ris == 1)
					{
						ans[i + 1] = '1';
					}
				}
	}
	if(n!=1)
	my_reverse(ans);
	return 0;
}
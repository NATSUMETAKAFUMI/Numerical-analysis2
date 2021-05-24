#include<stdio.h>

int main() 
{
	int ecnt1, ecnt2, count1, count2, judg1, judg2, ccnt;
	char str1[64], str2[64], distr1[64] = {}, distr2[64] = {}, distr[64][64] = {},  match[64] = {};

	ccnt = 0;

	printf("一つ目の文字を入力してください\n");
	scanf("%s", &str1);
	printf("二つ目の文字を入力してください\n");
	scanf("%s", &str2);

	ecnt1 = ecnt2 = 0;

	for (count1 = 0; count1 < 64; count1++) 
	{	
		if(str1[ecnt1] == str2[ecnt2])
		{
			match[count1] = 'o';
			distr1[count1] = str1[ecnt1];
			distr2[count1] = str2[ecnt2];
		}

		else if(str1[ecnt1] != str2[ecnt2])
		{
			match[count1] == 'x';
 			distr1[count1] = str1[ecnt1];
			distr2[count1] = str2[ecnt2];
		}

		ecnt1++;
		ecnt2++;

		if(str1[ecnt1] == '\0' &&  str2[ecnt2] == '\0')
		{
			count1 = 64;
		}
	}

	for(count1 = 0; count1 < 64; count1++) 
	{
		distr[ccnt][count1] = distr1[count1];
		distr[ccnt + 1][count1] = distr2[count1];
		distr[ccnt + 2][count1] = match[count1];

		distr1[count1] = '\0';
		distr2[count1] = '\0';
		match[count1] = '\0';
	}

	ccnt = ccnt + 3;
	
	ecnt1 = ecnt2 = 0;

	for(count1 = 0; count1 < 64; count1++)
	{
		if(str1[ecnt1] == str2[ecnt2])
		{
			match[count1] = 'o';
			distr1[count1] = str1[ecnt1];
			distr2[count1] = str2[ecnt2];

			ecnt1++;
			ecnt2++;
		}

		else if(str1[ecnt1] != str2[ecnt2])
		{
			match[count1] = 'x';

			judg1 = judg2 = 1;

			while(1) 
			{
				if(str1[ecnt1 + judg1] == str2[ecnt2])
				{
					break;
				}
				
				else if(str1[ecnt1 + judg1] == '\0')
				{
					judg1 = 64;
					break;
				}

				else 
				{
					judg1++;
				}
			}

			while(1) 
			{
				if(str1[ecnt1] == str2[ecnt2 + judg2])
				{
					break;
				}

				else if(str2[ecnt2 + judg2] == '\0')
				{
					judg2 = 64;
					break;
				}

				else 
				{
					judg2++;
				}
			}

			if(judg1 < judg2)
			{
				distr1[count1] = str1[ecnt1];
				distr2[count1] = '_';

				if(judg1 > 1)
				{
					for(count2 = 1; count2 < judg1; count2++)
					{
						count1++;

					distr1[count1] = str1[ecnt1 + count2];
					distr2[count1] = '_';
					match[count1] = 'x';
					}
				}

				ecnt1 += judg1;
			}

			else if(judg1 > judg2)
			{
				distr1[count1] = '_';
				distr2[count1] = str2[ecnt2];

				if(judg2 > 1)
				{
					for(count2 = 1; count2 < judg2; count2++)
					{
						count1++;

						distr1[count1] = '_';
						distr2[count1] = str2[ecnt2 + count2];
						match[count1] = 'x';
					}
				}

				ecnt2 += judg2;
			}

			else if(judg1 == judg2)
			{
				distr1[count1] = str1[ecnt1];
				distr2[count1] = str2[ecnt2];

				ecnt1++;
				ecnt2++;
			}
		}

		if(str1[ecnt1] == '\0' && str2[ecnt2] == '\0')
		{
			count1 = 64;
		}
	}

	
	for(count1 = 0; count1 < 64; count1++)
	{
		distr[ccnt][count1] = distr1[count1];
		distr[ccnt + 1][count1] = distr2[count1];
		distr[ccnt + 2][count1] = match[count1];

		distr1[count1] = '\0';
		distr2[count1] = '\0';
		match[count1] = '\0';
	}

	ccnt = ccnt + 3;

	int ocnt, oMax, xcnt, xMin, cNum;

	cNum = 0;
	oMax = 0;
	xMin = 64;

	for(count1 = 0; count1 < 64; count1++)
	{
		ocnt = 0;
		xcnt = 0;

		for(count2 = 0; count2 < 64; count2++)
		{
			if(distr[count1 * 3 + 2][count2] == 'o')
			{
				ocnt++;
			}

			else if(distr[count1 * 3 + 2][count2] == 'x')
			{
				xcnt++;
			}

			if(distr[count1 * 3 + 2][count2] == '\0')
			{
				count2 = 64;
			}
		}

		if(ocnt > oMax)
		{
			oMax = ocnt;
			cNum = count1 * 3;
		}

		else if(ocnt == oMax)
		{
			if(xcnt < xMin)
			{
				xMin = xcnt;
				cNum = count1 * 3;
			}
		}

		if(distr[count1 * 3 + 3][0] == '\0')
		{
			count1 = 64;
		}
	}

	printf("--------------------result--------------------\n");

	char disstr1[128] = {}, disstr2[128] = {}, result[128] = {};

	for(count1 = 0; count1 < 64; count1++)
	{
		disstr1[count1 * 2] = distr[cNum][count1];
		disstr2[count1 * 2] = distr[cNum + 1][count1];
		result[count1 * 2] = distr[cNum + 2][count1];

		disstr1[count1 * 2 + 1] = ' ';
		disstr2[count1 * 2 + 1] = ' ';
		result[count1 * 2 + 1] = ' ';
	}

	printf("%s\n", disstr1);
	printf("%s\n", disstr2);
 	printf("%s\n", result);

	return 0;
}

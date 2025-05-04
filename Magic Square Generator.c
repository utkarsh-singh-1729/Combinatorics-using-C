#include <stdio.h>
#include <stdlib.h>

//Scale of matrix
#define MAX 20
#define MIN 3

int magic[MAX][MAX];

//Show magic matrix
void ShowMagic(int n)
{
	int i, j;
	//show data
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-1; j++)
			printf("%d ", magic[i][j]);
		printf("%d\n", magic[i][j]);
	}

}

//Initialize the magic
void InitMagic(int n)
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			magic[i][j] = 0;	//initialize every position with 0
	}
}

//Odd-number scale method of magic square
void OddMagic(int offseti, int offsetj, int min, int n)
{
	int tmpi, tmpj;		//save last number's position
	int i;

	tmpi = 0; tmpj = n / 2;
	magic[tmpi + offseti][tmpj + offsetj] = min;	//the middle of first line is min
	for(i=2; i<=n*n; i++)
	{
		tmpi = (tmpi - 1 + n) % n;
		tmpj = (tmpj + 1) % n;

		//check proper position
		if(magic[tmpi + offseti][tmpj + offsetj] != 0)
		{
			tmpi = (tmpi + 2) % n;
    		tmpj = (tmpj - 1 + n) % n;
		}
		magic[tmpi + offseti][tmpj + offsetj] = i + min - 1;
	}
}

//Double-even-number scale method of magic square(4N)
void DoubleEvenMagic(int n)
{
	int sum;
	int tmp, ri, rj;
	int i, j;

	tmp = 1;
	sum = n*n+1;
	//original number
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			magic[i][j] = (tmp ++);
	}

	//find proper position and replace it with complementary number
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			ri = i % 4;
			rj = j % 4;

			//find proper position
			if(((ri == 0 || ri == 3) && (rj == 0 || rj == 3)) ||
			   ((ri == 1 || ri == 2) && (rj == 1 || rj == 2)))
			{
				//replace with complementary number
				magic[i][j] = sum - magic[i][j];
			}
		}
	}
}

//Single-even-number scale method of magic square(4N+2)
void SingleEvenMagic(int n)
{
	int i, j, k;
	int startj;
	int tmp;

	//create four odd magic matrixs
	OddMagic(0, 0, 1, n/2);						//A
	OddMagic(n/2, n/2, (n/2)*(n/2) + 1, n/2);	//D
	OddMagic(0, n/2, 2*(n/2)*(n/2) + 1, n/2);	//B
	OddMagic(n/2, 0, 3*(n/2)*(n/2) + 1, n/2);	//C

	k = (n - 2) / 4;
	for(i = 0; i < n / 2; ++ i)
	{
		//A and C exchange
		if(i == k)
			startj = k;
		else
			startj = 0;
		for(j = startj; j < startj + k; ++ j)
		{
			tmp = magic[i][j];
			magic[i][j] = magic[i + n/2][j];
			magic[i + n/2][j] = tmp;
		}

		//B and D exchange
		startj = n - 1 - k;
		for(j = startj; j > startj - k + 1; -- j)
		{
			tmp = magic[i][j];
			magic[i][j] = magic[i + n/2][j];
			magic[i + n/2][j] = tmp;
		}
	}
}

//Check input whether legal and calculate
void GetMagic(int n)
{
	if(n > MAX || n < MIN)
	{
		printf("The scale must be %d--%d!\n", MIN, MAX);
		exit(-1);
	}

	InitMagic(n);

	if(n % 2 == 1)
		OddMagic(0, 0, 1, n);
	else if(n % 4 == 0)
		DoubleEvenMagic(n);
	else
		SingleEvenMagic(n);
}

int main()
{
	int n = 1;
	printf("---------- Magic Square ----------\n");
	printf("Input the number(3~30), and create the magic sqaure.\n");
	printf("Input 0 to exit.\n\n");
	while(1)
	{
		printf("Input the number: ");
		scanf("%d", &n);
		if(n == 0)
			break;
		else if(n >= 3 && n <= 20)
		{
			GetMagic(n);
			ShowMagic(n);
			printf("\n");
		}
		else
			printf("Invalid input!\n\n");
	}
	printf("Thank you!\n");
	return 0;
}

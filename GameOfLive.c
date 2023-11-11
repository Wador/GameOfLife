#include <windows.h>
#include <stdio.h>

#define W 25
#define H 80
#define G 400

int roundx(int i, int k)
{
	i += k;
	if (i >= W) i -= W;
	if (i < 0) i += W;
	return i;
}

int roundy(int j, int l)
{
	j += l;
	if (j >= H) j -= H;
	if (j < 0) j += H;
	return j;
}

int findnb(int M[W][H], int i, int j)
{
	int k, l, counter = 0;
	for (k = -1; k <= 1; k++)
	{
		for (l = -1; l <= 1; l++)
			if (k || l)
				if (M[roundx(i, k)][roundy(j, l)] != 0) counter++;
	}
	return counter;
}



int main()
{
	int M[W][H], N[W][H], i, j, k, q;
	srand((unsigned int) GetTickCount());
	for (i = 0; i < W; i++)
	{
		for (j = 0; j < H; j++)
		{
			M[i][j] = rand() % 2;
		}
	}

	for (k = 0; k < G; k++)
	{
		for (i = 0; i < W; i++)
		{
			for (j = 0; j < H; j++)
			{
				q = findnb(M, i, j);
				if (q != 3 && M[i][j] == 0)N[i][j] = 0;
				else if (q < 2 && M[i][j] != 0)N[i][j] = 0;
				else if (q > 3 && M[i][j] != 0)N[i][j] = 0;
				else N[i][j] = 1;
				if (M[i][j] == 1) printf("0");
				else printf(" ");
			}
			printf("\n");
		}
		Sleep(500);
		system("cls");

		for (i = 0; i < W; i++)
		{
			for (j = 0; j < H; j++)
			{
				M[i][j] = N[i][j];
			}
		}
	}
	return 0;
}


#include "Sudoku.h"

using namespace std;

void Sudoku::giveQuestion()
{
	int q1[9][9] = {{8,0,0,0,0,0,0,0,0},
					{0,0,3,6,0,0,0,0,0},
					{0,7,0,0,9,0,2,0,0},
					{0,5,0,0,0,7,0,0,0},
					{0,0,0,0,4,5,7,0,0},
					{0,0,0,1,0,0,0,3,0},
					{0,0,1,0,0,0,0,6,8},
					{0,0,8,5,0,0,0,1,0},
					{0,9,0,0,0,0,4,0,0}};

	for(i = 0 ; i < 9 ; i++ )
	{
		for(j = 0 ; j < 9 ; j++ )
		{
			printf("%d " , q1[i][j]);
		}
		printf("\n");
	}
}

void Sudoku::readIn()
{
	an = 0;
	for( i = 0 ; i < 9 ; i++ ) 
	{
		for( j = 0 ; j < 9 ; j++)
		{
			scanf( "%1d", &input[i][j] );
			//input2[i][j] = input[i][j];
		}
	}
	for (i = 0; i  < 9; ++i){
		for(j = 0; j < 9; ++j){
			if (input[i][j] != 0){
				for(k = 0; k < 9; ++k){
					if ((input[i][j] == input[i][k]) && j != k){
						an = 1;
						break;
					}
					if ((input[i][j] == input[k][j]) && i != k){
						an = 1;
						break;
					}
				}
			}
		}
	}
}



int Sudoku::avail(int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    
    for( j = 0 ; j < 9 ; j++ )
    {
        if (input[row][j] == num) return 0;
        if (input[j][col] == num) return 0;
        if (input[rowStart + (j%3)][colStart + (j/3)] == num) return 0;
    }
    return 1;
}

int Sudoku::avail2(int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    
    for( j = 8 ; j >= 0 ; j-- )
    {
        if (input2[row][j] == num) return 0;
        if (input2[j][col] == num) return 0;
        if (input2[rowStart + (j%3)][colStart + (j/3)] == num) return 0;
    }
    return 1;
}

int Sudoku::fill(int row, int col)
{
	int i;
    if( row < 9 && col < 9 )
    {
        if(input[row][col] != 0)
        {
            if((col+1)<9) return fill( row, col+1);
            else if((row+1)<9) return fill( row+1, 0);
            else return 1;
        }
        else
        {

            for( i = 0 ; i < 9 ; i++ )
            {
                if( avail(row , col , i+1) )
                {

                    input[row][col] = i+1;
                    if( ( col+1 ) < 9 )
                    {
                    	
                        if( fill(row, col + 1) ) return 1;
                        else input[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fill( row+1, 0)) return 1;
                        else input[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int Sudoku::fill2(int row, int col)
{
	int i;
    if( row > 0 && col > 0 )
    {
        if(input2[row][col] != 0)
        {
            if((col-1)>0) return fill2( row, col-1);
            else if((row-1)>0) return fill2( row-1, 0);
            else return 1;
        }
        else
        {

            for( i = 10 ; i > 1 ; i-- )
            {
                if( avail2(row , col , i -1) )
                {

                    input2[row][col] = i-1;
                    if( ( col-1 ) > 0 )
                    {
                    	
                        if( fill2(row, col - 1) ) return 1;
                        else input2[row][col] = 0;
                    }
                    else if( ( row + 1 ) > 0 )
                    {
                        if( fill2( row - 1 , 0) ) return 1;
                        else input2[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int Sudoku::fill3(int row, int col)
{
	int i;
    if( row < 9 && col < 9 )
    {
        if(input2[row][col] != 0)
        {
            if((col+1)<9) return fill3( row, col+1);
            else if((row+1)<9) return fill3( row+1, 0);
            else return 1;
        }
        else
        {

            for( i = 8 ; i >= 0 ; i-- )
            {
                if( avail3(row , col , i+1) )
                {

                    input2[row][col] = i+1;
                    if( ( col+1 ) < 9 )
                    {
                    	
                        if( fill3(row, col + 1) ) return 1;
                        else input2[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fill3( row+1, 0)) return 1;
                        else input2[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int Sudoku::avail3(int row, int col, int num)
{
    int rowStart = (row/3) * 3;
    int colStart = (col/3) * 3;
    
    for( j = 0 ; j < 9 ; j++ )
    {
        if (input2[row][j] == num) return 0;
        if (input2[j][col] == num) return 0;
        if (input2[rowStart + (j%3)][colStart + (j/3)] == num) return 0;
    }
    return 1;
}

void Sudoku::solve()
{
	//printf("%d\n", an);
	for(i = 0; i < 9; ++i){
		for(j = 0; j < 9; ++j){
			input2[i][j] = input[i][j];
		}
	}
	if( an == 1 ) {printf("0\n");
	return;
}
	bn = fill( 0 , 0 );
	cn = fill3( 0 , 0 ); 

	if( bn == 1)
	{
		dn = 0;
		for( i = 0; i < 9; ++i)
		{
			for(int u = 0; u < 9; ++u)
			{
				if (input[i][u] != input2[i][u]) dn = 1;
			}
		}

		if (dn == 1) printf("2\n");
		else
		{
			printf("1\n");
			for( i = 0 ; i < 9 ; i++ )
			{	
				for( j = 0 ; j < 9 ; j++ )
				{
					printf("%d " , input[i][j]);
				}
				printf("\n");
			}
		}
			
	}
	
	else
	{
		printf("0\n");
	}
}

void Sudoku::changeNum(int a , int b)
{
	for( i = 0 ; i < 9 ; i++ )
	{
		for( j = 0 ; j < 9 ; j++ )
		{
			if( input[i][j] == a)
			{
				input[i][j] = b;
			}
			else if( input[i][j] == b)
			{
				input[i][j] = a;
			}
		}
	}
}

void Sudoku::changeRow(int a , int b)
{
	int t;
	int temp[9];
	for( i = 0 ; i < 3 ; i++ )
	{
		for( j = 0 ; j < 9 ; j++ )
		{
			swap( input[i + (a*3)][j] , input[i + (b*3)][j]);
		}	
	}
}

void Sudoku::changeCol(int a , int b)
{
	int t;
	int temp[9];
	
	for( j = 0 ; j < 3 ; j++ )
	{
		for( i = 0 ; i < 9 ; i++ )
		{
			swap( input[i][j + (a*3)] , input[i][j + (b*3)]);
		}	
	}
}

void Sudoku::rotate(int n)
{
	int temp[9][9];

	n %= 4;
	switch(n)
	{
		case 0:
			break;

		case 1:
			for( j = 8 , k = 0 ; k < 9 ; j-- , k++ )
			{
				for( i = 0 , l = 0 ; l < 9  ; i++ , l++ )
				{
					temp[i][j] = input[k][l];
				}
			}

			for( i = 0 ; i < 9 ; i++)
			{
				for( j = 0 ; j < 9 ; j++)
				{
					input[i][j] = temp[i][j];
				}
			}
			break;

		case 2:
			for( i = 8 , k = 0 ; k < 9 ; i-- , k++ )
			{
				for( j = 8 , l = 0 ; l < 9  ; j-- , l++ )
				{
					temp[i][j] = input[k][l];
				}
			}

			for( i = 0 ; i < 9 ; i++)
			{
				for( j = 0 ; j < 9 ; j++)
				{
					input[i][j] = temp[i][j];
				}
			}
			break;

		case 3:
			for( j = 0 , k = 0 ; k < 9 ; j++ , k++ )
			{
				for( i = 8 , l = 0 ; l < 9  ; i-- , l++ )
				{
					temp[i][j] = input[k][l];
				}
			}

			for( i = 0 ; i < 9 ; i++)
			{
				for( j = 0 ; j < 9 ; j++)
				{
					input[i][j] = temp[i][j];
				}
			}
			break;
	}
}

void Sudoku::flip(int n)
{
	switch (n)
	{
		case 0:
			for( k = 0 ; k < 4 ; k++ )
			{
				for( i = 0; i < 9 ; i++)
				{
					swap( input[k][i] , input[8-k][i] );
				}
			}
			break;
		case 1:
			for( k = 0 ; k < 9 ; k++ )
			{
				for( i = 0 , j = 8  ; i < 4 ; i++ , j-- )
				{
					swap( input[k][i] , input[k][j] );
				}
			}	

	}
}

void Sudoku::transform()
{

	srand(time(NULL));
	changeNum(rand() % 9 + 1, rand() % 9 + 1);
	changeRow(rand() % 3, rand() % 3);
	changeCol(rand() % 3, rand() % 3);
	rotate(rand() % 20);
	flip(rand() % 2);
	for(i = 0 ; i < 9 ; i++ )
	{
		for(j = 0 ; j < 9 ; j++ )
		{
			printf("%d " , input[i][j]);
		}
		printf("\n");
	}
}

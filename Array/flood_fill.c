/* Flood fill Algorithm – how to implement fill() in paint?
 * In MS-Paint, when we take the brush to a pixel and click, the color of the region of that pixel is replaced with a new selected color. Following is the problem statement to do this task. 
 * Given a 2D screen, location of a pixel in the screen and a color, replace color of the given pixel and all adjacent same colored pixels with the given color.
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int matrix[10][10] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };

int
flood_fill(int matrix[10][10], int m, int n, int loc_x, int loc_y, int new_col)
{
    int i=0, j=0;
    int col = matrix[loc_x][loc_y];

    printf("MATRIX size(%d, %d)    location (%d, %d)\n", m, n, loc_x, loc_y);
    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    printf("%d  ", matrix[i][j]);
	}
	printf("\n");
    }
    printf("\n	    END		\n");


    for(i=loc_x; i<m; i++)
    {
	for(j=loc_y; j<n; j++)
	{
	    if(matrix[i][j] == col)
		matrix[i][j] = new_col;
	    else
		break;
	}
    }

    for(i=loc_x; i>=0; i--)
    {
        for(j=loc_y; j>=0; j--)
        {
            if(matrix[i][j] == col)
                matrix[i][j] = new_col;
            else
                break;
        }
    }

    for(i=loc_x; i>=0; i--)
    {
	 for(j=loc_y; j<n; j++)
	 {
	     if(matrix[i][j] == col)
		 matrix[i][j] = new_col;
	     else
		 break;
	 }
    }

    for(i=loc_x; i<m; i++)
    {
	for(j=loc_y; j>=0; j--)
	{
	    if(matrix[i][j] == col)
		matrix[i][j] = new_col;
	    else
		break;
	}
    }
    
    return 0;
}

int
main()
{
    int i, j;
    int m, n, col, x, y;


    /*
    printf("# of rows and columns : ");
    scanf("%d%d", &m, &n);


    printf("MATRIX : ");
    for(i=0; i<m; i++)
	for(j=0; j<n; j++)
	{
	    scanf("%d", &matrix[i][j]);
	}
    
    */

    m = 8;
    n = 8;
    printf("NEW COLOUR : ");
    scanf("%d", &col);

    printf("Location of new colurs : ");
    scanf("%d%d", &x, &y);

    flood_fill(matrix, m, n, x, y, col);

    for(i=0; i<m; i++)
    {
	for(j=0; j<n; j++)
	{
	    printf("%d  ", matrix[i][j]);
	}
	printf("\n");
    }
    printf("\n");

    return 0;
}


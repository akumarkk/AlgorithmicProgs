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
static int count;


int
flood_fill(int matrix[10][10], int m, int n, int loc_x, int loc_y,int given_col, int new_col)
{
    count++;
    if(loc_x > m && (loc_x < 0) &&
	    (loc_y > n) && (loc_y <0))
	return 0;

    if(matrix[loc_x][loc_y] != given_col)
	return 0;

    matrix[loc_x][loc_y] = new_col;

    flood_fill(matrix, m, n , loc_x, loc_y+1, given_col, new_col);
    flood_fill(matrix, m, n , loc_x+1, loc_y, given_col, new_col);
    flood_fill(matrix, m, n , loc_x-1, loc_y, given_col, new_col);
    flood_fill(matrix, m, n , loc_x, loc_y-1, given_col, new_col);
    
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

    flood_fill(matrix, m, n, x, y,matrix[x][y], col);
    printf("Count = %d\n", count);

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


#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;
void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
  //out of bounds
	if (cur.y < 0 || cur.y > size.y - 1 || cur.x < 0 || cur.x > size.x - 1
		|| tab[cur.y][cur.x] != to_fill)
		return ;
  // marks the current position with the character 'F' to indicate that it has been visited.
	tab[cur.y][cur.x] = 'F';
  //left
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
  //right
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
  //up
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
  //down
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;

    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {0, 0};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};

    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
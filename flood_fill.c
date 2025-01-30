#include <stdlib.h>
#include <stdio.h>

typedef struct  s_point
{
        int           x;
        int           y;
}                               t_point;

int     is_character(char character, char **tab, t_point size, t_point *begin)
{
        if (begin->y >= size.y || begin->x >= size.x || begin->y < 0 || begin->x < 0)
                return (0);
        if (tab[begin->y][begin->x] != character)
                return (0);
        tab[begin->y][begin->x] = 'F';

        begin->y = begin->y + 1;
        is_character(character, tab, size, begin);
        begin->y = begin->y - 1;

        begin->y = begin->y - 1;
        is_character(character, tab, size, begin);
        begin->y = begin->y + 1;

        begin->x = begin->x + 1;
        is_character(character, tab, size, begin);
        begin->x = begin->x - 1;

        begin->x = begin->x - 1;
        is_character(character, tab, size, begin);
        begin->x = begin->x + 1;

        return (0);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
        char    character;

        character = tab[begin.y][begin.x];
        is_character(character, tab, size, &begin);
}


char** make_area(char** zone, t_point size)
{
        char** new;

        new = malloc(sizeof(char*) * size.y);
        for (int i = 0; i < size.y; ++i)
        {
                new[i] = malloc(size.x + 1);
                for (int j = 0; j < size.x; ++j)
                        new[i][j] = zone[i][j];
                new[i][size.x] = '\0';
        }

        return new;
}

int main(void)
{
        t_point size = {8, 5};
        char *zone[] = {
                "11111111",
                "10001001",
                "00010001",
                "10110001",
                "11100001",
        };

        char**  area = make_area(zone, size);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        printf("\n");

        t_point begin = {7, 4};
        flood_fill(area, size, begin);
        for (int i = 0; i < size.y; ++i)
                printf("%s\n", area[i]);
        return (0);
}

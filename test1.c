#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int map[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int total=0;

void dfs(int x, int y) 
{
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE || visited[x][y] || map[x][y] == 1) 
    {
        return;
    }
    visited[x][y] = 1;
    if (map[x][y] == 2) 
    {
        total++;
    }
    dfs(x - 1, y);
    dfs(x + 1, y);
    dfs(x, y - 1);
    dfs(x, y + 1);
}

int main() 
{
    int start_x, start_y;
    scanf("%d %d", &start_x, &start_y);

for (int i = 0; i < MAX_SIZE; i++) 
{
    for (int j = 0; j < MAX_SIZE; j++) 
    {
        scanf("%d", &map[i][j]);
    }
}
dfs(start_x, start_y);
printf("%d", total);
return 0;
}
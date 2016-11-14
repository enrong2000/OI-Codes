//OPENJUDGE
//Time Limit : 1000 MS 
//Memory Limit : 65536 KB
//Enrong
//ÖØÐ´ 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;
 
bool map[6][6], fid = false;
int step;
int dr[5] = {-1, 0, 0, 0, 1};
int dc[5] = {0, -1, 0, 1, 0};
 
bool isgoal()
{                          
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 4; j ++)
            if(map[i][j] != map[1][1])
                return false;
    return true;
}
 
void flip(int row, int col)
{             
    for(int i = 0; i < 5; i ++)
    {
        int r = row + dr[i];
        int c = col + dc[i];
        map[r][c] = !map[r][c];
    }
}
 
void dfs(int row, int col, int dep) 
{   
    if(dep == step)
    {
        fid = isgoal();
        return;
    }
    if(fid || row == 5) return;

    flip(row, col);                    
    if(col < 4) dfs(row, col + 1, dep + 1);
    else dfs(row + 1, 1, dep + 1);

    flip(row, col);                      
    if(col < 4) dfs(row, col + 1, dep);
    else dfs(row + 1, 1, dep);
}
 
int main()
{
    char c;
    for(int i = 1; i <= 4; i ++)
        for(int j = 1; j <= 4; j ++)
       {
            cin >> c;
            if(c == 'b') map[i][j] = true;
       }
    for(step = 0; step <= 16; step ++){  
        dfs(1, 1, 0);
        if(fid) break;
    }
    if(fid) cout << step << endl;
    else cout << "Impossible" << endl;
    return 0; 
}

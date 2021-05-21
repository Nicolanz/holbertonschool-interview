#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool ckeckGrid(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void subtractCorners(int grid1[3][3]);
void subtractCentralCorners(int grid1[3][3]);

#endif /* _SANDPILES_H_*/

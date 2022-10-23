/*
Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally. Solving one piece at a time, and removing those solutions that fail to satisfy the constraints of the problem at any point of time (by time, here, is referred to the time elapsed till reaching any level of the search tree) is the process of backtracking.
*/
// Rat Maze probelm solved using backtracking 
#include <bits/stdc++.h>
using namespace std;

#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout<<" "<<sol[i][j]<<" ";
		cout<<endl;
	}
}


bool isSafe(int maze[N][N], int x, int y)
{

	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return true;
	return false;
}


bool solveMaze(int maze[N][N])
{
	int sol[N][N] = { { 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 },
					{ 0, 0, 0, 0 } };
	if (solveMazeUtil(maze, 0, 0, sol) == false) {
		cout<<"Solution doesn't exist";
		return false;
	}
	printSolution(sol);
	return true;
}


bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{

	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		sol[x][y] = 1;
		return true;
	}

	if (isSafe(maze, x, y) == true) {
		
		if (sol[x][y] == 1)
			return false;

		sol[x][y] = 1;

		if (solveMazeUtil(maze, x + 1, y, sol) == true)
			return true;

		if (solveMazeUtil(maze, x, y + 1, sol) == true)
			return true;

		sol[x][y] = 0;
		return false;
	}
	return false;
}

int main()
{
	int maze[N][N] = { { 1, 0, 0, 0 },
					{ 1, 1, 0, 1 },
					{ 0, 1, 0, 0 },
					{ 1, 1, 1, 1 } };
	solveMaze(maze);
	return 0;
}

// Time Complexity: O(2^(n^2)). 

// Space Complexity: O(n^2).
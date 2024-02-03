#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix_multiplication(vector<vector<int>>& matrixA, vector<vector<int>>& matrixB)
{
	vector<vector<int>> matrixC(matrixA.size(), vector<int>(matrixB[0].size()));
	int n = matrixA.size();
	int m = matrixA[0].size();
	int l = matrixB[0].size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			for (int k = 0; k < m; k++)
			{
				matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
	return matrixC;
}

int main()
{
	vector<vector<int>> A = {
		{1, 2, 3},
		{3, 1, 2}
	};

	vector<vector<int>> B = {
		{1, 2},
		{3, 2},
		{1, 2}
	};
	vector<vector<int>> C = {
		{10, 12},
		{8, 12}
	};
	cout << (matrix_multiplication(A, B) == C);
}
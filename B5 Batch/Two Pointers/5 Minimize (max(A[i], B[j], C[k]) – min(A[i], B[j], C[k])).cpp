// You can start from i = 0, j = 0 and k = 0
#include<bits/stdc++.h>
using namespace std;

int solve(int A[], int B[], int C[], int i, int j, int k)
{
		int min_diff, current_diff, max_term;

		// calculating min difference from last
		// index of lists
		min_diff = Integer.MAX_VALUE;

		while (i != -1 && j != -1 && k != -1)
		{
			current_diff = abs(max(A[i], max(B[j], C[k]))
							- min(A[i], min(B[j], C[k])));

			// checking condition
			if (current_diff < min_diff)
				min_diff = current_diff;

			// calculating max term from list
			max_term = max(A[i], max(B[j], C[k]));

			// Moving to smaller value in the
			// array with maximum out of three.
			if (A[i] == max_term)
				i -= 1;
			else if (B[j] == max_term)
				j -= 1;
			else
				k -= 1;
		}
		
		return min_diff;
	}

	// Driver code
	int main()
	{
		int D[] = { 5, 8, 10, 15 };
		int E[] = { 6, 9, 15, 78, 89 };
		int F[] = { 2, 3, 6, 6, 8, 8, 10 };
		int nD = sizeof(D) / sizeof(D[0]);
		int nE = sizeof(E) / sizeof(E[0]);
		int nF = sizeof(F) / sizeof(F[0]);
		cout << solve(D, E, F, nD-1, nE-1, nF-1);
		
		return 0;
	}

// This code is contributed by Ravi Maurya.

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		if (A == NULL || n == 0) return 1;

		int* tmp = new int[n + 1];

		for (int i = 0; i < n; ++i)
			if (A[i] >= 0 && A[i] <= n)
				tmp[A[i]] = A[i];

		int result = n + 1;
		for (int i = 1; i <= n; ++i)
			if (tmp[i] != i) {
				result = i;
				break;
			}
		
		delete[] tmp;

		return result;
	}
};
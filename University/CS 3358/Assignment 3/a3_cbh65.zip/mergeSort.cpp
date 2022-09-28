//Cole Hurst

#include <iostream>
using namespace std;

// Merges two sorted subarrays of A[].
// First sorted subarray is A[l..m].
// Second sorted subarray is A[m+1..r].
// You might want to call this function in function mergeSort().
void merge(int A[], int l, int m, int r)
{
    int lengthL = m - l + 1;
    int lengthR = r - m;
    int i, j, k;

    int L[lengthL];
    int R[lengthR];

    for (i = 0; i < lengthL; i++)
    {
        L[i] = A[l + i];
    }
    for(j = 0; j < lengthR; j++)
    {
        R[j] = A[m + 1+ j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < lengthL && j < lengthR)
    {
        if(L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < lengthL)
    {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < lengthR)
    {
        A[k] = R[j];
        j++;
        k++;
    }

}

// using mergeSort to sort sub-array A[l..r]
// l is for left index and r is right index of the
// sub-array of A[] to be sorted
void mergeSort(int A[], int l, int r)
{
    int m;

    if (l < r)
    {
        m = (l + r)/2 ;
        mergeSort(A,l,m);
        mergeSort(A, m +1, r);

        merge( A, l, m, r);
    }
}


int main()
{
    cout << "Please enter the length (number of elements) of the input array: ";
	int n;
	cin >> n;

	if(n <= 0) {
		cout << "Illegal input array length!" << endl;
		return 0;
	}

	int* A = new int [n];

	cout << "Please enter each element in the array" << endl;
	cout << "(each element must be an integer within the range of int type)." << endl;
	for(int i=0; i<n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}

    cout << "Given array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


    mergeSort(A, 0, n-1);

    cout << "After mergeSort, sorted array A[] is: ";
	for(int i=0; i<n-1; i++)
		cout << A[i] << ",";
	cout << A[n-1] << endl;


	delete [] A;
    return 0;
}

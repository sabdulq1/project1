#include <iostream>
#include <list>
#include <algorithm>
#include "rand-normal.cpp"
#include <cmath>

using namespace std;

int main()
{
    int N;
    double μ, σ;
    cout << "Enter the size of the array: ";
    cin >> N;
    cout << "Enter the mean of the random numbers: ";
    cin >> μ;
    cout << "Enter the standard deviation of the random numbers: ";
    cin >> σ;

    double X0[N];
    double X1[N];


    // Fill the array X0 with random numbers following a normal distribution
    for (int i = 0; i < N; i++) {
        X0[i] = rand_normal( μ, σ);
    }

    // Calculate the average of three numbers (left, ego, and right) for each element of the array X0 and store the result in X1
    for (int i = 0; i < N; i++) {
        int L = i == 0 ? N-1 : i-1;
        int R = i == N-1 ? 0 : i+1;
        X1[i] = (X0[L] + X0[i] + X0[R]) / 3;
    }

    // Print the resulting arrays
    cout << "X0: [";
    for (int i = 0; i < N; i++) {
        cout << X0[i] << " ";
    }
    cout << "]" << endl;

    cout << "X1: [";
    for (int i = 0; i < N; i++) {
        cout << X1[i] << " ";
    }
    cout << "]" << endl;

    return 0;
}

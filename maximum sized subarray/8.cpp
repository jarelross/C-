//Jarel Ross
//Write a program to find the sum of the maximum sized subarray of numbers that has the greatest sum.
// Input: Read from a file called input.txt. The first number will be the size of the array.
// All other integers will be elements in the array.
// 6 1 2 -2 3 4 1 Output: Maximum Sum is: 8
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include<string>
using namespace std;

int test(int entries, int a[], int count) {
    int large = 0, sum = 0, k = 0, i = 0, moveI = 0;
    for (int y = 0; y < count; y++) {
        i = moveI;

        for (i; k < entries; i++) {
            sum += a[i];
            k++;
        }
        if (sum > large) {
            large = sum;
        }

        k = 0;
        moveI++;
        sum = 0;
    }
    return large;
}

int main(int argc, char*argv[]) {

    int s = 0;
    int x;
    ifstream inFile;

    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file"<<endl ;
        exit(1);
    }
    int a[100];
    while (inFile >> x) {
        a[s] = x;
        s++;
    }
    inFile.close();
    int count = a[0];
    int list[count];
    for (int i = 0; i < count; i++) {
        list[i] = a[i+1];
        cout << list[i] << endl;
    }

    int max = 0;
    for (int i = 1; i < (count); i++) {

        int y = test(i, list, count);
        if (max < y) {
            max = y;
        }
    }
    cout << "final sum = " << max << endl;

    return 0;
}

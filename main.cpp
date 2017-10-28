#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;
#define INT_MAX 2147483647;

int binarySearch(int array[], int iBegin, int iEnd, int iSearch);
void sortSelection(int array[], int iEnd);
void sortInsertion(int array[], int n);
void sortMerge(int array[], int iBegin, int iEnd);
void merge(int array[], int iBegin, int iMid, int iEnd);
bool isUpperCase(char t[]);
int sqr(int x);
int sumOfSqr(int x);
void printRecursive(char* t, int charSize);
void printReverseRecursive(char* t, int charSize);
int gcd(int a, int b);
void printBinary(long long n);
bool* primeSieve(int n);


int main(int argc, char* argv[])
{

    if (argc)
    {
        for (int i = 1; i < argc; i++)
        {
            cout << argv[i][0];
        }
    }


    int arraySize = 9;
    int myArray[arraySize];

    for ( int i = 0; i < arraySize; i++)
        myArray[i] = (rand() % 1000);

    cout << "unsorted array: ";

    for (int i = 0; i < arraySize; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;
    cout << endl;

    sortMerge(myArray, 0, arraySize - 1);

    cout << "sorted array: ";
    for (int i = 0; i < arraySize; i++)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    /*

                char text[256];
                cout << "enter a string: ";
                cin.getline(text, 256);

                if (isUpperCase(text)){
                    cout << "the 1st letter is upperhcase\n";
                }
                else{
                    cout << "the 1st letter is not uppercase\n";
                }


                int x;
                cout << "Enter a number which you want to return a sum of squares: ";
                cin >> x;
                cout << sumOfSqr(x);



            char* t1 = "ABCDE";

            printRecursive(t1, 6);
            cout << endl;
            printReverseRecursive(t1, 0);
            cout << endl;


            int a;
            int b;
            cout << "Enter two numbers: ";
            cin >> a >> b;
            cout << "the GCD of " << a << " and " << b << " is " << gcd(a,b);



        long long x;
        cout << "Enter a number you wish to see in binary: ";
        cin >> x;
        printBinary(x);



        cout << "What number would you like to find all the primes of? ";
        int n;
        cin >> n;

        bool* primes = primeSieve(n);

        cout << "The primes of " << n << " are: ";
        for (int i = 0; i < n; i++){
            if (primes[i])
                cout << i << " ";
        }
        cout << endl;

        delete [] primes;


        cout << "Enter a number that you want to test if it is prime or not: ";
        long long a;
        cin >> a;
        if (a % 2 == 0)
            cout << "the number is not prime\n";
        else
            cout << "the number is prime\n";

            */
    return 0;
}


int binarySearch(int array[], int iBegin, int iEnd, int iSearch)
{

    while (true)
    {

        int iMiddle = (iBegin + iEnd) / 2;
        if (iBegin > iEnd)
            return iBegin;
        else if(array[iMiddle] == iSearch)
            return iMiddle;
        else if(iSearch > array[iMiddle])
            iBegin = iMiddle + 1;
        else
            iEnd = iMiddle - 1;
    }
}

void sortSelection(int array[], int iEnd)
{

    int iShift;
    int iPivot;
    int j = 0;

    for (iPivot = iEnd - 2; iPivot >= 0; iPivot--)
    {
        int valuePivot = array[iPivot];
        int index = binarySearch(array, iPivot +1, iEnd - 1, valuePivot);
        index--;

        for (iShift = iPivot; iShift < index; iShift++)
        {
            array[iShift] = array[iShift + 1];
        }
        array[iShift] = valuePivot;

    }

}

void sortInsertion(int array[], int n)
{

    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}


void sortMerge(int array[], int iBegin, int iEnd)
{
    if (iBegin < iEnd)
    {
        int middle = (iBegin + iEnd) / 2;

        sortMerge(array, iBegin, middle);
        sortMerge(array, middle + 1, iEnd);
        merge(array, iBegin, middle, iEnd);
    }

}
void merge(int array[], int iBegin, int iMid, int iEnd)
{

    int n1 = (iMid - iBegin) + 1;
    int n2 = iEnd - iMid;

    int left[n1];
    int right[n2];

    // copy over lower half
    for (int i = 1; i <= n1; i++)
    {
        left[i] = array[iBegin + i - 1];
        cout << "left i:" << i << " " << left[i] << endl;
    }
    // now the upper half
    for (int i = 1; i <= n2; i++)
    {
        right[i] = array[iMid + i];
        cout << "right i:" << i << " " << right[i] << endl;
    }

    cout << "IBegin: " << iBegin << endl;
    cout << "IMid: " << iMid << endl;
    cout << "iEnd: " << iEnd << endl;
    cout << "N1: " << n1 << endl;
    cout << "N2: " << n2 << endl;

    // left[n1 + 1] = INT_MAX;
    // right[n2 + 1] = INT_MAX;

    int i = 1;
    int j = 1;
    for (int k = iBegin; k <= iEnd; k++)
    {
        if (left[i] <= right[j]){
            array[k] = left[i];
            i++;
            cout << "Array[" << k << "]: " << array[k] << endl;

            if (i > n1){
                k++;
                while(j <= n2 && k <= iEnd){
                    array[k] = right[j];
                    j++;
                    cout << "Array[" << k << "]: " << array[k] << endl;
                    k++;
                }
            }
        }
        else{
            array[k] = right[j];
            j++;
            cout << "Array[" << k << "]: " << array[k] << endl;
            if (j > n2){
                k++;
                while (i <= n1 && k <= iEnd){
                    array[k] = left[i];
                    cout << "Array[" << k << "]: " << array[k] << endl;
                    k++;
                    i++;

                }
            }
        }

    }

    cout << endl;

}

bool isUpperCase(char t[])
{
    if (t[0] >= 65 && t[0] <= 90)
        return true;

    return false;
}

int sqr(int x)
{
    return x * x;
}
int sumOfSqr(int x)
{
    if (x == 0)
    {
        return x;
    }
    else
    {
        return sumOfSqr((x -1)) + sqr(x);
    }
}

void printRecursive(char* t, int charSize)
{
    if(charSize)
    {
        printRecursive(t, charSize - 1);
        cout << t[charSize - 1];
    }
    else
    {
        return;
    }
}

void printReverseRecursive(char* t, int charSize)
{
    if (t[charSize] == 0)
        return;
    else
    {
        printReverseRecursive(t, charSize + 1);
        cout << t[charSize];
    }

}

int gcd(int a, int b)
{

    if (b == 0)
        return a;
    else if (a % 2 != 0 && b % 2 == 0)
    {
        return 1;
    }
    else
    {
        gcd(b, a % b);
    }

}

void printBinary(long long n)
{
    if (n > 0)
    {

        long long r = n % 2;
        printBinary(n /= 2);

        if (r)
            cout << "1";
        else
            cout << "0";
    }
}


bool* primeSieve(int n)
{

    bool* temp = new bool[n + 1];

    for (int i = 0; i < n; i++)
    {
        temp[i] = true;
    }

    int m = sqrt(n);
    temp[0] = false;
    temp[1] = false;

    for (int i = 2; i <= m; i++)
    {
        if(temp[i])
        {
            for (int j = i * i; j <= n; j += i)
                temp[j] = false;
        }
    }

    return temp;
}


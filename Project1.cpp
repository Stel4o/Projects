#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 30;

// function prototypes
void inputArray(double[], int&);
void sumPositiveNumbers(double[], int);
void meanNegativeNumbers(double[], int);
void productNonZeroNumbers(double[], int);
void minPositiveNumber(double[], int);
void displayArray(double[], int);

int main()
{
    int choice; 
    int size; 
    double array[MAX_SIZE]; 

    do
    {

        cout << "1. Input array\n";
        cout << "2. Sum of positive numbers\n";
        cout << "3. Arithmetic mean of negative numbers\n";
        cout << "4. Product of non-zero numbers\n";
        cout << "5. Minimum positive number\n";
        cout << "6. Display array\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            inputArray(array, size);
            break;
        case 2:
            sumPositiveNumbers(array, size);
            break;
        case 3:
            meanNegativeNumbers(array, size);
            break;
        case 4:
            productNonZeroNumbers(array, size);
            break;
        case 5:
            minPositiveNumber(array, size);
            break;
        case 6:
            displayArray(array, size);
            break;
        case 7:
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}

void inputArray(double arr[], int& size)
{
    cout << "Enter the size of the array (L): ";
    cin >> size;

    if (size <= 0 || size > MAX_SIZE)
    {
        cout << "Invalid size.\n";
        return;
    }

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}


void sumPositiveNumbers(double arr[], int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
            sum += arr[i];
    }

    cout << "Sum of positive numbers: " << sum << endl;
}
void meanNegativeNumbers(double arr[], int size)
{
    double sum = 0;
    int count = 0;
    double min, max;


    cout << "Enter the minimum value of the interval: ";
    cin >> min;
    cout << "Enter the maximum value of the interval: ";
    cin >> max;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0 && arr[i] >= min && arr[i] <= max)
        {
            sum += arr[i];
            count++;
        }
    }

    if (count > 0)
        cout << "Arithmetic mean of negative numbers: " << sum / count << endl;
    else
        cout << "There are no negative numbers in the specified interval.\n";
}
void productNonZeroNumbers(double arr[], int size)
{
    double product = 1;
    int zeroCount = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            product *= arr[i];
        else
            zeroCount++;
    }

    cout << "Product of non-zero numbers: " << product << endl;
    cout << "Number of zero numbers: " << zeroCount << endl;
}
void minPositiveNumber(double arr[], int size)
{
    double min = -1;
    int minIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0 && (arr[i] < min || min == -1))
        {
            min = arr[i];
            minIndex = i;
        }
    }

    if (minIndex == -1)
        cout << "There are no positive numbers in the array.\n";
    else
        cout << "Minimum positive number: " << min << " at index " << minIndex << endl;
}
void displayArray(double arr[], int size)
{
    cout << "The elements of the array are:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
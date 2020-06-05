// negtivae positive ele AND keeping order.
#include <iostream>
using namespace std;

void segregate(int arr[], int n)
{
    int count_negative = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
            count_negative++;
    int i = 0, j = i + 1;
    while (i != count_negative) {

        if (arr[i] < 0) {
            i++;
            j = i + 1;
        }
        else if (arr[i] > 0 && j < n) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int count_negative = 0;
    int arr[] = { -12, 1, -13, 5, 6, -7, 5, -3, -6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    segregate(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

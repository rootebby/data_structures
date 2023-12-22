#include <stdio.h>

int find_max(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        int max_of_rest = find_max(a + 1, n - 1);
        return (a[0] > max_of_rest) ? a[0] : max_of_rest;
    }
}

int find_min(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        int min_of_rest = find_min(a + 1, n - 1);
        return (a[0] < min_of_rest) ? a[0] : min_of_rest;
    }
}

int find_sum(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        return a[0] + find_sum(a + 1, n - 1);
    }
}

int find_product(int a[], int n) {
    if (n == 1) {
        return a[0];
    } else {
        return a[0] * find_product(a + 1, n - 1);
    }
}

float find_average(int a[], int n) {
    int sum = find_sum(a, n);
    return (float)sum / n;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 4, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Maximum element: %d\n", find_max(arr, size));
    printf("Minimum element: %d\n", find_min(arr, size));
    printf("Sum of elements: %d\n", find_sum(arr, size));
    printf("Product of elements: %d\n", find_product(arr, size));
    printf("Average of elements: %.2f\n", find_average(arr, size));

    return 0;
}

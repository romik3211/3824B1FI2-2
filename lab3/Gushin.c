#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#define N 7

bool func(int arr[N]) {
    int t[N] = { 0 };
    for (int i = 0; i < N; i++) {
        t[arr[i]]++;
    }
    for (int i = 0; i < N; i++) {
        if (t[i] != 1)
            return false;
        else continue;
    }
    return true;
}
int nod(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    setlocale(LC_ALL, "RUS");
    int a, b;
    printf("Введите 2 числа\n");
    scanf_s("%d %d", &a, &b);
    int nd = nod(a, b);
    printf("Их Нод равен: %d", nd);
    /*int a[N];
    printf("Введите элементы массива, %d элементов\n", N);
    for (int i = 0; i < N; i++) {
        int d;
        scanf_s("%d", &d);
        a[i] = d;
    }
    bool b = func(a);
    if (b)
        printf("da");
    else
        printf("net");*/
}
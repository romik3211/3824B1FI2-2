#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "RUS");
    int kod[] = { 2313, 7457, 3274, 3275, 5322, 2108 };
    char tovar[6][31] = { "Творог 300г", "Молоко 1л", "Хлеб", "Гречневая крупа 1 кг", "Макароны 500г", "Вода 0.5л" };
    int sizet = sizeof(tovar) / sizeof(tovar[0]);
    int cena[] = { 100, 90, 30, 110, 200, 60 };
    int kolv[6] = { 0 };
    int k = -1;
    int sm = 0;
    printf("Для перехода к оплате нажмите '0'\n");
    while (k != 0) {
        printf("Отсканируйте покупки: \n");
        if (scanf_s("%d", &k) != 1) {
            printf("Неверный формат кода\n");
            while (getchar() != '\n');
            continue;
        }
        if (k == 0)
            break;
        int b = 0;
        for (int i = 0; i < sizet; i++) {
            if (kod[i] == k) {
                sm += cena[i];
                kolv[i] += 1;
                printf("Успешно\n");
                b = 1;
                break;
            }
        }
        if (b == 0) {
            printf("Такого товара нет\n");
        }
    }

    system("cls");
    printf("Ваш чек:\n\n");
    for (int i = 0; i < sizet; i++) {
        if (kolv[i] > 0) {
            printf("%s   Стоимость:%d Руб, шт: %d  Итого: %d\n", tovar[i], cena[i], kolv[i], cena[i] * kolv[i]);
        }
    }
    printf("\n");
    printf("Итоговая сумма: %d\n", sm);
}
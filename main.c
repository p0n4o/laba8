#include <stdlib.h>
#include "data.h" // Импортируем "data.h"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\e[0;33m"

void search(int* n, EMPLOYEE **emp){ // Функция поиска набора, удовлетворяющего условию

    // Объявление всех необходимых для решения переменных
    int new[*n];
    int max_height = 0;
    int min_price = 100000;
    int p = 0;
    int res;

    for(int i = 0; i<*n; i++){ // Находим минимальное значение цены среди всех наборов
        if(emp[i]->price < min_price){
            min_price = emp[i]->price;
        }
    }

    for(int j = 0; j<*n; j++) { // В заранее объявленный массив записываем номера всех наборов с минимальной ценой
        if (emp[j]->price == min_price){
            new[p] = j;
            p++;
        }
    }

    for (int k = 0; k < p; k++) { // Среди всех наборов вошедших в массив "new" находим набор с наибольшей высотой
        if (emp[new[k]]->ftr.height > max_height) {
            max_height = emp[new[k]]->ftr.height;
            res = new[k];
        }
    }

    // Вывод набора, удовлетворяющего условию
    printf(ANSI_COLOR_WHITE "Название самого высокого набора минимальной цены:" ANSI_COLOR_GREEN "\t\"%s\"\n", emp[res]->name);
    printf(ANSI_COLOR_YELLOW "Цена:     %li\n", emp[res]->price);
    printf(ANSI_COLOR_WHITE "Вес:      %li\n", emp[res]->ftr.weight);
    printf(ANSI_COLOR_YELLOW "Высота:   %li\n", emp[res]->ftr.height);
    printf(ANSI_COLOR_WHITE "Ширина:   %li\n\n", emp[res]->ftr.width);
}


int main(){

    EMPLOYEE **employee[20]; // Объявляем массив указателей на структуру
    for (int i = 0; i < 20; i++) employee[i] = malloc(sizeof(EMPLOYEE)); // Выделяем память для внутренних массивов структуры
    int n = create(employee); // Перменная n задает количество наборов
    if (n == 0){ // Если n = 0, то завершаем программу
        return 0;
    }
    else{
        // Иначе вызываем функции, описанные в "data.h"

        output(employee, &n);
        search(&n, employee);
        return 0;
    }
}





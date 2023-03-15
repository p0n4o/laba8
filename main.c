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
    int l = 0;
    int res[*n];

    for(int i = 0; i<*n; i++){ // Находим минимальное значение цены среди всех наборов
        if(emp[i]->price < min_price){
            min_price = emp[i]->price;
        }
    }


    for(int j = 0; j<*n; j++) { // В заранее объявленный массив записываем индексы всех наборов с минимальной ценой
        if (emp[j]->price == min_price){
            new[p] = j;
            p++;
        }
    }

    for(int m = 0; m < p; m++){ // Находим максимальное значение высоты среди всех наборов минимальной цены
        if(emp[new[m]]->ftr.height > max_height){
            max_height = emp[new[m]]->ftr.height;
        }
    }

    for (int k = 0; k < p; k++) { // Среди всех наборов, индексы которых вошли в массив "new", находим наборы с наибольшей высотой
        if (emp[new[k]]->ftr.height == max_height) {
            res[l] = new[k];
            l++;
        }
    }
    if (l > 1){
        for (int s = 0; s < l; s++) {
            // Если наборов, удовлетворяющих условию, несколько, то выводим с учетом нуменклатуры
            printf(ANSI_COLOR_WHITE "Название %d-го самого высокого набора минимальной цены:" ANSI_COLOR_GREEN "\t\"%s\"\n", s+1, emp[res[s]]->name);
            printf(ANSI_COLOR_YELLOW "Цена:     %li\n", emp[res[s]]->price);
            printf(ANSI_COLOR_WHITE "Вес:      %li\n", emp[res[s]]->ftr.weight);
            printf(ANSI_COLOR_YELLOW "Высота:   %li\n", emp[res[s]]->ftr.height);
            printf(ANSI_COLOR_WHITE "Ширина:   %li\n\n", emp[res[s]]->ftr.width);
        }
    }
    else{
        // Если один набор удовлетворяет условию, то просто выводим
        printf(ANSI_COLOR_WHITE "Название самого высокого набора минимальной цены:" ANSI_COLOR_GREEN "\t\"%s\"\n", emp[res[0]]->name);
        printf(ANSI_COLOR_YELLOW "Цена:     %li\n", emp[res[0]]->price);
        printf(ANSI_COLOR_WHITE "Вес:      %li\n", emp[res[0]]->ftr.weight);
        printf(ANSI_COLOR_YELLOW "Высота:   %li\n", emp[res[0]]->ftr.height);
        printf(ANSI_COLOR_WHITE "Ширина:   %li\n\n", emp[res[0]]->ftr.width);
    }
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





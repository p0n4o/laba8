#include <stdlib.h>
#include "data.h"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\e[0;33m"

void search(int* n, EMPLOYEE **emp){
    int new[*n];
    int max_height = 0;
    int min_price = 100000;
    int p = 0;
    int res;

    for(int i = 0; i<*n; i++){
        if(emp[i]->price < min_price){
            min_price = emp[i]->price;
        }
    }

    for(int j = 0; j<*n; j++) {
        if (emp[j]->price == min_price){
            new[p] = j;
            p++;
        }
    }

    for (int k = 0; k < p; k++) {
        if (emp[new[k]]->ftr.height > max_height) {
            max_height = emp[new[k]]->ftr.height;
            res = new[k];
        }
    }
    printf(ANSI_COLOR_WHITE "Название самого высокого набора минимальной цены:" ANSI_COLOR_GREEN "\t\"%s\"\n", emp[res]->name);
    printf(ANSI_COLOR_YELLOW "Цена:     %d\n", emp[res]->price);
    printf(ANSI_COLOR_WHITE "Вес:      %d\n", emp[res]->ftr.weight);
    printf(ANSI_COLOR_YELLOW "Высота:   %d\n", emp[res]->ftr.height);
    printf(ANSI_COLOR_WHITE "Ширина:   %d\n\n", emp[res]->ftr.width);
}


int main(){
//  system("chcp 65001");
    EMPLOYEE **employee[20];

    for (int i = 0; i < 20; i++) employee[i] = malloc(sizeof(EMPLOYEE));

    int n = create(employee);
    if (n == 0){
        return 0;
    }
    else{
        output(employee, &n);
        search(&n, employee);
        return 0;
    }
}





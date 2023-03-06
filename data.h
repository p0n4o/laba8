#include <stdio.h>
#include <string.h>
#include "file.h"
#define ANSI_COLOR_WHITE   "\e[1;37m"
#define ANSI_COLOR_CYAN    "\e[1;36m"
//#define DEBUG


int create(EMPLOYEE **emp){
#if DEBUG
    int n;
	printf("Число наборов:\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Введите название набора:\n");
		scanf("%s", &emp[i].name[100]);
		printf("Введите цену набора:\n");
		scanf("%d", &emp[i].price);
		printf("Введите вес набора:\n");
		scanf("%d", &emp[i]->ftr.weight);
		printf("Введите высоту набора:\n");
		scanf("%d", &emp[i]->ftr.height);
		printf("Введите ширину набора:\n");
		scanf("%d", &emp[i]->ftr.width);
	}
#else
    int n=18;

    strcpy(emp[0]->name, "Эйфелева башня");
    emp[0]->price = 99999;
    emp[0]->ftr.weight = 10001;
    emp[0]->ftr.height = 48;
    emp[0]->ftr.width = 59;

    strcpy(emp[1]->name, "Титаник");
    emp[1]->price = 99999;
    emp[1]->ftr.weight = 9090;
    emp[1]->ftr.height = 59;
    emp[1]->ftr.width = 39;

    strcpy(emp[2]->name, "Больничное крыло Хогвартса");
    emp[2]->price = 6499;
    emp[2]->ftr.weight = 510;
    emp[2]->ftr.height = 38;
    emp[2]->ftr.width = 6;

    strcpy(emp[3]->name, "Магазины цветов и дизайна в центре");
    emp[3]->price = 22999;
    emp[3]->ftr.weight = 2010;
    emp[3]->ftr.height = 38;
    emp[3]->ftr.width = 58;

    strcpy(emp[4]->name, "Ferrari Daytona SP3");
    emp[4]->price = 59999;
    emp[4]->ftr.weight = 3778;
    emp[4]->ftr.height = 29;
    emp[4]->ftr.width = 62;

    strcpy(emp[5]->name, "Пирамида Хеопса");
    emp[5]->price = 16999;
    emp[5]->ftr.weight = 1476;
    emp[5]->ftr.height = 38;
    emp[5]->ftr.width = 48;

    strcpy(emp[6]->name, "Арсенал Железного человека");
    emp[6]->price = 9999;
    emp[6]->ftr.weight = 496;
    emp[6]->ftr.height = 26;
    emp[6]->ftr.width = 38;

    strcpy(emp[7]->name, "Боевой корабль Республики");
    emp[7]->price = 34999;
    emp[7]->ftr.weight = 3292;
    emp[7]->ftr.height = 58;
    emp[7]->ftr.width = 17;

    strcpy(emp[8]->name, "Орхидея");
    emp[8]->price = 6999;
    emp[8]->ftr.weight = 608;
    emp[8]->ftr.height = 38;
    emp[8]->ftr.width = 26;

    strcpy(emp[9]->name, "Праздничный поезд Микки и Минни");
    emp[9]->price = 3599;
    emp[9]->ftr.weight = 22;
    emp[9]->ftr.height = 35;
    emp[9]->ftr.width = 7;

    strcpy(emp[10]->name, "Символы Хогвартса: коллекционное издание");
    emp[10]->price = 39999;
    emp[10]->ftr.weight = 3010;
    emp[10]->ftr.height = 58;
    emp[10]->ftr.width = 12;

    strcpy(emp[11]->name, "Визит в деревню Хогсмид");
    emp[11]->price = 10999;
    emp[11]->ftr.weight = 851;
    emp[11]->ftr.height = 48;
    emp[11]->ftr.width = 7;

    strcpy(emp[12]->name, "Халкбастер: битва за Ваканду");
    emp[12]->price = 8499;
    emp[12]->ftr.weight = 385;
    emp[12]->ftr.height = 28;
    emp[12]->ftr.width = 26;

    strcpy(emp[13]->name, "Конструктор Элвис Пресли");
    emp[13]->price = 13999;
    emp[13]->ftr.weight = 3445;
    emp[13]->ftr.height = 40;
    emp[13]->ftr.width = 5;

    strcpy(emp[14]->name, "Полноприводный грузовик-внедорожник Mercedes-Benz Zetros");
    emp[14]->price = 35999;
    emp[14]->ftr.weight = 2110;
    emp[14]->ftr.height = 58;
    emp[14]->ftr.width = 9;

    strcpy(emp[15]->name, "Космодром");
    emp[15]->price = 17999;
    emp[15]->ftr.weight = 1010;
    emp[15]->ftr.height = 58;
    emp[15]->ftr.width = 9;

    strcpy(emp[16]->name, "Чаепитие у Эльзы и Олафа");
    emp[16]->price = 2799;
    emp[16]->ftr.weight = 17;
    emp[16]->ftr.height = 26;
    emp[16]->ftr.width = 6;

    strcpy(emp[17]->name, "Патруль разбойников");
    emp[17]->price = 8999;
    emp[17]->ftr.weight = 562;
    emp[17]->ftr.height = 26;
    emp[17]->ftr.width = 38;

#endif
    return n;
}

void output(EMPLOYEE **emp, int* n){
    printf("Наборы:\n\n");
    for (int i = 0; i < *n; i++) {
        printf(ANSI_COLOR_WHITE  "Название набора:" ANSI_COLOR_CYAN "\t\"%s\"\n", emp[i]->name);
        printf(ANSI_COLOR_WHITE "Цена:     %d\n", emp[i]->price);
        printf("Вес:      %d\n", emp[i]->ftr.weight);
        printf("Выоста:   %d\n", emp[i]->ftr.height);
        printf("Ширина:   %d\n\n", emp[i]->ftr.width);
    }
}



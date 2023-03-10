typedef struct {      // Создание подстуктуры "FEATURES"
    long int weight;  // Объявление параметра "weight" как long int
    long int height;  // Объявление параметра "height" как long int
    long int width;   // Объявление параметра "width" как long int
} FEATURES;

typedef struct {      // Создание стуктуры "EMPLOYEE"
    FEATURES ftr;     // Подструктура "FEATURES"
    long int price;   // Объявление параметра "price" как long int
    char name[100];   // Объявление параметра "name" как char[100]
} EMPLOYEE;


#include <iostream>

typedef struct Node_tag {
    int ar[2];
    struct Node_tag *next;
} Node_t; //Вводим структуру для стэка

void push(Node_t **head, int num1,int num2) { //Функция для добавляения нового значения(цифорок) в стэк
    Node_t *tmp = new Node_t; //Память выделяем
    if (tmp == NULL) {
        exit(0); //Если ничего не передалось выходим из программы
    }

    tmp->next = *head;
    tmp->ar[0] = num1;
    tmp->ar[1] = num2;//Тут как раз запонения стэка(то есть в его начало добавляются элементы)
    *head = tmp;
}

void printStack(const Node_t* head) { //функция просто вывволдит стэк который ему передали
    while (head) {
        std::cout << " " << head->ar[0] << " "<< head->ar[1] << " | ";
        head = head->next; 
    }
}
void check(Node_t* head,int num) { //Эта функция смотрит если сумма пары чисел равно сумме которую мы задали то она обнуляет значения
    while (head) {
        int num1,num2;
        num1= (int) head->ar[0];
        num2= (int) head->ar[1];//переводит в инт то что мы передали(пары эти которые передали)
        if((num1+num2)==num){ //оператор если, если сумма равна тому что передали то ниже все зануляеем
            head->ar[0]=0;
            head->ar[1]=0;
        }

        head = head->next;
    }
}

int main() {
    int i;
    Node_t *head = NULL;
    int kol,num1,num2,opr; //просто вводим интовые значения
    std::cout << "Введите сумму:";
    std::cin >> opr;//запрашивает сумму
    std::cout << "Введите количество пар: ";
    std::cin >> kol; //колво пар запрашивает
    for(int x=0;x<kol;x++){
        std::cout << "Введите пару: ";
        std::cin >> num1;
        std::cin >> num2;//вводим пары
        push(&head,num1,num2);//закидывем их в функцию пуш
    }
    std::cout << "Изначальный стэк: ";
    printStack(head);//печатаем не обработаные числа
    check(head,opr);//закидываем в функцию для проверки суммы
    std::cout << "\nИзмененный стэк: ";
    printStack(head); //печатаем изменненый стэк
    return 0;
}
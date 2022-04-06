#include <iostream>

typedef struct Node_tag {
    int num;
    struct Node_tag *next;

} Node_t;//Вводим структуру для стэка

void push(Node_t **head, int value1) { //та же функция пуш что и в первой проге
    Node_t *tmp = new Node_t;
    if (tmp == NULL) {
        exit(0);
    }

    tmp->next = *head;
    tmp->num =  value1;

    *head = tmp;
}

void printStack(const Node_t* head) {//та же функция пуш что и в первой проге
    while (head) {
        std::cout << " " << head->num;
        head = head->next;
    }
}
int pop(Node_t **head) {//вытаскиевает значения из стэка
    Node_t *out;
    int value;
    if (*head == NULL) {
        exit(0);
    }
    out = *head;
    *head = (*head)->next;
    value = out->num;
    delete out;
    return value;
}


int main() {

    Node_t *head = NULL;
    Node_t *num_1 = NULL;
    Node_t *num_2 = NULL;
    int kol,num1;
    std::cout << "Колво элементов: ";
    std::cin >> kol;
    std::cout << "Элементы: ";
    for(int x=0;x<kol;x++){
        std::cin >> num1;
        push(&head,num1);
    }

    while (head) {//цикл идет пока стэк не кончиться 
        int n= pop(&head); // передается значение из стэка
        if(n%2==0){//смотрит четное или не четное и заносит в первый иили второй стек соотвественно
            push(&num_2,n);
        } else{
            push(&num_1,n);
        }
    }

    std::cout << "\nНечетный стэк: ";//вывводит стэки
    printStack(num_1);
     std::cout << "\nЧетный стэк: ";
    printStack(num_2);
    return 0;
}
#include <iostream> 
#include <Windows.h>
using namespace std;

struct Node { // Оголошення структури Node
    int data; // Поле для збереження даних
    Node* next; // Вказівник на наступний елемент
};

bool hasDuplicatePair(Node* head) { // Функція для перевірки наявності пари елементів з однаковими значеннями
    Node* current = head; // Покажчик current на початок списку

    while (current != nullptr && current->next != nullptr) { // Перевірка, чи список не закінчився і чи наступний елемент не є останнім
        int currentValue = current->data; // Збереження значення поточного елементу
        Node* runner = current->next; // Покажчик runner на наступний елемент після поточного

        while (runner != nullptr) { // Перегляд усіх наступних елементів після поточного
            if (runner->data == currentValue) { // Перевірка, чи значення наступного елементу дорівнює значенню поточного
                return true; // Якщо так, повертаємо true (знайдена пара з однаковими значеннями)
            }
            runner = runner->next; // Перехід до наступного елементу
        }

        current = current->next; // Перехід до наступного елементу
    }

    return false; // Якщо жодна пара з однаковими значеннями не знайдена, повертаємо false
}

void createList(Node*& head, Node*& tail, int values[], int size) { // Функція для створення списку з масиву значень
    head = nullptr; // Ініціалізація початкового та кінцевого вузла як nullptr
    tail = nullptr;

    for (int i = 0; i < size; i++) { // Проходження по усім елементам масиву
        Node* newNode = new Node(); // 1 Створення нового вузла
        newNode->data = values[i]; // 2 Присвоєння значення вузлу з масиву
        newNode->next = nullptr; // 3 Ініціалізація вказівника на наступний вузол як nullptr

        if (head == nullptr) { // Якщо список порожній
            head = newNode; // Встановлення початкового вузла
            tail = newNode; // Встановлення кінцевого вузла
        }
        else { // Якщо список не порожній
            tail->next = newNode; // Додавання нового вузла після кінцевого вузла
            tail = newNode; // Оновлення кінцевого вузла
        }
    }
}

void printList(Node* head) { // Функція для виведення списку на екран
    Node* current = head; // Покажчик current на початок списку

    while (current != nullptr) { // Проходження по усіх вузлах списку
        cout << current->data << " "; // Виведення значення поточного вузла
        current = current->next; // Перехід до наступного вузла
    }

    cout << endl; // Виведення символу нового рядка після виведення всього списку
}


int main() { // Основна функція програми

    int values[] = { 1, 2, 3, 4, 5, 2 }; // Задання масиву значень для створення списку
    int size = sizeof(values) / sizeof(values[0]); // Визначення розміру масиву

    Node* head = nullptr; // Ініціалізація початкового та кінцевого вузла як nullptr
    Node* tail = nullptr;

    createList(head, tail, values, size); // Створення списку з масиву значень

    cout << "Список елементів:" << endl; // Виведення тексту на екран
    printList(head); // Виведення списку на екран

    if (hasDuplicatePair(head)) { // Перевірка наявності пари елементів з однаковими значеннями
        cout << "Список містить пару елементів з однаковими значеннями." << endl; // Виведення тексту на екран
    }
    else { // Якщо пари елементів з однаковими значеннями не знайдено
        cout << "Список не містить пару елементів з однаковими значеннями." << endl; // Виведення тексту на екран
    }

    Node* current = head; // Покажчик current на початок списку
    while (current != nullptr) { // Проходження по усіх вузлах списку
        Node* temp = current; // Тимчасове зберігання поточного вузла
        current = current->next; // Перехід до наступного вузла
        delete temp; // Видалення поточного вузла
    }

    return 0; // Повернення 0 для позначення успішного завершення програми
}

/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation benchmark
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static long long m = 1 << 31;
static long long a = 1103515245;
static long long c = 12345;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * @param:  data  - numeric, who's need to add in the linked list
 * @return: Node* - Node, which we just added
 * @note:   function to create a new list item
 * @see:    https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA#:~:text=%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%B5%20%D0%BE%D0%B4%D0%BD%D0%BE%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D0%BE%D0%B3%D0%BE%20%D1%81%D0%BF%D0%B8%D1%81%D0%BA%D0%B0.-,%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BA%D0%B0,-%D0%9E%D1%87%D0%B5%D0%B2%D0%B8%D0%B4%D0%B5%D0%BD%20%D1%81%D0%BB%D1%83%D1%87%D0%B0%D0%B9%2C%20%D0%BA%D0%BE%D0%B3%D0%B4%D0%B0
 */
Node *createNode(int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Exception:\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @param: head - pointer, who's the first element of the list, also called the head.
 * @param: data - numeric, who's need to add in the linked list
 * @note:  Function to add an element to a list
 * @see:   https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA#:~:text=%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%B5%20%D0%BE%D0%B4%D0%BD%D0%BE%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D0%BE%D0%B3%D0%BE%20%D1%81%D0%BF%D0%B8%D1%81%D0%BA%D0%B0.-,%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BA%D0%B0,-%D0%9E%D1%87%D0%B5%D0%B2%D0%B8%D0%B4%D0%B5%D0%BD%20%D1%81%D0%BB%D1%83%D1%87%D0%B0%D0%B9%2C%20%D0%BA%D0%BE%D0%B3%D0%B4%D0%B0
 */
void append(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Функция для вывода списка
void printList(Node *head) {
    Node *currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

// Вспомогательная функция для разделения списка
Node *partitionList(Node *head, Node *tail) {
    int pivot = tail->data;
    Node *i = head;
    Node *j = head;
    while (j != tail) {
        if (j->data <= pivot) {
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
            i = i->next;
        }
        j = j->next;
    }
    int temp = i->data;
    i->data = tail->data;
    tail->data = temp;
    return i;
}

// Функция для быстрой сортировки связного списка
void quickSortList(Node *head, Node *tail) {
    if (head != tail && head != NULL && tail != NULL && head != tail->next) {
        Node *currentNode = partitionList(head, tail);
        quickSortList(head, currentNode);
        quickSortList(currentNode->next, tail);
    }
}

// Функция для быстрой сортировки массива
void quickSortArray(int arr[], int low, int high) {
    if (low < high) {
        int i = low, j = high, pivot = arr[low];
        while (i < j) {
            while (arr[i] <= pivot && i <= high) {
                i++;
            }
            while (arr[j] > pivot && j >= low) {
                j--;
            }
            if (i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[j];
        arr[j] = arr[low];
        arr[low] = temp;
        quickSortArray(arr, low, j - 1);
        quickSortArray(arr, j + 1, high);
    }
}

long long glibcGeneratorByGcc(long long seed) {
    return (a * seed + c) % m;
}

void fillArrayAndList(int *arr, Node **node, size_t n) {
    long long seed = 1 >> 31;

    for (int i = 0; i < n; i++) {
        seed = glibcGeneratorByGcc(seed);
        arr[i] = seed;
        append(node, seed);
    }
}

void delegatingAllOperations(int n) {
    int *array = (int *) malloc(n * sizeof(int));
    Node* listHead = NULL;
    fillArrayAndList(array, &listHead, n);
}

int main() {
    int arr10[10];
    Node *listHead10 = NULL;
    size_t size = sizeof(arr10) / sizeof(int);
    fillArrayAndList(arr10, &listHead10, size);

//
//    // Вывод исходных данных
//    printf("Current array: ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", arr10[i]);
//    }
//    printf("\n");
//
//    printf("Current list: ");
//    printList(listHead10);
//
//    // Сортировка массива и списка с использованием быстрой сортировки
//    quickSortArray(arr10, 0, 9);
//    quickSortList(listHead10, NULL);
//
//    // Вывод отсортированных данных
//    printf("Sorted array: ");
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", arr10[i]);
//    }
//    printf("\n");
//
//    printf("Sorted list: ");
//    printList(listHead10);
//
    return 0;
}
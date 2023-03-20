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
 * @param: head  - pointer, who's the first element of the list, also called the head.
 * @param: value - numeric, who's need to add in the linked list
 * @note:  Function to add an element to a list
 * @see:   https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA#:~:text=%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%B5%20%D0%BE%D0%B4%D0%BD%D0%BE%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D0%BE%D0%B3%D0%BE%20%D1%81%D0%BF%D0%B8%D1%81%D0%BA%D0%B0.-,%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BA%D0%B0,-%D0%9E%D1%87%D0%B5%D0%B2%D0%B8%D0%B4%D0%B5%D0%BD%20%D1%81%D0%BB%D1%83%D1%87%D0%B0%D0%B9%2C%20%D0%BA%D0%BE%D0%B3%D0%B4%D0%B0
 */
void insert(struct Node** head, int value)
{
    // Create dynamic node
    struct Node* node
            = (struct Node*)malloc(sizeof(struct Node));
    if (node == NULL) {
        // checking memory overflow
        printf("Memory overflow\n");
    }
    else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        }
        else {
            struct Node* temp = *head;

            // finding last node
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // adding node at last position
            temp->next = node;
        }
    }
}

// Displaying linked list element
void display(struct Node* head)
{
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node* temp = head;
    printf("\n Linked List :");
    while (temp != NULL) {
        printf("  %d", temp->data);
        temp = temp->next;
    }
}

// Finding last node of linked list
struct Node* last_node(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

// We are Setting the given last node position to its proper
// position
struct Node* partition(struct Node* first, struct Node* last)
{
    // Get first node of given linked list
    struct Node* pivot = first;
    struct Node* front = first;
    int temp = 0;
    while (front != NULL && front != last) {
        if (front->data < last->data) {
            pivot = first;

            // Swapping  node values
            temp = first->data;
            first->data = front->data;
            front->data = temp;

            // Visiting the next node
            first = first->next;
        }

        // Visiting the next node
        front = front->next;
    }

    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    return pivot;
}



// Функция для вывода массива
void printArray(int *arr, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
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
//        append(node, seed);
//        push(node, seed);
    }
}

void delegatingAllOperations(int n) {
    int *array = (int *) malloc(n * sizeof(int));
    Node *listHead = NULL;

    fillArrayAndList(array, &listHead, n);

    printArray(array, n);
//    printList(listHead);

    quickSortArray(array, 0, n - 1);
    quickSortList(listHead, NULL);

    printArray(array, n);
//    printList(listHead);

    free(array);
    free(listHead);
}

int main() {
    delegatingAllOperations(10);

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
/**
 * @author:  https://github.com/Ossowitz
 * @author:  https://t.me/DispatcherServlet
 * @version: 1.0
 * TODO: implementation benchmark
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EXCEPTION                   "\033[1;31m%s\033[0m\n"
#define STATELESS                           "\033[1;32m%s\033[0m\n"
#define MEMORY_OVERFLOW_EXCEPTION           "Memory overflow"

struct Node {
    int data;
    struct Node *next;
};

/**
 * @param: head  - pointer, who's the first element of the list, also called the head.
 * @param: value - numeric, who's need to add in the linked list
 * @note:  Function to add an element to a list
 * @see:   https://neerc.ifmo.ru/wiki/index.php?title=%D0%A1%D0%BF%D0%B8%D1%81%D0%BE%D0%BA#:~:text=%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80%D0%B5%20%D0%BE%D0%B4%D0%BD%D0%BE%D1%81%D0%B2%D1%8F%D0%B7%D0%BD%D0%BE%D0%B3%D0%BE%20%D1%81%D0%BF%D0%B8%D1%81%D0%BA%D0%B0.-,%D0%92%D1%81%D1%82%D0%B0%D0%B2%D0%BA%D0%B0,-%D0%9E%D1%87%D0%B5%D0%B2%D0%B8%D0%B4%D0%B5%D0%BD%20%D1%81%D0%BB%D1%83%D1%87%D0%B0%D0%B9%2C%20%D0%BA%D0%BE%D0%B3%D0%B4%D0%B0
 */
void add(struct Node **head, int value) {
    // Create dynamic node
    struct Node *node
            = (struct Node *) malloc(sizeof(struct Node));
    if (node == NULL) {
        // checking memory overflow
        printf(STATELESS,
               MEMORY_OVERFLOW_EXCEPTION
        );
    } else {
        node->data = value;
        node->next = NULL;
        if (*head == NULL) {
            *head = node;
        } else {
            struct Node *temp = *head;

            // finding last node
            while (temp->next != NULL) {
                temp = temp->next;
            }

            // adding node at last position
            temp->next = node;
        }
    }
}

/**
 * @param: head - pointer to the beginning of a linear list
 * @note: function, if there are problems and there is a need to test the program
 */
void displayLinkedList(struct Node *head) {
    if (head == NULL) {
        printf("Empty linked list");
        return;
    }
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * @param:  head - pointer to the beginning of a linear list
 * @return: finding last node of linked list
 */
struct Node *findLastNode(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

/**
 * @param:  first - pointer to the first element of the linked list
 * @param:  last  - pointer to the last element of the linked list
 * @return: In the partition function, the last element is considered a pivot
 * @see:    https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
 */
struct Node *partition(struct Node *first, struct Node *last) {
    // Get first node of given linked list
    struct Node *pivot = first;
    struct Node *front = first;
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

/**
 * @param: first - pointer to the first element of the linked list
 * @param: last  - pointer to the last element of the linked list
 * @note:  Performing quick sort in  the given linked list
 * @see:   https://www.geeksforgeeks.org/quicksort-on-singly-linked-list/
 */
void quickSortLinkedList(struct Node *first, struct Node *last) {
    if (first == last) {
        return;
    }
    struct Node *pivot = partition(first, last);

    if (pivot != NULL && pivot->next != NULL) {
        quickSortLinkedList(pivot->next, last);
    }

    if (pivot != NULL && first != pivot) {
        quickSortLinkedList(first, pivot);
    }
}

/**
 * @param: arr  - array
 * @param: size - size of array
 * @note: function, if there are problems and there is a need to test the program
 */
void printArray(int *arr, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

/**
 * @param   a - numeric
 * @param   b - numeric
 * @return: compare function to sort in reverse order
 */
int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

/**
 * @param: arr  - array, which we are going to sort
 * @param: low  - zero index
 * @param: high - last index
 * @note:  https://www.programiz.com/dsa/quick-sort
 */
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

/**
 * @param:  seed - numeric, initial value in LKG
 * @return: pseudo-random number
 * @note:   https://ru.wikipedia.org/wiki/%D0%9B%D0%B8%D0%BD%D0%B5%D0%B9%D0%BD%D1%8B%D0%B9_%D0%BA%D0%BE%D0%BD%D0%B3%D1%80%D1%83%D1%8D%D0%BD%D1%82%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4#:~:text=glibc%20(-,used%20by,-GCC)%5B10
 */
long long glibcGeneratorByGcc(long long seed) {
    long long m = 1 << 31;
    long long a = 1103515245;
    long long c = 12345;
    return (a * seed + c) % m;
}

/**
 * @param: arr  - array
 * @param: head - pointer to the beginning of a linear list
 * @param: n    - numeric, which is needed to indicate how much to fill the data structure
 * @note:  a function that fills an array and a linear list with random numbers
 */
void fillArrayAndLinkedList(int *arr, struct Node **head, size_t n) {
    long long seed = 1 >> 31;

    for (int i = 0; i < n; i++) {
        seed = glibcGeneratorByGcc(seed);
        arr[i] = seed;
        add(head, seed);
    }
}

/**
 * @param: head - pointer to the beginning of a linear list
 * @note:  reverse linked list
 */
void reverseList(struct Node** head) {
    struct Node* current = *head;
    struct Node* prev = NULL;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

/**
 * @param: n - data structure size (array or linear list)
 * @param: i - operation ID: 1 - usualSort(), 2 - doubleSort(), 3 - descSort()
 * @note: the function to which we delegate the sorting
 */
void delegatingAllOperations(int n, int i) {
    int *array = (int *) malloc(n * sizeof(int));
    struct Node *head = NULL;

    fillArrayAndLinkedList(array, &head, n);

    if (i == 1) {
        clock_t start = clock();
        quickSortArray(array, 0, n - 1);
        clock_t end = clock();
        double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("Array - \033[1;32m%d\033[0m: %lf sec\n", n, elapsed);
        free(array);

        start = clock();
        quickSortLinkedList(head, findLastNode(head));
        end = clock();
        elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("List - \033[1;32m%d\033[0m: %lf sec\n\n", n, elapsed);
        free(head);
    } else if (i == 2) {
        quickSortArray(array, 0, n - 1);
        clock_t start = clock();
        quickSortArray(array, 0, n - 1);
        clock_t end = clock();
        double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("Array - \033[1;32m%d\033[0m: %lf sec\n", n, elapsed);
        free(array);

        quickSortLinkedList(head, findLastNode(head));
        start = clock();
        quickSortLinkedList(head, findLastNode(head));
        end = clock();
        elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("List - \033[1;32m%d\033[0m: %lf sec\n\n", n, elapsed);
        free(head);
    } else if (i == 3) {
        // Сортировка массива в обратном порядке
        qsort(array, n, sizeof(int), compare);
        clock_t start = clock();
        quickSortArray(array, 0, n - 1);
        clock_t end = clock();
        double elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("Array - \033[1;32m%d\033[0m: %lf sec\n", n, elapsed);
        free(array);

        reverseList(&head);
        start = clock();
        quickSortLinkedList(head, findLastNode(head));
        end = clock();
        elapsed = (double) (end - start) / CLOCKS_PER_SEC;
        printf("List - \033[1;32m%d\033[0m: %lf sec\n\n", n, elapsed);
        free(head);
    }
}

/**
 * @note: usual quicksort
 * @note: we delegate the execution of the sort itself to another function
 */
void usualSort() {
    printf(EXCEPTION,
           "Usual sort:"
    );
    for (int i = 0, n = 10; i < 9; i++, n *= 10) {
        delegatingAllOperations(n, 1);
    }
}

/**
 * @note: sorting an already sorted data structure
 * @note: we delegate the execution of the sort itself to another function
 */
void doubleSort() {
    printf(EXCEPTION,
           "Double sort:"
    );
    for (int i = 0, n = 10; i < 9; i++, n *= 10) {
        delegatingAllOperations(n, 2);
    }
}

/**
 * @note: sorting a data structure that was previously sorted in reverse order
 * @note: we delegate the execution of the sort itself to another function
 */
void descSort() {
    printf(EXCEPTION,
           "Desc sort:"
    );
    for (int i = 0, n = 10; i < 9; i++, n *= 10) {
        delegatingAllOperations(n, 3);
    }
}

/**
 * @note: usualSort()  - usual quicksort
 * @note: doubleSort() - sorting an already sorted data structure
 * @note: descSort()   - sorting a data structure that was previously sorted in reverse order
 */
int main() {

    usualSort();
    doubleSort();
    descSort();

    return 0;
}
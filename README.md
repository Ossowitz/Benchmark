# Quick sort benchmark

## Принцип работы быстрой сортировки

Пусть дана некоторая последовательность чисел, длиной **n**. Необходимо отсортировать её в порядке неубывания.

*Суть быстрой сортировки заключается в том, чтобы выбрать точку опоры и разместить все числа, меньшие её слева, а
большие - справа.

1. Необходимо выбрать точку опоры и разделить массив на подмассивы таким образом, чтобы числа меньше опорного оказались слева, а больше - справа.
2. Левый и правый подмассивы тоже разделяются с использованием того же подхода, пока каждый подмассив не будет содержать один элемент.
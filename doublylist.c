
#include <stdio.h>

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int temp;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n)
{
    int i, temp;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    for (i = n - 1; i > 0; i--)
    {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Invalid number of elements.\n");
        return 0;
    }

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    heapSort(a, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}
-----------------------

#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize()
{
    int i;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert(int key)
{
    int index, i, pos;

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        pos = (index + i) % SIZE;

        if (hashTable[pos] == key)
        {
            printf("Key already exists.\n");
            return;
        }

        if (hashTable[pos] == -1)
        {
            hashTable[pos] = key;
            printf("Key inserted successfully.\n");
            return;
        }
    }

    printf("Hash table is full.\n");
}

void search(int key)
{
    int index, i, pos;

    index = key % SIZE;

    for (i = 0; i < SIZE; i++)
    {
        pos = (index + i) % SIZE;

        if (hashTable[pos] == key)
        {
            printf("Key found at index %d.\n", pos);
            return;
        }

        if (hashTable[pos] == -1)
            break;
    }

    printf("Key not found.\n");
}

void display()
{
    int i;

    printf("\nHash Table:\n");

    for (i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : Empty\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

int main()
{
    int choice, key;

    initialize();

    do
    {
        printf("\n1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);

                if (key < 0)
                    printf("Invalid key.\n");
                else
                    insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);

                if (key < 0)
                    printf("Invalid key.\n");
                else
                    search(key);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

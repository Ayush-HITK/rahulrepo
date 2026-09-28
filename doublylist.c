#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

/* Create a new list */
void create()
{
    int n, i, x;
    struct node *newnode, *temp;

    head = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &x);

        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

/* Print the list */
void printList()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/* Insert at first */
void insertFirst()
{
    int x;
    struct node *newnode;

    printf("Enter data: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

/* Insert at last */
void insertLast()
{
    int x;
    struct node *newnode, *temp;

    printf("Enter data: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Insert at given position */
void insertPosition()
{
    int x, pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1)
    {
        insertFirst();
        return;
    }

    printf("Enter data: ");
    scanf("%d", &x);

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

/* Insert after given data */
void insertAfterData()
{
    int x, value;
    struct node *temp, *newnode;

    printf("Enter data after which to insert: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Data not found.\n");
        return;
    }

    printf("Enter new data: ");
    scanf("%d", &x);

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;

    newnode->prev = temp;
    newnode->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}

/* Delete first */
void deleteFirst()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

/* Delete last */
void deleteLast()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

/* Delete from given position */
void deletePosition()
{
    int pos, i;
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

/* Delete given data */
void deleteData()
{
    int value;
    struct node *temp;

    printf("Enter data to delete: ");
    scanf("%d", &value);

    temp = head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Data not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

/* Count elements */
void count()
{
    int c = 0;
    struct node *temp = head;

    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    printf("Number of elements = %d\n", c);
}

/* Search presence */
void searchPresence()
{
    int value;
    struct node *temp = head;

    printf("Enter data to search: ");
    scanf("%d", &value);

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Data is present.\n");
            return;
        }
        temp = temp->next;
    }

    printf("Data is not present.\n");
}

/* Find position */
void searchPosition()
{
    int value, pos = 1;
    struct node *temp = head;

    printf("Enter data to search: ");
    scanf("%d", &value);

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Data found at position %d.\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Data not found.\n");
}

/* Count occurrences */
void searchCount()
{
    int value, c = 0;
    struct node *temp = head;

    printf("Enter data to search: ");
    scanf("%d", &value);

    while (temp != NULL)
    {
        if (temp->data == value)
            c++;

        temp = temp->next;
    }

    printf("Data occurs %d time(s).\n", c);
}

/* Sort the list */
void sortList()
{
    struct node *i, *j;
    int temp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
}

/* Reverse the list */
void reverseList()
{
    struct node *temp = NULL;
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("List reversed successfully.\n");
}

/* Main menu */
int main()
{
    int choice;

    do
    {
        printf("\n========== DOUBLY LINKED LIST ==========\n");
        printf("1.  Create a new list\n");
        printf("2.  Print the list\n");
        printf("3.  Insert at first\n");
        printf("4.  Insert at last\n");
        printf("5.  Insert at given position\n");
        printf("6.  Insert after given data\n");
        printf("7.  Delete first node\n");
        printf("8.  Delete last node\n");
        printf("9.  Delete from given position\n");
        printf("10. Delete given data\n");
        printf("11. Count elements\n");
        printf("12. Search - Presence\n");
        printf("13. Search - Position\n");
        printf("14. Search - Number of occurrences\n");
        printf("15. Sort the list\n");
        printf("16. Reverse the list\n");
        printf("17. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            printList();
            break;

        case 3:
            insertFirst();
            break;

        case 4:
            insertLast();
            break;

        case 5:
            insertPosition();
            break;

        case 6:
            insertAfterData();
            break;

        case 7:
            deleteFirst();
            break;

        case 8:
            deleteLast();
            break;

        case 9:
            deletePosition();
            break;

        case 10:
            deleteData();
            break;

        case 11:
            count();
            break;

        case 12:
            searchPresence();
            break;

        case 13:
            searchPosition();
            break;

        case 14:
            searchCount();
            break;

        case 15:
            sortList();
            break;

        case 16:
            reverseList();
            break;

        case 17:
            printf("Program terminated.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }

    } while (choice != 17);

    return 0;
}
// -- -- -- -- -- -- -- -- -- -- -- --2nd one-- -- -- -- -- -- -- -- -- -- --
#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp, swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}

void insertionSentinel(int a[], int n)
{
    int i, j, key;

    for (i = 2; i <= n; i++)
    {
        key = a[i];
        a[0] = key; // Sentinel
        j = i - 1;

        while (a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void shellSort(int a[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];

            for (j = i; j >= gap && a[j - gap] > temp; j = j - gap)
                a[j] = a[j - gap];

            a[j] = temp;
        }
    }
}

void display(int a[], int n)
{
    int i;

    printf("Sorted Array: ");

    for (i = 1; i <= n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[101], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    do
    {
        printf("\n----- SORTING MENU -----\n");
        printf("1. Modified Bubble Sort\n");
        printf("2. Insertion Sort using Sentinel\n");
        printf("3. Shell Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            bubbleSort(a + 1, n);
            display(a, n);
            break;

        case 2:
            insertionSentinel(a, n);
            display(a, n);
            break;

        case 3:
            shellSort(a + 1, n);
            display(a, n);
            break;

        case 4:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}
// -- -- -- -- -- -- -- -- -- -- -- --3rd program-- -- -- -- -- -- -- -- -- -- -- -- -- -- --
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1, j;

    for (j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
// -- -- -- -- -- -- -- -- -- -- -- --4th program-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
#include <stdio.h>

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
// -------------------------------next-------------------------------
#include <stdio.h>

int getMax(int a[], int n)
{
    int max = a[0], i;

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countingSort(int a[], int n, int exp)
{
    int output[100], count[10] = {0};
    int i;

    for (i = 0; i < n; i++)
        count[(a[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(int a[], int n)
{
    int max = getMax(a, n);
    int exp;

    for (exp = 1; max / exp > 0; exp *= 10)
        countingSort(a, n, exp);
}

int main()
{
    int a[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    radixSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
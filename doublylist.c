
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
---------------
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}
struct Node *findMin(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}
struct Node *deleteNode(struct Node *root, int key) {
    if (root == NULL)
        return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int main() {
    struct Node *root = NULL;
    int choice, data, n, i;
    while (1) {
        printf("\n1.Create BST\n2.Insertion\n3.Inorder\n4.Preorder\n5.Postorder\n6.Deletion\n7.Searching\n8.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                root = NULL;
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 3:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 5:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                root = deleteNode(root, data);
                break;
            case 7:
                printf("Enter data to search: ");
                scanf("%d", &data);
                if (search(root, data) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

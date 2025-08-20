#include <iostream>
using namespace std;
int arr[500];
int n = 0;
void createArray()
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void displayArray()
{
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insertElement()
{
    int pos, val;
    cout << "Enter position to insert: ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}
void deleteElement()
{
    int pos;
    cout << "Enter position to delete:  ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}
void linearSearch()
{
    int key, found = 0;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i << endl;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "Element not found.\n";
    }
}
int main()
{
    int choice;
    while (true)
    {
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            createArray();
            break;
        case 2:
            displayArray();
            break;
        case 3:
            insertElement();
            break;
        case 4:
            deleteElement();
            break;
        case 5:
            linearSearch();
            break;
        case 6:
            cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}

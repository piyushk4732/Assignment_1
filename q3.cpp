#include <iostream>
#include <cstdio>   // add this line

using namespace std;

int main()
{
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        printf("%d", arr[i]); // works now
    return 0;
}
// output is : 1 0 0 0 0
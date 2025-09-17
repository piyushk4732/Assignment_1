#include <iostream>
#include <queue>
using namespace std;

int main()
{
    string s;
    cout<<"enter the string: ";
    cin >> s;
    queue<char> q;
    int freq[256] = {0};
    

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        freq[c]++;
        q.push(c);
        while (!q.empty() && freq[q.front()] > 1)
            q.pop();
        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }
    return 0;
}
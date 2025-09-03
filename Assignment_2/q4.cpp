#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// (a) Concatenate
void concatenate(string a, string b) {
    cout << "Concatenated: " << a + b << endl;
}

// (b) Reverse
void reverseString(string s) {
    reverse(s.begin(), s.end());
    cout << "Reversed: " << s << endl;
}

// (c) Delete vowels
void removeVowels(string s) {
    string result = "";
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            result += c;
    }
    cout << "Without vowels: " << result << endl;
}

// (d) Sort strings
void sortStrings(string arr[], int n) {
    sort(arr, arr + n);
    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// (e) Convert uppercase to lowercase
void toLowercase(string s) {
    for (char &c : s) c = tolower(c);
    cout << "Lowercase: " << s << endl;
}

int main() {
    string s1 = "Hello", s2 = "World";
    concatenate(s1, s2);
    reverseString(s1);
    removeVowels("Beautiful");
    string arr[] = {"banana", "apple", "cherry"};
    sortStrings(arr, 3);
    toLowercase("WELCOME");

}
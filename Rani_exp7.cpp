#include <iostream>
#include <string>

using namespace std;

long repeatedString(string s, long n) {
    long count_a = 0;
    long len = s.length();
    
    for (int i = 0; i < len; ++i) {
        if (s[i] == 'a') 
            count_a++;
    }
    
    long repeats = n / len;

    long remaining = n % len;
    
    for (int i = 0; i < remaining; ++i) {
        if (s[i] == 'a') 
            count_a++;
    }
    
    return count_a + (repeats * count_a);
}

int main() {
    string s;
    long n;
    cin >> s >> n;
    
    long result = repeatedString(s, n);
    cout << result << endl;

    return 0;
}

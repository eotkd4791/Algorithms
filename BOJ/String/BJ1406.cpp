#include <iostream>
#include <list>
using namespace std;

int n;
char ord, ch;
string str;
list<char> l;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> str >> n;

    list<char>::iterator iter = l.end();
    for(int i=0; i<str.size(); i++) l.push_back(str[i]);

    while (n--) {
        cin >> ord;

        if (ord == 'L') {
            if (iter != l.begin()) iter--;
        } else if (ord == 'D') {
            if (iter != l.end()) iter++;
        } else if (ord == 'B') {
            if (iter != l.begin()) iter = l.erase(--iter);
        } else {
            cin >> ch;
            l.insert(iter, ch);
        }
    }
    for(iter=l.begin(); iter!=l.end(); iter++) cout << *iter;
    return 0;
}

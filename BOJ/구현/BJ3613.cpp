#include <iostream>
#include <cstring>
using namespace std;

string cstr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> cstr;
    char str[cstr.size() + 1];
    strcpy(str, cstr.c_str());

    int uc=0, lc=0, ub=0, other = 0;

    bool flag = false;
    bool error = false;
    for(int i=0; i<strlen(str); i++) {

        if(str[i] == '_') {
            ub++;
            if(flag) {
                error = true;
            }
            else {
                flag = true;
            }
        }
        else if(str[i] >= 97 && 122 >= str[i]) {
            flag = false;
            lc++;
        }
        else if(str[i] >= 65 && 90 >= str[i]) {
            flag = false;
            uc++;
        }
        else {
            flag = false;
            other++;
        }
    }
    if(other>0) {
        cout << "Error!" << '\n';
        return 0;
    }
    if(error || str[0] == '_' || (str[0] >= 65 && 90 >= str[0]) || str[strlen(str)-1]=='_' ){
        cout << "Error!" << '\n';
        return 0;
    }

    if(ub>0) { //C++
        if(uc>0) {
            cout << "Error!" << '\n';
            return 0;
        }
        else { //C++ => java
            bool cap = false;
            for(int i=0; i<strlen(str); i++) {
                if(str[i] == '_') {
                    cap = true;
                    continue;
                }
                if(cap) {
                    if(str[i] >= 97 && 122 >= str[i]) {
                        char ch = str[i] - 32;
                        cout << ch;
                    }

                    else cout << str[i];
                    cap = false;
                }
                else cout << str[i];
            }
        }
    }
    else {
         // Java => C++
        bool cap = false;
        for(int i=0; i<strlen(str); i++) {
            if(str[i] >= 65 && 90 >= str[i]) {
                cap = true;
            }
            if(cap) {
                char ch = str[i] + 32;
                cout << '_' << ch;
                cap = false;
            }
            else {
                cout << str[i];
            }
        }
    }
    return 0;
}
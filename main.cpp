#include <iostream>
using namespace std;
string eq;
string fin;
int fn;
int n;
int n2;
int start1 = -1;
int end1 = -1;
int start2 = -1;
int end2 = -1;
int hn = 0;

int ctn(char e) {
    if (e == '1') {
        return 1;
    }
    if (e == '2') {
        return 2;
    }
    if (e == '3') {
        return 3;
    }
    if (e == '4') {
        return 4;
    }
    if (e == '5') {
        return 5;
    }
    if (e == '6') {
        return 6;
    }
    if (e == '7') {
        return 7;
    }
    if (e == '8') {
        return 8;
    }
    if (e == '9') {
        return 9;
    }
    if (e == '0') {
        return 0;
    }
    else {
        return -1;
    }
}
// checks if a char is a operator
bool isop(char x) {
    if (x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' ||
        x == '7' || x == '8' || x == '9' || x == '0') {
        return false;
    }
    else if (x == 'x' || x == 'X' || x == '*' || x == '+' || x == '/' ||
        x == '-') {
        return true;
    }
    else {
        return false;
    }
}
bool isnu(char x) {
    if (x == '1' || x == '2' || x == '3' || x == '4' || x == '5' || x == '6' ||
        x == '7' || x == '8' || x == '9' || x == '0') {
        return true;
    }
    else if (x == 'x' || x == 'X' || x == '*' || x == '+' || x == '/' ||
        x == '-') {
        return false;
    }
    else {
        return false;
    }
}
// allow me to do exponents
int po(int var, int exp) {

    int st = 1;
    if (exp != 0) {
        for (int y = 0; y < exp; y++) {
            st = st * var;
        }
    }
    else {
        return 0;
    }
    return st;
}
int soleq(string eq) {
    n = 0;
    n2 = 0;
    int dif1 = end1 - start1;
    int dif2 = end2 - start2;

    if (dif1 != 0) {

        for (int x = start1; x < end1 + 1; x++) {

            if (x != 0) {
                n += ctn(eq[end1 - x]) * po(10, x);
                if (x == end1) {
                    break;
                }

            }
            else {
                n += ctn(eq[end1 - x]);
            }

            // cout << ctn(eq[start1 + x]) * po(10, x) << endl;
        }
    }

    else if (dif1 == 0) {
        n = ctn(eq[start1]);
    }



    if (dif2 != 0) {
        for (int x = start2; x < end2 + 1; x++) {

            if (hn != 0) {

                n2 += ctn(eq[end2 - hn]) * po(10, hn);
                if (x == end2) {
                    break;
                }
                hn++;

            }
            else {
                n2 += ctn(eq[end2 - hn]);
                hn++;
            }

        }
    }


    else if (dif2 == 0) {
        n2 = ctn(eq[start2]);
    }
    if (eq[(start2 + end1) / 2] == 'x' || eq[(start2 + end1) / 2] == 'X' ||
        eq[(start2 + end1) / 2] == '*') {
        return n * n2;
        
    }
    else if (eq[(start2 + end1) / 2] == '+') {
        
        return n + n2;
    }
    else if (eq[(start2 + end1) / 2] == '/') {
        
        return n / n2;
    }
    else if (eq[(start2 + end1) / 2] == '-') {
        
        return n - n2;
    }
    else {
        return 0;
    }
}
// setup solving the equation
void calculate() {
    start1 = -1;
    end1 = -1;
    start2 = -1;
    end2 = -1;
    cin >> eq;

    for (int i = 0; i < eq.length(); i++) {
        if (isop(eq[i]) == false) {
            int ch = i;

            do {

                ch++;
                if (ch == eq.length()) {
                    break;
                }
                // solve the equation

                for (int b = i; b < eq.length(); b++) {
                    if (isop(eq[i]) == false) {
                        if (start1 == -1) {
                            start1 = i;
                        }
                        if (isop(eq[i += 1]) == true && end1 == -1) {
                            i--;
                            end1 = i;
                            i += 2;
                        }
                        if (start1 != -1 && end1 != -1 && start2 == -1) {
                            start2 = i;
                        }
                        if (isop(eq[i]) == true && end2 == -1) {
                            i--;
                            end2 = i;
                        }
                        else if (end2 == -1 && start1 != -1 && end1 != -1 &&
                            start2 != -1) {
                            end2 = eq.length();
                            end2 -= 1;
                        }
                    }
                }
            } while (isop(eq[ch]) == false && ch != eq.length());
        }
    }

    cout << soleq(eq);
}
int main() { 
    calculate();
    cout << endl;
    for(int t = 1; t > 0;) {
        calculate();
        cout << endl;
        t = 1;
    } 
}
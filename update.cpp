#include <iostream>
using namespace std;
string eq;

// allow me to do exponents
int po(float var, float exp) {

  int st = 1;
  if (exp != 0) {
    for (float y = 0; y < exp; y++) {
      st = st * var;
    }
  } else {
    return 1;
  }
  return st;
}


int find(int start) {
  for (int i = 0; i < eq.length(); i++){
    if (eq[i] == 'x' || eq[i] == '+' ||eq[i] == '/' || eq[i] == '-' || eq[i] == '^'|| eq[i] == '#') {
      return i;
    }
  }
  return -1;
}
int sqrt(float var) {
  
}


int main() {
  cout << po(9,.5);
  cin >> eq;
  float int1 = stof(eq.substr(0,find(0)));
  float int2 = stof(eq.substr(find(0)+1,eq.length()));
  if (eq[find(0)] == 'x' || eq[find(0)] == 'X' || eq[find(0)] == '*') {
    cout << (int1*int2);
  }
  else if (eq[find(0)] == '+') {
    cout << (int1+int2);
  }
  else if (eq[find(0)] == '-') {
    cout << (int1-int2);
  }
  else if (eq[find(0)] == '/') {
    cout << int1/int2;
  }
  else if (eq[find(0)] == '^') {
    cout << po(int1,int2);
  }
  else if (eq[find(0)] == '#') {
      cout << sqrt(int1);
  }
  else if(find(0) == -1){
    cout << "Error 1 - Invalid Input";
  }
}

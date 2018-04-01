#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string reverse_bin (string bin){
  string bin2 = "";
  for (int i=bin.size()-1; i>=0; i--){
    bin2+=bin[i];
  }
  return bin2;
}

string first (int num){
  string a = "";
  while (num>=1){
    if (num%2==0)
      a+='0';
    else
      a+='1';
    num/=2;
  }
  return reverse_bin (a);
}

long long int second (int num) {
  int sum = 0, i = 0;
  while (num>=1){
    sum+=pow(2, i)*(num%10);
    num/=10;
    i++;
  }
  return sum;
}

int main() {
  int ask, num;
  
  cout << "Which conversion do you want?\nWrite 0 for Decimal to Binary and 1 for Binary to Decimal: ";
  cin >> ask;
  
  cout << "Write the integer that you want to convert: ";
  cin >> num;
  
  if (ask==0)
    cout << "Your decimal number in binary is: " << first(num) << "\n";
  else
    cout << "Your binary number in decimal is: " << second(num) << "\n";
  
  return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>

struct S {
  unsigned int b : 12;
};

using namespace std;

int main()
{
  std::ifstream file;
  file.open("diagnostic-report.txt");

  std::string contents;

  if (file.is_open()) {
    int zero[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int lines = 1000;
    int gamma[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int epsilon[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int g = 0;
    int e = 0;
    while (file) {
      int i = 0;
      file >> contents;
      while ( i <= 11) {
        if (contents[i] != '1') {
          zero[i]++;
        }
        i++;
      }
    }
    for(int j = 0; j < 12; j++) {
      std::cout << zero[j];
      std::cout << "\n";
      if (zero[j] > (lines / 2)) {
        gamma[j] = 0;
        epsilon[j] = 1;
      } else {
        gamma[j] = 1;
        epsilon[j] = 0;
      }
    }
    for (int k = 11; k >= 0; k--) {
      if(gamma[k] == 1) {
        g += pow(2, (11-k));
      }
      if(epsilon[k] == 1) {
        e += pow(2, (11-k));
      }
    }
    std::cout << g;
    std:: cout << "\n";
    std::cout << e;
  }
  
  return 0;
}
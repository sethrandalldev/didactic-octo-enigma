#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <math.h>
#include <vector>

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
    std::vector<string> v1;
    std::vector<string> v2;

    while (file) {
      int i = 0;
      file >> contents;
      while (i <= 11) {
        if (contents[i] != '1') {
          zero[i]++;
        }
        i++;
      }
      v1.push_back(contents);
      v2.push_back(contents);
    }
    for(int j = 0; j < 12; j++) {
      if (zero[j] > (lines / 2)) {
        gamma[j] = 0;
        epsilon[j] = 1;
      } else {
        gamma[j] = 1;
        epsilon[j] = 0;
      }


      std::cout << v1.size() << "\n";
      if (v1.size() != 1) {
        for (int n = 0; n < v1.size(); n++) {
          int c = v1[n][j] - 48;
          std::cout << "c: " << c << "\n";
          if (c != gamma[j]) {
            v1.erase(v1.begin() + n);
            n--;
          }
        }
      } else {
        std::cout << "v1 = { ";
        for (string n : v1) {
          std::cout << n << ", ";
        }
        std::cout << "}; \n";
      }
      



      if (v2.size() != 1) {
        for (int n = 0; n < v2.size(); n++) {
          int c = v2[n][j] - 48;
          if (c == gamma[j]) {
            v2.erase(v2.begin() + n);
            n--;
          }
        }
      } else {
        std::cout << "v2 = { ";
        for (string n : v2) {
          std::cout << n << ", ";
        }
        std::cout << "}; \n";
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
    std::cout << "g: " << g;
    std:: cout << "\n";
    std::cout << "e: " << e;
    std:: cout << "\n";



        std::cout << "v1 = { ";
        for (string n : v1) {
          std::cout << n << ", ";
        }
        std::cout << "}; \n";

    std::cout << "v2 = { ";
        for (string n : v2) {
          std::cout << n << ", ";
        }
        std::cout << "}; \n";
  }
  return 0;
}

int getMostCommon(std::vector<string> v, int position) {
  int zeros = 0;
  for (int i = 0; i < v.size(); i++) {
    int c = v[i][position] - 48;
    if (c == 0) {
      zeros++;
    }
  }
  return zeros > (v.size() / 2) ? 0 : 1;
}

std::vector<string> removeElementsByPosition(std::vector<string> v, int mostCommon, int position, bool most) {
  for (int i = 0; i < v.size(); i++) {
    int c = v[i][position] - 48;
    if (most) {
      if (c != mostCommon) {
        v.erase(v.begin() + i);
      }
    } else {
      if (c == mostCommon) {
        v.erase(v.begin() + 1);
      }
    }
  }
  return v;
}
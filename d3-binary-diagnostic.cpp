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

void printVecotr(std::vector<string> v, string name) {
  std::cout << name << " = { ";
  for (string n : v) {
    std::cout << n << ", ";
  }
  std::cout << "}; \n";
}

int getMostCommon(std::vector<string> v, int position) {
  int zeros = 0;
  int ones = 0;
  for (int i = 0; i < v.size(); i++) {
    int c = v[i][position] - '0';
    if (c == 0) {
      zeros++;
    } else {
      ones++;
    }
  }
  return ones >= zeros ? 1 : 0;
}

int getLeastCommon(std::vector<string> v, int position) {
  int zeros = 0;
  int ones = 0;
  for (int i = 0; i < v.size(); i++) {
    int c = v[i][position] - '0';
    if (c == 0) {
      zeros++;
    } else {
      ones++;
    }
  }
  return zeros <= ones ? 0 : 1;
}

std::vector<string> removeElementsByPosition(std::vector<string> v, int comparison, int position) {
  int i = 0;
  int c = v[i][position] - '0';
  int loops = 0;
  while (i < v.size() && (loops < v.size())) {
    if (c != comparison) {
      v.erase(v.begin() + i);
    } else {
      i++;
    }
    c = v[i][position] - '0';
    i++;
  }
  return v;
}

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

      std::cout << "before: " << v1.size() << "\n";
      if (v1.size() != 1) {
        v1 = removeElementsByPosition(v1, getMostCommon(v1, j), j);
      } else {
        std::cout << "v1 = { ";
        for (string n : v1) {
          std::cout << n << ", ";
        }
        std::cout << "}; \n";
      }
      std::cout << "after: " << v1.size() << "\n";

    std::cout << "v2 = { ";
    for (string n : v2) {
      std::cout << n << ", ";
    }
    std::cout << "}; \n";

      if (v2.size() != 1) {
        v2 = removeElementsByPosition(v2, getLeastCommon(v2, j), j);
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


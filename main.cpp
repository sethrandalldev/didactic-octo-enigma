#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  std::ifstream file;
  file.open("direction.txt");

  std::string contents;

  if (file.is_open()) {
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    string direction = "";
    while (file) {
      file >> contents;
      
      if (direction != "") {
        if (direction == "forward") {
          horizontal += stoi(contents);
          depth += (aim * stoi(contents));
        } else if (direction == "up") {
          aim -= stoi(contents);
        } else {
          aim += stoi(contents);
        }
        direction = "";
      } else {
        direction = contents;
      }
    }
    std::cout << (horizontal * depth);
  }
  
  return 0;
}
#include <string>
#include <iostream>

void Output() {
  std::cout << std::endl;
}

template<typename First, typename ... Strings>
void Output(First arg, const Strings&... rest) {
  std::cout << arg << " ";
  Output(rest...);
}

int main() {
  Output("I", "Am", "A");

}

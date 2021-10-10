#include <iostream>
#include <string>

#include "calculator-interface.hpp"
#include "emscripten/bind.h"

#include "utils/calculator.hpp"

using namespace emscripten;
using namespace std;

ImageEngine::ImageEngine(string n) : name(n) {}

string ImageEngine::getGreeting() {
  utils::calculator calc;
  int result = 10;
  printf("------ VALUE ------\n");
  for (int i = 0; i < 10; i++) {
    cout << "Addition: " << std::to_string(calc.addition(i, 15)) << std::endl;
    result = calc.subtraction(24, i);
    if (result < 5) {
      cout << "Difference: " << std::to_string(result) << std::endl;
    }
  }
  return "My name is " + name + " and the result is " + std::to_string(result);
}

void ImageEngine::makeSound() { cout << "bark!" << '\n'; }

EMSCRIPTEN_BINDINGS(c) {
  class_<ImageEngine>("ImageEngine")
      .constructor<string>()
      .function("makeSound", &ImageEngine::makeSound)
      .function("getGreeting", &ImageEngine::getGreeting);
}
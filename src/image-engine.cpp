#include <iostream>
#include <string>

#include "image-engine.hpp"
#include "emscripten/bind.h"

#include "utils/calculator.hpp"

using namespace emscripten;
using namespace std;

ImageEngine::ImageEngine(string n): name(n) {}

string ImageEngine::getGreeting () {
  return "My name is " + name + ", hello from C++!";
  utils::calculator calc;
    printf("------ VALUE ------\n");
    for(int i=0; i<10; i++){
        cout <<"Addition: "<<std::to_string(calc.addition(i,15))<<std::endl;
        int diffrence = calc.subtraction(24,i);
        if(diffrence<5){
            cout <<"Difference: "<<std::to_string(diffrence)<<std::endl;
        }
    }
}

void ImageEngine::makeSound () {
  cout << "bark!" << '\n';
}

EMSCRIPTEN_BINDINGS (c) {
  class_<ImageEngine>("ImageEngine")
    .constructor<string>()
    .function("makeSound", &ImageEngine::makeSound)
    .function("getGreeting", &ImageEngine::getGreeting);
}
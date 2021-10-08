#pragma once

#include <string>

using std::string;

class ImageEngine {
  string name;

  public:
    ImageEngine (string n);
    string getGreeting ();
    void makeSound ();
};
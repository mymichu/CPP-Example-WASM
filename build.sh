#!/bin/bash
conan install --profile .conan-profile/emscripten --build missing -if build .
conan build -if build -bf build .
#!/bin/bash
rm -rf build
conan install --profile .conan-profile/emscripten --build missing -if build .
conan build -if build -bf build .
#emrun --no_browser --port 8000 build/src/image-engine.html
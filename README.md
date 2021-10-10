# CPP-Example-WASM

This example compiles a cpp project into webassembly. The webassembly output can be used as a standalone executable, or you can run the webassembly within your browser.

## Build

To build this example run the following commands

1. Build Docker Container to build and serve the example

```console
docker build .devcontainer -t webassembly-build:latest
```

2. Build the application:

On Linux

```console
docker run --rm -v $PWD:/data --workdir /data -it webassembly-build:latest /bin/bash -c '${EMSDK}/emsdk activate ${EMSCRIPTEN_VERSION}; source "/opt/emsdk/emsdk_env.sh"; ./build.sh'
```

On Windows

```console
docker run --rm -v "$(pwd):/data" --workdir /data -it webassembly-build:latest /bin/bash -c '${EMSDK}/emsdk activate ${EMSCRIPTEN_VERSION}; source "/opt/emsdk/emsdk_env.sh"; ./build.sh'
```

## Run WASM Standalone with runtime

To run this example standalone install wasmer

```console
iwr https://win.wasmer.io -useb | iex
```

Then run with the following command the wasm file:

```console
wasmer run build/src/calculator-standalone.wasm
```

## Run WASM in Browser

Run the following example:

On Linux

```console
docker run -v $PWD:/data --workdir /data -p 8000:8000 webassembly-build:latest /bin/bash -c '${EMSDK}/emsdk activate ${EMSCRIPTEN_VERSION}; source "/opt/emsdk/emsdk_env.sh"; emrun --no_browser --port 8000 build/src/calculator.html'
```

On Windows

```console
docker run -v "$(pwd):/data" --workdir /data -p 8000:8000 webassembly-build:latest /bin/bash -c '${EMSDK}/emsdk activate ${EMSCRIPTEN_VERSION}; source "/opt/emsdk/emsdk_env.sh"; emrun --no_browser --port 8000 build/src/calculator.html'
```

Open the browser and go to:
http://localhost:8000/calculator.html


## Run WASM in Browser with Javascript interaction

Copy built sources to http/sources folder

```console
cp build/src/calculator-interface.* http/sources
```

build docker container
```console
docker build http/. -t webserver:latest
```

run docker container with with webserver
```console
docker run -p 9000:80 webserver:latest
```

Open the browser and go to:
http://localhost:9000

And check the console log

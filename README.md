# Project README

## Overview
- The project is a command-line version of an interactive TFighter game. Players can control characters and engage in battles using keyboard inputs.

## Features
- Command-line interface for gameplay.
- Support for Windows, Linux, WebAssembly, and Wine platforms.

## Project Structure
```
<Project>/
├── build/              # .exe files produced by Main.c
├── src/                # src code
│   ├── Main.c          # Entry point
│   └── Settings.h      # Header file for constants and structures
├── Makefile.linux      # Linux Build configuration
├── Makefile.windows    # Windows Build configuration
├── Makefile.wine       # Wine Build configuration
├── Makefile.web        # Emscripten Build configuration
└── README.md           # This file
```

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run
### Linux
To build the project on Linux:
```bash
cd <Project>
make -f Makefile.linux all
# Execute the game
./build/Main
```

### Windows
To build the project on Windows:
```cmd
cd <Project>
make -f Makefile.windows all
# Execute the game
build\Main.exe
```

### WebAssembly
To build the project for WebAssembly:
```bash
cd <Project>
make -f Makefile.web all
# Run with wasmtime or Emscripten's serve command
wasmtime build/Main.wasm
```

### Wine
To build and run the project using Wine on Linux:
```bash
cd <Project>
make -f Makefile.wine all
WINEPREFIX=~/wine64 WINEARCH=win64 wine build/Main.exe
```

Note: Ensure that the required dependencies are installed on your system before building.
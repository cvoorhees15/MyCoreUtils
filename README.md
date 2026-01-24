# MyCoreUtils

An attempt at rewriting some of the basic UNIX core utils to practice using system calls.

## Details

- **my-cat**: Concatenate and display file contents.
- **my-cp**: Copy files from source to destination.
- **my-mkdir**: Create directories.

## Requirements

- CMake (version 3.10 or higher)
- A C compiler (e.g., GCC or Clang)

## Build Instructions

1. Clone or navigate to the project directory.
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Generate build files with CMake:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   make
   ```
5. The executables (`my-cat`, `my-cp`, `my-mkdir`) will be located in the `bin/` directory.

## Usage

- `my-cat <file>`: Display the contents of `<file>`.
- `my-cp <source> <destination>`: Copy `<source>` to `<destination>`.
- `my-mkdir <directory>`: Create the directory `<directory>`.
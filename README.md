# Charlie2D testing project

# Compile Instructions
## Linux
Install cmake along with sdl2, sdl2_image, sdl2_ttf, sdl2_mixer, and sdl2_gfx

Compile
```
mkdir build
cd build
cmake ..
make
./index
```
## Windows
Download and install Cmake ([Downloads](https://cmake.org/download/))

Download and install the Mingw Compiler for 
x86_64 ([Downloads](https://github.com/niXman/mingw-builds-binaries/releases))

Extract and add the bin folder to your PATH env variable ([Guide](https://www.rose-hulman.edu/class/csse/resources/MinGW/installation.htm))

Compile
```
mkdir build
cd build
cmake -G "MinGW Makefiles" -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
cmake --build .
.\index.exe
```

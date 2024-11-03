# Charlie2D-Project-Template
The official Charlie2D Project Template

#### Clone Command:
```
git clone https://github.com/Ethanscharlie/Charlie2D-Project-Template.git GAMENAMEHERE; cd "$(basename "$_" .git)"
```

# Compile Instructions
## Linux
Install cmake

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

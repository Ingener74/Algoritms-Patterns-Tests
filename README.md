#Algorith, patterns, libraries, tests

This repository contain tests for design patterns, some boost features, Qt features and other some programming features

install dependencies
```
sudo apt-get install libboost-dev python-dev
```
build Lua
```
cd <somewhere>
git clone https://github.com/LuaDist/lua.git
cd lua
mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make
sudo make install
```

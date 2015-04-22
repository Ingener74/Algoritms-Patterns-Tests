#Алгоритмы, паттерны, тесты...

Репа для всяких тестов, проверок, для посмотреть, затестить и т. д. 

ставим зависимости
```
sudo apt-get install libboost-dev python-dev qt4-default qt4-demos qt4-designer qt4-dev-tools qt4-doc qt4-doc-html qt4-qmake qt4-qmlviewer qt4-qtconfig libjpeg8-dev libfltk1.3 libfltk1.3-dev
```
собираем Lua
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
sudo apt-get install 

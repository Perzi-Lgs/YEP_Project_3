#!/bin/bash

gcc -c enemies1.cpp -fPIC
g++ -shared -fPIC -o enemies1.so enemies1.o

gcc -c enemies2.cpp -fPIC
g++ -shared -fPIC -o enemies2.so enemies2.o

gcc -c enemies3.cpp -fPIC
g++ -shared -fPIC -o enemies3.so enemies3.o

gcc -c enemies4.cpp -fPIC
g++ -shared -fPIC -o enemies4.so enemies4.o

gcc -c enemies5.cpp -fPIC
g++ -shared -fPIC -o enemies5.so enemies5.o

gcc -c enemies6.cpp -fPIC
g++ -shared -fPIC -o enemies6.so enemies6.o

gcc -c enemies7.cpp -fPIC
g++ -shared -fPIC -o enemies7.so enemies7.o

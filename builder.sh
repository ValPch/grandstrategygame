#!/bin/bash

PTH=${0%/*}

if [ ! -d $PTH/build ]
then
  mkdir $PTH/build
fi

cd $PTH/build

cmake ..

make

mv tester.exe ../

#!/bin/bash
for x in {A..Z}; do
    mkdir $x
    touch $x/$x.cpp
    touch $x/in0
    touch $x/in1
    touch $x/in2
    touch $x/out0
    touch $x/out1
    touch $x/out2
    touch $x/compile.sh
done

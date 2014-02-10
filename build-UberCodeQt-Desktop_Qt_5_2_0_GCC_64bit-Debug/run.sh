#!/bin/bash

if [ -z "$1" ] ; then
    echo "usage: $0 binaryName"
    exit 0
fi

LD_LIBRARY_PATH=`cd ../_2RealFramework/kernel/lib && pwd`:`cd ../../../qt-solutions/qtpropertybrowser/lib/ && pwd` ./$1

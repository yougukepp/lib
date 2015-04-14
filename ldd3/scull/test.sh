#!/bin/sh

make clean
make
echo "build ok"
echo ""

./scull_unload.sh
./scull_load.sh
echo "insmod ok"
echo ""

rm -rf ./in.txt
echo "0123456789abcdef" > ./in.txt

sudo dd if=./in.txt of=/dev/scull bs=17 count=1
echo "write ok"
echo ""

sudo dd if=/dev/scull of=./out.txt bs=17 count=1
echo "read ok"
echo ""

sudo chmod 666 ./in.txt ./out.txt

diff -q ./in.txt ./out.txt

if [ 0 == $? ]; then
    echo "TEST PASS!"
else
    echo "TEST FAILLED!"
fi


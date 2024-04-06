#!/bin/bash

./build/aarch64/night-vision &
PROGRAM_PID=$!

top -b -d 1 -p $PROGRAM_PID | head -n 20 > night-vision-usage.txt

sleep 10
kill $PROGRAM_PID

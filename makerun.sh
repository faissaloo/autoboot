#!/bin/sh
make
success=$?
if [ $success -eq 0 ]; then
	PCSX2 --elf="./autoboot.elf"
fi

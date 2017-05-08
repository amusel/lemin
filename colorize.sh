#!/bin/sh

cat \
		| sed "s|-|$(echo "\033[0;32m-\033[0m")|g" \
		| sed "s|L|$(echo "\033[0;32mL\033[0m")|g" \
		| sed "s|s|$(echo "\033[0;31ms\033[0m")|g" \
		| sed "s|t|$(echo "\033[0;31mt\033[0m")|g" \
		| sed "s|a|$(echo "\033[0;31ma\033[0m")|g" \
		| sed "s|r|$(echo "\033[0;31mr\033[0m")|g" \
		| sed "s|t|$(echo "\033[0;31mt\033[0m")|g" \
		| sed "s|e|$(echo "\033[0;31me\033[0m")|g" \
		| sed "s|n|$(echo "\033[0;31mn\033[0m")|g" \
		| sed "s|d|$(echo "\033[0;31md\033[0m")|g" \
		| sed "s|c|$(echo "\033[0;31mc\033[0m")|g" \
		| sed "s|o|$(echo "\033[0;31mo\033[0m")|g" \
		| sed "s|h|$(echo "\033[0;31mh\033[0m")|g" \

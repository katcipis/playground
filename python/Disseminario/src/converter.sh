#!/bin/bash
for file in `find . -name '*.py'`
do	 	
iconv -f  latin1 -t UTF-8 -o "$file"2 "$file"
mv "$file"2 "$file"
done

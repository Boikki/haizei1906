#!/bin/bash

. 11.find_longest_string.sh

max=0
max_string=''
max_file=''
line=0

for i in $@; do
    if [[ -f $i ]]; then
        find_in_file $i
    elif [[ -d $i ]]; then
        find_in_dir $i
    fi
done

line=`grep -n "$max_string" $max_file | cut -d ":" -f 1 | tr '\n' ' '`
printf "%s is the longest string, which length is %d, \n at line %s in file %s\n" ${max_string} ${max} "${line}" ${max_file}


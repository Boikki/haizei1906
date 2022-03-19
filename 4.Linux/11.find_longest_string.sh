#!/bin/bash


function fliter() {
    types="png jpeg mp4 pdf avi"
    file_name=`basename $1`
    file_type=`echo ${file_name} | tr "." "\n" | tail -1`
    for i in ${types}; do 
        if [[ $i == ${file_type} ]]; then
            return 1
        fi
    done
    file $i | grep -q -w "text" 2>/dev/null 
    if [[ $? -ne 0 ]]; then
        return 1
    fi
    return 0
}

function find_in_file(){
    words=`cat $1 | tr -s -c "a-zA-Z" "\n"`
    for i in ${words}; do
        t_len=`echo ${#i}`
        if [[ ${t_len} -gt ${max} ]]; then
            max=${t_len}
            max_string=$i
            max_file=$1
        fi
    done
}

function find_in_dir() {
    for i in `ls -A $1`; do
        if [[ -d $1/$i ]]; then
            find_in_dir $1/$i
        else
            find_in_file $1/$i
        fi
    done
}

#!/bin/bash

declare -a prime
end=$1



for (( i=2; i<$end; i++ ));do
    if [[ ${prime[$i]}x == x ]];then
        prime[0]=$[ ${prime[0]} + 1 ]
        prime[${prime[0]}]=$i
    fi
    for (( j=1; j<=${prime[0]}; j++ ));do
        if [[ $[$i * ${prime[$j]}] -gt $end ]];then 
            break
        fi
        prime[$[ $i * ${prime[$j]} ]]=1
        if [[ $[ $i % ${prime[$j]} ] -eq 0 ]];then 
            break
        fi
    done
done

for i in `seq 1 ${prime[0]}`;do
    echo ${prime[$i]}
done



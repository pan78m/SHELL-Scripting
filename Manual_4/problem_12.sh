#! /bin/bash
# 7. Find the Largest digit from the Number.
#!/bin/bash

read -p "Enter the number of terms: " n

Largest=$n

while (($n!=0));do
    digit=$((n%10))

    if ((digit>Largest));then
        ((Largest=$digit))
    fi 
    n=$((n/10))
done

echo Largest Digit:$Largest

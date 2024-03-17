#!/bin/bash

read -p "Enter numbers (separated by spaces): " numbers

sum_odd=0
sum_even=0

IFS=' ' read -ra num_array <<< "$numbers"

for num in "${num_array[@]}"; do
    if ((num % 2 == 0)); then
        ((sum_even += num))
    else
        ((sum_odd += num))
    fi
done

echo "Sum of even numbers: $sum_even"
echo "Sum of odd numbers: $sum_odd"

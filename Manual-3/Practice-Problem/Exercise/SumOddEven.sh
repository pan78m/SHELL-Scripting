#! /bin/bash

sumOdd=0
sumEven=0

for n in 3 5 7 8 6; do
    if ((n%2 == 0)); then
        ((sumEven+=n))
    else
        ((sumOdd+=n))
    fi
done

echo "Even sum=$sumEven"
echo "Odd sum=$sumOdd"

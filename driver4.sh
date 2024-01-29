#!/bin/bash

# Define an array of values for X
values=(10 25 50 75 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000)

# Loop through each value of X
for value in "${values[@]}"; do
    # Run the executable multiple times
    for ((i=1; i<=10; i++)); do
        echo "Running ./project_${value}.exe, iteration $i"
        ./project_${value}.exe
    done
    echo "Done with $value"
    echo
done

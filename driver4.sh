#!/bin/bash

# Define an array of values
values=(10 25 50 75)

for value in $(seq 100 50 950); do
    values+=($value)
done

for value in $(seq 1000 100 2000); do
    values+=($value)
done

# Define the number of iterations
iterations=5

# Loop through the values and run ./project_integrated.exe with each value and iterations as arguments
for value in "${values[@]}"; do
    echo "Running ./project_integrated.exe with arguments value=$value and iterations=$iterations"
    ./project_integrated.exe "$value" "$iterations"
done

echo "Done with all values"

#!/bin/bash

# Define an array of values (100, 200, 300, etc.)
values=(10 25 50 75 100 200 300 400 500 600 700 800 900 1000 150 250 350 450 550 650 750 850 950)

# Define the number of iterations
iterations=10

# Loop through the values and run ./project_integrated.exe with each value and iterations as arguments
for value in "${values[@]}"; do
    echo "Running ./project_integrated.exe with arguments value=$value and iterations=$iterations"
    ./project_integrated.exe "$value" "$iterations"
done

echo "Done with all values"

#!/bin/bash

for file in maps_loic/*.ber; do
    echo "Processing $file..."
    ./so_long "$file"
    if [ $? -ne 0 ]; then
        echo -e "\nError occurred while processing $file. Continuing to the next file."
    fi
done

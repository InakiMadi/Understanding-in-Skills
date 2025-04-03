#!/bin/bash
count=0
for file in *; do
    if [ -f "$file" ] && [ $(stat -c %s "$file") -gt 1000000 ]; then
        ((count++))
        # echo "$file"
    fi
done
echo "Number of files >1MB: $count."
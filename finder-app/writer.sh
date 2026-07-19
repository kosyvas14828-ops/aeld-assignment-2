#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Please provide both a file path and a text string."
    exit 1
fi

writefile=$1
writestr=$2

dirpath=$(dirname "$writefile")

mkdir -p "$dirpath" 2>/dev/null || {
    echo "Error: could not create directory '$dirpath'."
    exit 1
}

echo "$writestr" > "$writefile" 2>/dev/null || {
    echo "Error: could not create file '$writefile'."
    exit 1
}

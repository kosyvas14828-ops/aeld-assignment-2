#!/bin/sh

if [ $# -ne 2 ]; then
    echo "Please provide both a directory path and a search string."
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]; then
    echo "The path '$filesdir' does not point to a valid directory."
    exit 1
fi

file_count=$(find "$filesdir" -type f | wc -l)
match_count=$(grep -R -n "$searchstr" "$filesdir" 2>/dev/null | wc -l)

echo "The number of files are $file_count and the number of matching lines are $match_count"

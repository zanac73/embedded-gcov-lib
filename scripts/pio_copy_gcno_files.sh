#!/bin/bash

# Origin and destination folders
PIO_BASE_DIR=$(pwd)/.pio
GCNO_FILES_DIR=$PIO_BASE_DIR/build
GCNO_DESTINATION_DIR=$PIO_BASE_DIR/lib/esp32/embedded-gcov/objs/

# Creates destination folder 
mkdir -p "$GCNO_DESTINATION_DIR"

echo "Copying .gcno files from $GCNO_FILES_DIR to $GCNO_DESTINATION_DIR"

# Find .gcno files e copy to destination folder
find "$GCNO_FILES_DIR" -name "*.gcno" -type f | while read -r file; do
    echo "Copy $file  to  $GCNO_DESTINATION_DIR"
    cp "$file" "$GCNO_DESTINATION_DIR"
done

echo "Success copying .gcno files!"

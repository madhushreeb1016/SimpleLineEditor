# Simple Line Editor - Help

## How to Compile

Open the terminal in the project folder and run:

`gcc -Wall -Wextra line_editor.c -o line_editor`

## How to Run

Windows:

`.\line_editor`

## Menu Options

1. Insert Line - Adds a new line to the document.
2. Delete Line - Deletes a selected line number.
3. Display Document - Displays all stored lines with their line numbers.
4. Search - Searches for text in the document.
5. Line Count / Word Count - Displays the number of lines and words.
6. Exit - Exits the editor and releases allocated memory.

## Notes

* The editor can store up to 100 lines.
* Each line can contain up to 199 characters.
* Line numbers start from 1.
* Invalid line numbers are rejected.
* The document can be displayed at any time.
* Search reports the lines containing the searched text.

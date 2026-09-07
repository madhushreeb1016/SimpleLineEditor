# Simple Line Editor in C

## Team Members

* Team Member 1
* Team Member 2

## Project Description

A simple command-line line editor developed in C. It stores document lines and provides basic editing and text-search functionality through a menu-driven interface.

## Data Structure

The project uses a dynamic array of strings.

```c
char *lines[MAX_LINES];
```

Each line is dynamically allocated using `malloc()`.

## Features

### Core Features

* Insert Line
* Delete Line
* Display Document

### Bonus Features

* Search
* Line Count / Word Count

## Technologies Used

* C
* GCC
* VS Code
* Terminal

## Compilation

```bash
gcc -Wall -Wextra line_editor.c -o line_editor
```

## Run

```bash
.\line_editor
```

## Error Handling

The program handles:

* Empty document
* Invalid line numbers
* Full document
* Memory allocation failure

## Project Structure

```text
SimpleLineEditor/
├── line_editor.c
├── README.md
└── HELP.md
```

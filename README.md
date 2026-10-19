# Introduction to C

A hands-on introduction to the C language, built on seven small example programs, their notes, a `Makefile` and a slide deck. The method is always the same: compile a program, run it, read its output, change one line, recompile, and watch what changed. The slides follow the files in order and end each one with a "try it" checkpoint. The course assumes you already know a scripting language such as Python and keeps comparing the two.

## Requirements

- A C compiler: `gcc` (Linux: `sudo apt install build-essential`; macOS: `xcode-select --install`, where `gcc` is clang; Windows: WSL, then the Linux line).
- `make`.
- Optional: AddressSanitizer (bundled with gcc and clang, `-fsanitize=address`) and `valgrind`, both used in the slides to catch memory errors; a LaTeX installation if you want to rebuild the exam PDFs.

## The working loop

1. Open a `.c` file in a text editor.
2. Compile it with warnings on: `gcc 01_basics.c -Wall -Wextra -o basics`
3. Run it: `./basics`
4. Compare the output with the slides and the comments in the source.
5. Change one line (the slides say which), go back to step 2.

Read every warning. Several programs in this course are meant to produce warnings, crashes or silently wrong output; each of those is part of a lesson. If a program compiles without warnings and runs without crashing, it is not necessarily correct.

## Repository layout

```
.
├── README.md
├── introduction_to_c.pdf             # the slide deck (58 slides, 6 parts, 8 checkpoints)
├── 01_basics.md                      # the notes for 01_basics.c
├── 01_basics.c                       # types, printing, casting, arrays, functions, pointers, structures
├── foo_test.h                        # header included by 01_basics.c
├── 02_array_pointers.c               # arr, &arr[0], &arr; arrays passed to functions
├── 03_char_strings.c                 # char, char*, char[]; string.h
├── 04_argv.c                         # command-line arguments
├── 05_write_files.c                  # writing a file
├── 06_file_lines_to_string_array.c   # reading a file line by line
├── some_text.txt                     # input file for 06
├── 07_example_malloc_realloc.c       # malloc, realloc, out-of-bounds writes
├── Makefile                          # builds basics and array_pointers
└── exercises/
    ├── exam.pdf                      # mock exam, student copy (30 min, 20 points)
    ├── exam_answer_key.pdf           # the same exam with answers and marking scheme
    ├── exam.tex                      # LaTeX source of both
    ├── pointers/                     # exercises on pointers
    └── dynamic_arrays_linked_lists/  # exercises on dynamic arrays and linked lists
```

## The programs

| File | What it covers | What to do with it |
| --- | --- | --- |
| `01_basics.md` | The notes: compiled language, types, arrays, functions, pointers, structures | Read it next to `01_basics.c` |
| `01_basics.c` | The same topics as runnable code, labelled `PRINT00` to `PRINT23` | Match every `PRINT` line to its code |
| `Makefile` | Recording the gcc commands; rebuilding only what changed | Run `make`, break it, extend it |
| `02_array_pointers.c` | `arr`, `&arr[0]` and `&arr`: one address, three types | Read the warnings, remove an `&` |
| `03_char_strings.c` | `char`, `char*` and `char[]`; `strlen`, `strcpy`, `strtol` | Uncomment a line, crash on purpose |
| `04_argv.c` | Command-line arguments | Run it with different arguments |
| `05_write_files.c` | `fopen` in `"w"` mode, `fprintf`, `fclose` | Run it, then look at `file.txt` |
| `06_file_lines_to_string_array.c` | `fopen` in `"r"` mode, `fgets` into a 2D `char` array | Create `some_text.txt` first |
| `07_example_malloc_realloc.c` | `malloc`, `realloc` and out-of-bounds writes | See a warning, a crash and a silent bug |

## Building and running

The `Makefile` builds the first two programs with `-std=c11 -Wall -Wextra -O3 -march=native`:

```sh
make                  # builds basics and array_pointers
make basics           # one target only
make                  # again: "make: 'all' is up to date."
touch 02_array_pointers.c && make   # rebuilds only what changed
```

The other programs are compiled by hand, with the same warnings on:

```sh
gcc 03_char_strings.c -Wall -Wextra -o char_strings && ./char_strings
gcc 04_argv.c -Wall -Wextra -o argv && ./argv hello world 42
gcc 05_write_files.c -Wall -Wextra -o write_files && ./write_files && cat file.txt
gcc 06_file_lines_to_string_array.c -Wall -Wextra -o file_lines && ./file_lines
gcc 07_example_malloc_realloc.c -Wall -Wextra -O3 -o malloc_realloc && ./malloc_realloc
```

Things to know before running them:

- `01_basics.c` includes `foo_test.h`, which must sit in the same folder.
- `06_file_lines_to_string_array.c` reads `some_text.txt` from the current folder and exits with status 1 if the file is missing (`echo $?` shows it).
- `05_write_files.c` creates `file.txt` and prints nothing on the screen.
- Keep `-O3` for `07_example_malloc_realloc.c`: its two `-Warray-bounds` warnings only appear when the optimizer is on.
- Expected warnings: unused variables in `01_basics.c`, a `%d` given a pointer and an "incompatible pointer type" in `02_array_pointers.c`, `-Wsizeof-pointer-div` in `03_char_strings.c`, `-Wmain` in `05_write_files.c`, `-Warray-bounds` in `07_example_malloc_realloc.c`. The slides explain each one.

To find the memory errors that compile and run quietly, build with AddressSanitizer:

```sh
gcc 07_example_malloc_realloc.c -g -fsanitize=address -o malloc_asan && ./malloc_asan
```

## The slides

`introduction_to_c.pdf` has six parts, one per file (or group of files): 01_basics.c with its notes, the Makefile, 02_array_pointers.c, 03_char_strings.c, 04 to 06 (arguments and files), 07_example_malloc_realloc.c. Every program is shown with its real output, and every part ends with a "try it" checkpoint: a change to make, what appears after recompiling, and why. The last slides sum up what the compiler and the operating system messages mean, what each file taught, and where to go next.

## Exercises

The `exercises/` folder holds:

- **The mock exam** on pointers, dynamic arrays and linked lists: 30 minutes, 20 points, three exercises (a pointer trace and three bugs to fix; a growable `int` vector with `realloc`; a singly linked list with `length`, `remove_first` and a use-after-free to spot). `exam.pdf` is the student copy, `exam_answer_key.pdf` adds the answers and the marking scheme. Both come from `exam.tex`:

  ```sh
  pdflatex exam.tex                                        # student copy
  pdflatex -jobname=exam_answer_key "\def\withanswers{1}\input{exam.tex}"   # answer key
  ```

- **`pointers/`**: exercises on pointers (addresses and values, dereferencing, passing by reference, pointer arithmetic).
- **`dynamic_arrays_linked_lists/`**: exercises on `malloc`, `realloc` and `free`, growable arrays, and singly linked lists.

## Further reading

The links cited in the source files: [undefined behavior](https://en.wikipedia.org/wiki/Undefined_behavior), [string literals](https://en.wikipedia.org/wiki/String_literal), [C string handling](https://en.wikipedia.org/wiki/C_string_handling#Functions), [header files](https://en.wikipedia.org/wiki/Include_directive#Header_files), [a hash table in C](https://benhoyt.com/writings/hash-table-in-c/), [malloc vs calloc](https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/), [TP : l'en-tête string.h](https://zestedesavoir.com/tutoriels/755/le-langage-c-1/1043_aggregats-memoire-et-fichiers/tp-len-tete-string-h/) (in French), and [replacing a substring](https://stackoverflow.com/questions/779875/what-function-is-to-replace-a-substring-from-a-string-in-c). The manual of every library function met here is one command away: `man 3 strtol`.

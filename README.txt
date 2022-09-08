gcc -dM -E - < /dev/null | grep STDC_VERSION

echo $?

======================
The GNU Debugger (GDB)
======================
Compile you program using the -g switch, like this:
gcc program.c -g

Then use gdb:
gdb ./a.out



https://stackoverflow.com/questions/18782608/the-logic-behind-pass-by-pointer-to-pointer-in-c

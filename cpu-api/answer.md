## Q1
child share variable values with the parent

## Q2
when the parent opens a file descriptor before `fork()`, then child and parent both read from the fd, then the content read in is not the same, the latter read content comes after the former read.  

both parent and child write to the same file.

## Q3

if to not use `wait()`, then use `SIGSTOP/SIGCONT` signal instead.
idea from `https://github.com/xxyzz/ostep-hw/tree/master/5`

## Q4
### General
note that the `exec` family functions never return, that the later code will not be executed.
comment out the others if one is to be executed.

### `execl`
execute with a list of arguments.  Since it receives a variable list of arguments, the last argument needs to be `NULL` to mark the end.  The first argument is the command itself, that it repeats the path, or it can be the command itself without the absolute path.

### `execlp`
execute with given file and executor.  The example executes a user-defined bash script by the `/bin/sh` program.

### `execle`
the `e` stands for environment

## Q5
child wait returns -1
parent wait returns the child process PID

## Q7
child process does not print out anything after closing the `stdout`

## Q8
`pipefd[2]`
`pipefd[0]` is the read end
`pipefd[1]` is the write end

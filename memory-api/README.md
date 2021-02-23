## notes

### stack memory

when return from function, the compiler deallocates the stack memory. for information to live beyond the call
invocation, store it outside the stack.

### heap memory

allocations and de-allocations are explicitly handled by the programmer.

### behavior of sizeof

if when passing a pointer to the `sizeof()`, if it is initialized as `int *x`, then `sizeof(x)` returns the constant
size of an integer pointer, not the integer array size. If it is initialized as `int x[10]`, then `sizeof(x)` returns
the size of the array, not the pointer size.

As is seen in the `sizeof_test.c`, passing pointer to `sizeof()` always results in pointer size, while it returns the
actual size of the variable is initialized as `int a[10]` or `char b[10]`.

### common mistakes on malloc and free

* forget to allocate memory

```c
char *src = "hello";
char *dst;
strcpy(dst, src);
```

* not allocating enough memory

```c
char *src = "hello";
char *dst = (char *) malloc(strlen(src)); // should add 1 for null char
strcpy(dst, src);
```

It may run without problem, but the terminating char overwrites one byte of space that the string does not own.  
Sometimes it crashes, sometimes it does not. But it is without doubt incorrect code.

* segmentation fault something wrong with the memory due to programmer's fault

> Tip: It compiled or it ran != it is correct
>
> Just because a program compiled or even ran once or many times correctly does not mean that the program is correct. A common reaction is to say "But it worked before!", and then blame the compiler, operating system, hardware, or even the professor. But the problem is usually in the code.

* forgetting to free memory this leads to memory leak, eventually leads to running out of memory, and the program has to
  restart.

note that using garbage-collected language does not solve the problem: if memory is still referenced, no garbage
collector will free it.

it's bad habit to let OS clean up allocation on program exit.

* free memory before done with it

causing dangling pointer tested by `dangling_pointer`, it turns out that it does not crash.

* free allocated memory twice double free, leading to undefined behavior, often crash program `./double_free` results in
  aborted execution.

## answer to questions

### 1. run null program

this program dereferences an integer pointer that is set to NULL. the program prompts `Segmentation fault` on execution.

### 2. run with gdb

gdb prompts: program received signal SIGSEGV, segmentation fault

### 3. run with valgrind

valgrind prompts: address 0x0 is not stacked, malloced, or recently freed.

terminating with signal 11 SIGSEGV.

### 4. exit without free malloc memory

both normal run and gdb run do not prompt with any error. running with `valgrind --leak-check=yes ./exit_without_free`
prompts memory leak message, which shows that valgrind is a better tool for memory leak check.

```text
...
==50760== HEAP SUMMARY:
==50760==     in use at exit: 40 bytes in 1 blocks
==50760==   total heap usage: 2 allocs, 1 frees, 1,064 bytes allocated
...
==50760== LEAK SUMMARY:
==50760==    definitely lost: 40 bytes in 1 blocks
==50760==    indirectly lost: 0 bytes in 0 blocks
==50760==      possibly lost: 0 bytes in 0 blocks
==50760==    still reachable: 0 bytes in 0 blocks
==50760==         suppressed: 0 bytes in 0 blocks
```

### 5. array of size 100

`./array_100`
normal run does not prompt with error.

valgrind run prompts writing to memory outside allocaiton

```text
==51200== Invalid write of size 4
==51200==    at 0x1091B3: main (in /home/xuluming/CLionProjects/ostep-code/memory-api/array_100)
==51200==  Address 0x4a581d0 is 0 bytes after a block of size 400 alloc'd
==51200==    at 0x483B7F3: malloc (in /usr/lib/x86_64-linux-gnu/valgrind/vgpreload_memcheck-amd64-linux.so)
==51200==    by 0x10918C: main (in /home/xuluming/CLionProjects/ostep-code/memory-api/array_100)
```

### 6. access after free

`access_after_free`
the program runs, the value prints, but the value is incorrect.

```text
a[0]=0
a[1]=1
a[2]=2
a[3]=3
a[4]=4
a[5]=5
a[6]=6
a[7]=7
a[8]=8
a[9]=9
array a freed.  trying to access element in array a: 
expect exception: 
a[0]=0
a[1]=0
a[2]=-2119294960
a[3]=21920
a[4]=4
a[5]=5
a[6]=6
a[7]=7
a[8]=8
a[9]=9
```

### 7. free pointer in the middle of array

`./free_funny_pointer`
allocates an array of size 100, then free a pointer 20 elements after the head. on normal run it prompts aborted,
invalid pointer.

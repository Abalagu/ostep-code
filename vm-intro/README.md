# Overview

Code from OSTEP chapter [The Abstraction: Address Spaces](http://pages.cs.wisc.edu/~remzi/OSTEP/vm-intro.pdf).

To compile, just type:

```
prompt> make
```

See the highly primitive `Makefile` for details.

Then, run it:

```
prompt> ./virtual-addresses
```

## memory-user

was suggested to use `strtol`
[strtol man](https://man7.org/linux/man-pages/man3/strtol.3.html)

### relevant commands

* `pgrep <process name>` return process id by name
* `ps <PID>` return process detail by process id
* `pkill <PID>` kill process by id
* `free -m` show memory detail in unit of MiB
* `fg` resume process in foreground

### observations

The used memory value changes around the same value as given in the command. When killing the execution by `Ctrl+C`, the
allocated memory is given back. However, when killing the execution by `Ctrl+Z`, the allocated memory remain used, and
it seems to fail to kill the process.

The cause is:

* `Ctrl+C` aborts the execution.
* `Ctrl+Z` shunts it into background, suspended.

Solution:

use `fg` to resume execution in foreground, then terminate properly.

## Answer to questions

2. running `free -m`

```text
              total        used        free      shared  buff/cache   available
Mem:           8499        3842         331          31        4325        4333
Swap:           947           0         946
```

3. running `memory-user 20`

```text
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ free -m
              total        used        free      shared  buff/cache   available
Mem:           8499        3885         287          32        4326        4289
Swap:           947           0         946
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ ./memory-user 20 &
[1] 44225
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ Allocate memory of size: 20 MiB
free -m
              total        used        free      shared  buff/cache   available
Mem:           8499        3904         269          32        4326        4271
Swap:           947           0         946

```

used memory increases from 3885 to 3904, which is around 20 MiB as given to memory-user.

4. kill memory-user process

```text
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ free -m
              total        used        free      shared  buff/cache   available
Mem:           8499        3921         252          32        4326        4253
Swap:           947           0         946
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ pkill memory-user 
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ free -m
              total        used        free      shared  buff/cache   available
Mem:           8499        3903         270          32        4326        4272
Swap:           947           0         946
[1]+  Terminated              ./memory-user 20
```

used memory decreased by around 20 MiB

6. pmap usage

```text
xuluming@ubuntu:~/CLionProjects/ostep-code/vm-intro$ pmap 44421
44421:   ./memory-user 20
0000562e6a264000      4K r---- memory-user
0000562e6a265000      4K r-x-- memory-user
0000562e6a266000      4K r---- memory-user
0000562e6a267000      4K r---- memory-user
0000562e6a268000      4K rw--- memory-user
0000562e6bd0e000    132K rw---   [ anon ]
00007fbcada43000  20484K rw---   [ anon ]
00007fbcaee44000    148K r---- libc-2.31.so
00007fbcaee69000   1504K r-x-- libc-2.31.so
00007fbcaefe1000    296K r---- libc-2.31.so
00007fbcaf02b000      4K ----- libc-2.31.so
00007fbcaf02c000     12K r---- libc-2.31.so
00007fbcaf02f000     12K rw--- libc-2.31.so
00007fbcaf032000     24K rw---   [ anon ]
00007fbcaf051000      4K r---- ld-2.31.so
00007fbcaf052000    140K r-x-- ld-2.31.so
00007fbcaf075000     32K r---- ld-2.31.so
00007fbcaf07e000      4K r---- ld-2.31.so
00007fbcaf07f000      4K rw--- ld-2.31.so
00007fbcaf080000      4K rw---   [ anon ]
00007ffedd442000    132K rw---   [ stack ]
00007ffedd4ec000     12K r----   [ anon ]
00007ffedd4ef000      4K r-x--   [ anon ]
ffffffffff600000      4K --x--   [ anon ]
 total            22976K
```

the size of 22976K is around 20 MiB as allocated to this process it lists the size, memory execution rights, and the
data that takes the space. either it is a so file, or a stack, or anon, which is believed to be heap, large blocks
allocated via malloc or mmap.

7. pmap to chrome it prints out too long a log. but the structure is similar to memory-user with compiled code, stack,
   and anon.
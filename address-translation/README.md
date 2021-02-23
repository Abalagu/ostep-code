# Notes on Chapter 15. Address Translation

address translation creates illusion to the program that it has its own private memory. But the reality is that its
physical space is shared with other programs, as the CPU switches between programs.

## interposition is powerful

interposition can be introduced to an interface add new functionality with transparency, meaning that the client using
the interface requires no change with such improvement.

## 15.2 objdump for assembly code

note that writing the function as `int main(){}` will generate much more code, while compiling to object file results in
simpler form.

use `objdump -d ./assignment_disassembly > ./log.txt`

## hardware-based relocation

aka dynamic relocation use two registers, base and bound, to offset the given address. 

using size is an alternative

## software-based relocation

before hardware-based relocation support, some system rewrites address by constant offset, such as
changing `movl 1000, %eax` to `movl 3000, %eax`.  
However, this may lead to some program generating addresses controlled by other programs, such illegal access needs to
be prevented.    
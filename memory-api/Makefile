objects = sizeof_test forget_allocation insufficient_malloc double_free dangling_pointer \
	null exit_without_free access_after_free array_100 free_funny_pointer

all: $(objects)

clean:
	rm -f $(objects)

sizeof_test: sizeof_test.c
	gcc -o sizeof_test sizeof_test.c

forget_allocation: forget_allocation.c
	gcc -o forget_allocation forget_allocation.c

insufficient_malloc: insufficient_malloc.c
	gcc -o insufficient_malloc insufficient_malloc.c

double_free: double_free.c
	gcc -o double_free double_free.c

dangling_pointer: dangling_pointer.c
	gcc -o dangling_pointer dangling_pointer.c

null: null.c
	gcc -o null null.c

exit_without_free: exit_without_free.c
	gcc -o exit_without_free exit_without_free.c

access_after_free: access_after_free.c
	gcc -o access_after_free access_after_free.c

array_100: array_100.c
	gcc -o array_100 array_100.c


free_funny_pointer: free_funny_pointer.c
	gcc -o free_funny_pointer free_funny_pointer.c
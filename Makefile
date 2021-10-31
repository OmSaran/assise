all: compile_libfs compile_kernfs

compile_libfs:
	make -C libfs -j 20
	make -C libfs/tests -j 20

compile_kernfs:
	make -C kernfs -j 20
	make -C kernfs/tests -j 20

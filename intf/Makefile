all: compile

compile:
	gcc -g test.c -I../libfs/src -L../libfs/build/ -lmlfs
	gcc -g test_read.c -o read -I../libfs/src -L../libfs/build/ -lmlfs
	gcc -g test_norm.c -o norm

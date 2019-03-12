.PHONY:	build test

all:	build	test

build:	bug

bug:	bug.c
	afl-gcc -g -o $@ $<

test:	bug
	@rm -rf in out
	@mkdir -p in out
	@echo 1 > in/data
	afl-fuzz -i in -o out -- ./bug @@

clean:
	rm -rf in out bug

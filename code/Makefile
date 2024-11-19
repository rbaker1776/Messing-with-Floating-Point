CC=clang++
CFLAGS=-std=c++20

%: %.cpp
	$(CC) $(CFLAGS) $(EXTRA) -o $@ $< && ./$@ && rm $@

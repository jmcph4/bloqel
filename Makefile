PROJ_NAME = bloqel

SRC_DIR = src
BUILD_DIR = build
DOCS_DIR = docs

CC = g++
CFLAGS = -Wall -Wextra -Wshadow -pedantic-errors -std=c++11 -g

$(BUILD_DIR)/lib$(PROJ_NAME).so: $(SRC_DIR)/*.cpp
	cd $(BUILD_DIR);
	$(CC) -c $^ $(CFLAGS) -fpic
	$(CC) *.o -shared -o $@
	cd ..;

.PHONY: docs
docs:
	cd $(SRC_DIR);\
	doxygen;\
	cd ..;

.PHONY: clean
clean:
	rm *.o
	rm $(BUILD_DIR)/*
	rm $(DOCS_DIR)/* -rf


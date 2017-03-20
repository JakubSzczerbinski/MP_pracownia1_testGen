CXX_COMPILER=g++
CXX_FLAGS=--std=c++11 -Werror -Wextra -Wall
CXX_LINKER_FLAGS=-lboost_program_options

build: main.cpp generator.cpp test_gen.cpp solver.cpp defaults.cpp
	${CXX_COMPILER} ${CXX_FLAGS} ${CXX_LINKER_FLAGS} \
	 main.cpp generator.cpp test_gen.cpp solver.cpp defaults.cpp\
	 -o test_generator
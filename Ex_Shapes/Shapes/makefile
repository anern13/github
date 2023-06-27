SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=objs/%.o)

PO_LIB := lib/libpoint.so
GLUT_LIB := lib/libglut_utils.so
SHAP_LIB := lib/libshape.so

GPP = g++ -std=c++14 -pedantic-errors -Wall -Wextra -g

test: main.cpp $(PO_LIB) $(GLUT_LIB) $(SHAP_LIB)
	$(GPP) main.cpp lib/libpoint.a -I include -Wl,-rpath=. lib/*.so

$(PO_LIB): lib/libpoint.a include/point.hpp
	$(GPP) lib/libpoint.a -shared -o $@

$(SHAP_LIB): $(OBJS)
	$(GPP) -shared -o $@ $^

objs/%.o: src/%.cpp
	$(GPP) -I include -fpic -c $< -o $@
	
demo: src/demo.c lib/libglut_utils.so
	gcc src/demo.c -I include -Wl,-rpath=. lib/libglut_utils.so
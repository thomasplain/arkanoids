EXT_DIR = externals
INC_DIR = include
VPATH = src:tests

# If system OS is Windows
ifeq ($(OS),Windows_NT)
	LIBGTEST = libgtest-win.a
else
	LIBGTEST = libgtest-nix.a
endif

CXXFLAGS += -I$(EXT_DIR) -I$(INC_DIR) -pthread

all: Main

clean:
	rm *.o
	rm arkanoids

Main: Main.o \
	Point_UnitTests.o Point.o \
	Box_UnitTests.o Box.o \
	Circle_UnitTests.o Circle.o \
	Vector_UnitTests.o Vector.o \
	Projection_UnitTests.o Projection.o \
	CollisionCheck_UnitTests.o CollisionCheck.o \
	Ball_UnitTests.o Ball.o
	$(CXX) -o arkanoids $(CXXFLAGS) $^ $(LIBGTEST)
	./arkanoids

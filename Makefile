CC = g++

all: main.o Model.o Vertex.o Face.o TextureSample2D.o ModelLoader.o TargaLoader.o BitmapLoader.o StringProcessing.o
	$(CC) main.o Model.o Vertex.o Face.o TextureSample2D.o ModelLoader.o TargaLoader.o BitmapLoader.o StringProcessing.o -o main -lglfw -lGL -lGLU

main.o: main.cpp
	$(CC) -c main.cpp

Model.o: Model.cpp
	$(CC) -c Model.cpp

Vertex.o: Vertex.cpp
	$(CC) -c Vertex.cpp

Face.o: Face.cpp
	$(CC) -c Face.cpp

TextureSample2D.o: TextureSample2D.cpp
	$(CC) -c TextureSample2D.cpp

ModelLoader.o: ModelLoader.cpp
	$(CC) -c ModelLoader.cpp

TargaLoader.o: TargaLoader.cpp
	$(CC) -c TargaLoader.cpp

BitmapLoader.o: BitmapLoader.cpp
	$(CC) -c BitmapLoader.cpp

StringProcessing.o: StringProcessing.cpp
	$(CC) -c StringProcessing.cpp


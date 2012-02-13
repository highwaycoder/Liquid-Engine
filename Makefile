PARENTDIRECTORY = ..

ASSETMODULE = ./AssetModule
ASSETMODULEOBJS = BitmapLoader.o TargaLoader.o ObjLoader.o Vertex.o Face.o Model.o TextureSample2D.o

UTILITYMODULE = ./UtilityModule
UTILITYMODULEOBS = StringProcessing.o

LIBS = -lGL -lGLU -lglfw

CC = g++

all: main.o AssetModule UtilityModule
	$(CC) main.o -L$(ASSETMODULE) $(ASSETMODULE)/AssetModule.a $(UTILITYMODULE)/UtilityModule.a $(LIBS)

main.o: main.cpp
	$(CC) -c main.cpp


AssetModule: AssetModule.so AssetModule.a

AssetModule.so: AssetModuleObjects
	cd $(ASSETMODULE); $(CC) -shared -o AssetModule.so $(ASSETMODULEOBJS)

AssetModule.a: AssetModuleObjects
	cd $(ASSETMODULE); ar rs AssetModule.a $(ASSETMODULEOBJS)

AssetModuleObjects: $(ASSETMODULE)/*.cpp
	cd $(ASSETMODULE); $(CC) -c -fpic *.cpp -I$(PARENTDIRECTORY)


UtilityModule: UtilityModule.so UtilityModule.a

UtilityModule.so: UtilityModuleObjects
	cd $(UTILITYMODULE); $(CC) -shared -o UtilityModule.so $(UTILITYMODULEOBS)

UtilityModule.a: UtilityModuleObjects
	cd $(UTILITYMODULE); ar rs UtilityModule.a $(UTILITYMODULEOBS)

UtilityModuleObjects: $(UTILITYMODULE)/*.cpp
	cd $(UTILITYMODULE); $(CC) -c -fpic *.cpp -I$(PARENTDIRECTORY)


clean:
	rm *.o
	rm $(ASSETMODULE)/*.o $(ASSETMODULE)/*.a $(ASSETMODULE)/*.so
	rm $(UTILITYMODULE)/*.o $(UTILITYMODULE)/*.a $(UTILITYMODULE)/*.so


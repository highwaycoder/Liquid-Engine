PARENTDIRECTORY = ..

UIMODULE = ./UIModule
UIMODULEOBJS = EngineCanvas.o UIApp.o control.o

UIMODULEFLAGS = $(shell wx-config --cppflags)
UIMODULELIBS = $(shell wx-config --libs --gl-libs) -lglut

ASSETMODULE = ./AssetModule
ASSETMODULEOBJS = BitmapLoader.o TargaLoader.o ObjLoader.o Vertex.o Face.o Model.o TextureSample2D.o

UTILITYMODULE = ./UtilityModule
UTILITYMODULEOBS = StringProcessing.o

LIBS = -lGL -lGLU -lglfw

CC = g++

all: main.o AssetModule UtilityModule
	$(CC) main.o -o main -L$(ASSETMODULE) $(ASSETMODULE)/AssetModule.a $(UTILITYMODULE)/UtilityModule.a $(UIMODULE)/UIModule.a $(LIBS) $(UIMODULELIBS) $(UIMODULEFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp

UIModule: UIModuleObjects
	cd $(UIMODULE); $(CC) $(UIMODULEOBJS) $(UIMODULELIBS)

UIModule.so: UIModuleObjects
	cd $(UIMODULE); $(CC) -shared -o UIModule.so $(UIMODULEOBJS) $(UIMODULELIBS)

UIModule.a: UIModuleObjects
	cd $(UIMODULE); ar rs UIModule.a $(UIMODULEOBJS)

UIModuleObjects:
	cd $(UIMODULE); $(CC) -c *.cpp $(UIMODULEFLAGS) -I$(PARENTDIRECTORY)

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
	rm -f *.o
	rm -f $(ASSETMODULE)/*.o $(ASSETMODULE)/*.a $(ASSETMODULE)/*.so
	rm -f $(UTILITYMODULE)/*.o $(UTILITYMODULE)/*.a $(UTILITYMODULE)/*.so
	rm -f $(UIMODULE)/*.o $(UIMODULE)/*.a $(UIMODULE)/*.so


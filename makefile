# GALACTICON makefile


# project structure:
# src:     *.cpp 
# include: *.h
# bin:     *.o, *.exe 
source_directory=  src
include_directory= include
binary_directory=  bin

source_files= $(wildcard src/*.cpp)
objects=      $(subst src,bin,$(subst cpp,o,$(source_files)))



sdl_include= C:\Users\npt\Documents\lib\SDL2\i686-w64-mingw32\include
sdl_libs   = C:\Users\npt\Documents\lib\SDL2\i686-w64-mingw32\lib

glm_include= C:\Users\npt\Documents\lib\glm

exe_flags  = -lmingw32 -lSDL2main -lSDL2 -Dmain=SDL_main -lSDL2_image -lSDL2_mixer -lSDL2_TTF -static-libgcc -static-libstdc++
obj_flags  = -I${include_directory} -I${glm_include} -I${sdl_include} -L${sdl_libs}



bin/%.o:src/%.cpp 
	g++ -c $< -o $@ $(obj_flags)

main: $(objects)
	g++ bin/*.o -o bin/main $(obj_flags) $(exe_flags) 

clean:
	del /q $(subst /,\,$(objects))



# here are the directories of the projects
# LIBS_ROOT=E:
LIBS_ROOT=/Users/markoates/Repos
ALLEGRO_DIR=$(LIBS_ROOT)/allegro5/build
ALLEGRO_FLARE_DIR=$(LIBS_ROOT)/allegro_flare
KRAMPUSHACK_DIR=$(LIBS_ROOT)/krampushack



# these are the names of the libs you are linking
ALLEGRO_FLARE_LIB=allegro_flare-0.8.8wip
ALLEGRO_LIBS=-lallegro_color-static -lallegro_font-static -lallegro_ttf-static -lallegro_dialog-static -lallegro_audio-static -lallegro_acodec-static -lallegro_primitives-static -lallegro_image-static -lallegro_main-static -lallegro-static
FRAMEWORKS=-framework CoreGraphics -framework QuartzCore -framework AudioToolbox -framework OpenAL -framework Foundation -framework CoreFoundation -framework CoreServices -framework IOKit -framework AppKit -framework OpenGL
OTHER_LIBS+=-lopus -logg -lvorbisfile -lvorbis -lfreetype -lflac
# OPENGL_LIB=-lopengl32



.PHONY: all clean main



SOURCES := $(shell find src -name '*.cpp')
OBJECTS := $(SOURCES:src/%.cpp=obj/%.o)



bin/krampushack: programs/krampushack.cpp $(OBJECTS)
	g++ -std=gnu++11 $(OBJECTS) $< -o $@ -l$(ALLEGRO_FLARE_LIB) $(ALLEGRO_LIBS) $(OTHER_LIBS) -L$(ALLEGRO_FLARE_DIR)/lib -L$(ALLEGRO_DIR)/lib $(OPENGL_LIB) -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include



obj/%.o: src/%.cpp
	g++ -c -std=gnu++11 $< -o $@ -I$(ALLEGRO_FLARE_DIR)/include -I$(ALLEGRO_DIR)/include -I./include



clean:
	-rm $(OBJECTS)
	-rm bin/krampushack





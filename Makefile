SRCDIR		=		./src/
INCDIR		=		./include/

SRC		=		$(SRCDIR)main.cpp \
				$(SRCDIR)SpriteSheet.cpp \
				$(SRCDIR)WorldState.cpp \
				$(SRCDIR)Character.cpp \
				$(SRCDIR)Animation.cpp \
				$(SRCDIR)Map.cpp

OBJS		=		$(SRC:.cpp=.o)

ifeq ($(TARGET), win)

NAME		=		Hateshinai.exe

CXX		=		i686-w64-mingw32-g++

CXXFLAGS		=		-Wall -Wextra -std=c++11 -DWIN32 -D_GLIBCXX_USE_CXX11_ABI=0

CXXFLAGS		+=		-I /usr/i686-w64-mingw32/include

LDFLAGS		=		-L /usr/i686-w64-mingw32/lib/ -lSDL2 -lSDL2main -lSDL2_image

endif

ifeq ($(TARGET), linux)

NAME		=		Hateshinai

CXX		=		g++

CXXFLAGS		=		-Wall -Wextra -std=c++11 -DLINUX -Iinclude

LDFLAGS		=		-lSDL2 -lSDL2main -lSDL2_image

endif

ifeq ($(TARGET), compile_win32)

NAME		=		Hateshinai

CXX		=		g++

CXXFLAGS		=		-Wall -Wextra -std=c++11 -DWIN32 -D_GLIBCXX_USE_CXX11_ABI=0 -Iinclude

LDFLAGS		=		-lSDL2 -lSDL2main -lSDL2_image

endif

all: $(OBJS)
	$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(OBJS)


fclean: clean
	rm -rf $(NAME)

re:	fclean all

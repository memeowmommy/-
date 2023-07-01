cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME game)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("SFML/include/")	# добавляем директории
include_directories("assets/")
link_directories("SFML/lib/")	

add_executable("${PROJECT_NAME}" main.cpp
                                 move.h
								 menu.h
								 menu.cpp

  
		
)
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s-d
						  sfml-window-s-d
						  sfml-system-s-d
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s-d
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)

file(COPY "assets/gg.png" DESTINATION "/assets")
file(COPY "assets/pink.png" DESTINATION "/assets")
file(COPY "assets/bg2.png" DESTINATION "/assets")
file(COPY "assets/npc.png" DESTINATION "/assets")
file(COPY "assets/Box.png" DESTINATION "/assets")
file(COPY "assets/pixy.ttf" DESTINATION "/assets")
file(COPY "assets/intro.ogg" DESTINATION "/assets")
file(COPY "assets/sound.ogg" DESTINATION "/assets")
file(COPY "assets/meow.wav" DESTINATION "/assets")
file(COPY "assets/bananacat.png" DESTINATION "/assets")


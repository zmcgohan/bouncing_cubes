clear
clang++ -F /Library/Frameworks -L /usr/local/lib -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system bouncing_cube.cpp BouncingCubeWindow.cpp -o bouncing_cube \
	&& ./bouncing_cube

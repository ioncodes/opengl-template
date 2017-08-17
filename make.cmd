cl /Fo.\obj\ -c src/*.cpp /I include
link /OUT:bin/64k.exe /libpath:lib obj/*.obj kernel32.lib user32.lib gdi32.lib opengl32.lib minicrt.lib
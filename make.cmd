del /q obj\*
del /q bin\*
cl /Fo.\obj\ -c src/*.cpp /I include -DUNICODE -D_UNICODE
link /OUT:bin/opengl.exe /libpath:lib obj/*.obj kernel32.lib user32.lib gdi32.lib opengl32.lib minicrt.lib
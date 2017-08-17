del /q obj\*.obj
del /q bin\*.exe
cl /Fo.\obj\ -c src/*.cpp /I include -DUNICODE -D_UNICODE
link /OUT:bin/opengl.exe /libpath:lib obj/*.obj kernel32.lib user32.lib gdi32.lib opengl32.lib minicrt.lib
#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include "glwindow.h"
#include "shaders.h"
#include "functions.h"

#define XRES 1280
#define YRES 720

char *fragmentShader = \
"void main()"
"{"
"vec2 v=-1.+gl_FragCoord.xy/vec2(640.,360.);"
"float r=pow(pow(abs(v.x),18.)+pow(abs(v.y),10.),1.8/28.);"
"vec2 t=vec2(gl_Color.x*64.+1./r,atan(v.x,v.y));"
"t=fract(2*t)-.5;"
"vec4 col=(1-pow(dot(t.xy,t.xy),.3))*vec4(2,1.8,1.6,0)+vec4(.3,.2,.1,0)+.12*vec4(v,0,0);"
"gl_FragColor=col/(2.*r);"
"}";

int main()
{
	wchar_t *windowTitle = L"lol";
	wchar_t *className = L"lol";


	GlWindow glWindow(windowTitle, className);
	glWindow.Init(); // initialize OpenGL context

	Functions::Initialize(); // Load functions

	Shaders shaders = Shaders();

	// Setup shaders
	shaders.ImplementShader(fragmentShader, GL_FRAGMENT_SHADER);
	shaders.CompileProgram();

	// set window size, draw window and loop renderer
	glWindow.ResizeWindow(XRES, YRES);
	glWindow.Show();
	glWindow.Loop();
	glWindow.Destroy();

	return 0;
}
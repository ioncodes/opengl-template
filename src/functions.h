#pragma once
#include <windows.h>
#include <GL/gl.h>
#include <GL/glext.h>

class Functions
{
public:
	static void Initialize();
	static PFNGLCREATEPROGRAMPROC glCreateProgram();
	static PFNGLCREATESHADERPROC glCreateShader();
	static PFNGLSHADERSOURCEPROC glShaderSource();
	static PFNGLCOMPILESHADERPROC glCompileShader();
	static PFNGLATTACHSHADERPROC glAttachShader();
	static PFNGLLINKPROGRAMPROC glLinkProgram();
	static PFNGLUSEPROGRAMPROC glUseProgram();

private:
	static PFNGLCREATEPROGRAMPROC m_glCreateProgram;
	static PFNGLCREATESHADERPROC m_glCreateShader;
	static PFNGLSHADERSOURCEPROC m_glShaderSource;
	static PFNGLCOMPILESHADERPROC m_glCompileShader;
	static PFNGLATTACHSHADERPROC m_glAttachShader;
	static PFNGLLINKPROGRAMPROC m_glLinkProgram;
	static PFNGLUSEPROGRAMPROC m_glUseProgram;
};
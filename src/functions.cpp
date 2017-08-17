#include "functions.h"

// Definitions
PFNGLCREATEPROGRAMPROC Functions::m_glCreateProgram;
PFNGLCREATESHADERPROC Functions::m_glCreateShader;
PFNGLSHADERSOURCEPROC Functions::m_glShaderSource;
PFNGLCOMPILESHADERPROC Functions::m_glCompileShader;
PFNGLATTACHSHADERPROC Functions::m_glAttachShader;
PFNGLLINKPROGRAMPROC Functions::m_glLinkProgram;
PFNGLUSEPROGRAMPROC Functions::m_glUseProgram;

void Functions::Initialize()
{
	m_glCreateProgram = (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
	m_glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
	m_glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
	m_glCompileShader = (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
	m_glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
	m_glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
	m_glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
}

PFNGLCREATEPROGRAMPROC Functions::glCreateProgram()
{
	return m_glCreateProgram;
}

PFNGLCREATESHADERPROC Functions::glCreateShader()
{
	return m_glCreateShader;
}

PFNGLSHADERSOURCEPROC Functions::glShaderSource()
{
	return m_glShaderSource;
}

PFNGLCOMPILESHADERPROC Functions::glCompileShader()
{
	return m_glCompileShader;
}

PFNGLATTACHSHADERPROC Functions::glAttachShader()
{
	return m_glAttachShader;
}

PFNGLLINKPROGRAMPROC Functions::glLinkProgram()
{
	return m_glLinkProgram;
}

PFNGLUSEPROGRAMPROC Functions::glUseProgram()
{
	return m_glUseProgram;
}

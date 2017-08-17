#pragma once
#include "functions.h"

/*
	This namespace contains wrapper functions to the OpenGL pointer functions.
*/
namespace GlFunctions
{
	inline GLuint CreateProgram()
	{
		return Functions::glCreateProgram()();
	}

	inline GLuint CreateShader(GLenum type)
	{
		return Functions::glCreateShader()(type);
	}

	inline void ShaderSource(GLuint shader, GLsizei count, const GLchar **string, const GLint *length)
	{
		Functions::glShaderSource()(shader, count, string, length);
	}

	inline void CompileShader(GLuint shader)
	{
		Functions::glCompileShader()(shader);
	}

	inline void AttachShader(GLuint program, GLuint shader)
	{
		Functions::glAttachShader()(program, shader);
	}

	inline void LinkProgram(GLuint program)
	{
		Functions::glLinkProgram()(program);
	}

	inline void UseProgram(GLuint program)
	{
		Functions::glUseProgram()(program);
	}
}
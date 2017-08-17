#pragma once
#include "functions.h"

class Shaders
{
public:
	Shaders();
	void ImplementShader(const GLchar *source, GLenum type) const;
	void CompileProgram() const;
private:
	GLuint m_program; // let's use only one program for now..
};


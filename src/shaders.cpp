#include "shaders.h"
#include "glfunctions.h"

using namespace GlFunctions;

Shaders::Shaders()
{
	m_program = CreateProgram();
}

void Shaders::ImplementShader(const GLchar *source, GLenum type) const
{
	GLuint shader = CreateShader(type);
	ShaderSource(shader, 1, &source, 0);
	CompileShader(shader);
	AttachShader(m_program, shader);
}

void Shaders::CompileProgram() const
{
	LinkProgram(m_program);
	UseProgram(m_program);
}

#include "GLSLProgram.h"
#include "Errors.h"
#include <vector>
#include <fstream>


GLSLProgram::GLSLProgram() : _numAttributes(0), _programID(0), _vertexShaderID(0), _fragmentShaderID(0)
{
}

GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::compileShaders(const std::string& vertexShaderFilepath, const std::string& fragmentShaderFilepath) 
{
// Vertex and fragment shaders are successfully compiled.
// Now time to link them together into a program.
// Get a program object.
	_programID = glCreateProgram();
	
	_vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_vertexShaderID == 0)
	{
		FatalError("Vertex Shader Failed to be created!");
	}

	_fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_fragmentShaderID == 0)
	{
		FatalError("Fragment Shader Failed to be created!");
	}

	compileShader(vertexShaderFilepath, _vertexShaderID);
	compileShader(fragmentShaderFilepath, _fragmentShaderID);

	
}

void GLSLProgram::linkShaders() 
{
	// Attach our shaders to our program
	glAttachShader(_programID, _vertexShaderID);
	glAttachShader(_programID, _fragmentShaderID);

	// Link our program
	glLinkProgram(_programID);

	// Note the different functions here: glGetProgram* instead of glGetShader*.
	GLint isLinked = 0;
	glGetProgramiv(_programID, GL_LINK_STATUS, (int *)&isLinked);
	if (isLinked == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<char> errorLog(maxLength);
		glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);

		// We don't need the program anymore.
		glDeleteProgram(_programID);
		// Don't leak shaders either.
		glDeleteShader(_vertexShaderID);
		glDeleteShader(_fragmentShaderID);

		// Use the infoLog as you see fit.

		std::printf("%s\n", &(errorLog[0]));
		FatalError("Shaders failed to link!");
	}

	// Always detach shaders after a successful link.
	glDetachShader(_programID, _vertexShaderID);
	glDetachShader(_programID, _fragmentShaderID);
	glDeleteShader(_vertexShaderID);
	glDeleteShader(_fragmentShaderID);
}

void GLSLProgram::addAttribute(const std::string& attributeName)
{
	glBindAttribLocation(_programID, _numAttributes++, attributeName.c_str());
}

void GLSLProgram::compileShader(const std::string& filePath, GLuint& id)
{
	std::ifstream vertexFile(filePath);
	if (vertexFile.fail())
	{
		FatalError("Vertex File failed to open " + filePath);
	}

	std::string filecontents = "";
	std::string line;

	while (std::getline(vertexFile, line))
	{
		filecontents += line + "\n";
	}

	vertexFile.close();

	const char* contentsPtr = filecontents.c_str();
	glShaderSource(id, 1, &contentsPtr, nullptr);
	glCompileShader(id);

	GLint success = 0;
	glGetShaderiv(id, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		GLint maxlenght = 0;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxlenght);

		std::vector<char> errorLog(maxlenght);
		glGetShaderInfoLog(id, maxlenght, &maxlenght, &errorLog[0]);

		glDeleteShader(id);

		std::printf("%s\n", &(errorLog[0]));
		FatalError("Shader "+ filePath + " failed to compile!");
	}
}

void GLSLProgram::use() 
{
	glUseProgram(_programID);
	for (int i = 0; i < _numAttributes; i++)
	{
		glEnableVertexAttribArray(i);
	}
}

void GLSLProgram::unuse() 
{
	glUseProgram(0);
	for (int i = 0; i < _numAttributes; i++)
	{
		glDisableVertexAttribArray(i);
	}
}
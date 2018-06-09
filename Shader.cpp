#include "Shader.h"
Shader::Shader(const char* a_VertexFilePath, const char* a_FragmentFilePath)
{

	VertexFilePath = a_VertexFilePath;
	FragmentFilePath = a_FragmentFilePath;
}


Shader::~Shader()
{
}

void Shader::Init()
{

	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile, fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(VertexFilePath);
		fShaderFile.open(FragmentFilePath);
		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		std::cout << e.what() << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCpde = fragmentCode.c_str();
	_ShaderID = glCreateProgram();

	_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(_VertexShaderID, 1, &vShaderCode, 0);
	glCompileShader(_VertexShaderID);

	int success;
	char infoLog[512];
	glGetShaderiv(_VertexShaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(_VertexShaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	};


	_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(_FragmentShaderID, 1, &fShaderCpde, 0);
	glCompileShader(_FragmentShaderID);

	glGetShaderiv(_FragmentShaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(_FragmentShaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	};


	glAttachShader(_ShaderID, _VertexShaderID);
	glAttachShader(_ShaderID, _FragmentShaderID);
	glLinkProgram(_ShaderID);

}

void Shader::Use()
{
	glUseProgram(_ShaderID);
}

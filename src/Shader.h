#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include "GLUtils.h"

#include "Utils.h"

namespace lwvl {
	struct Location {
		int data = -1;
		operator int() const;
		operator bool() const;

		Location(const int uniformLocation);
		Location(Location& other);
	};


	class Shader {
		unsigned int m_id;

	public:
		Shader();
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		Shader(Shader& other);
		~Shader();

		static Shader fromFiles(const std::string& vertexFile, const std::string& fragmentFile);

		static unsigned int compileShader(int mode, const std::string& source);

		[[nodiscard]] Location uniformLocation(const char* name) const;

		void uniformMatrix4fv(const Location& location, const float* data);
		bool uniformMatrix4fv(const char* name, const float* data);

		void uniform1f(const Location& location, const float v0);
		void uniform2f(const Location& location, const float v0, const float v1);
		void uniform3f(const Location& location, const float v0, const float v1, const float v2);
		void uniform4f(const Location& location, const float v0, const float v1, const float v2, const float v3);

		bool uniform1f(const char* name, const float v0);
		bool uniform2f(const char* name, const float v0, const float v1);
		bool uniform3f(const char* name, const float v0, const float v1, const float v2);
		bool uniform4f(const char* name, const float v0, const float v1, const float v2, const float v3);

		void uniform1i(const Location& location, const int v0);
		bool uniform1i(const char* name, const int v0);

		void uniform2u(const Location& location, const unsigned int v0, const unsigned int v1);
		bool uniform2u(const char* name, const unsigned int v0, const unsigned int v1);

		void setOrthographic(const Location& location, float top, float bottom, float right, float left, float far, float near);
		void setOrthographic2D(const Location& location, float top, float bottom, float right, float left);

		void bind() const;
		static void clear();
	};
}

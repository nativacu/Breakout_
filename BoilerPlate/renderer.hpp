#include "shader.hpp"

#pragma once
#ifndef RENDERER_H
#define RENDERER_H

namespace engine {
	namespace renderer {
		class renderer
		{
		public:
			renderer();
			void get_program_ID();
			void draw_polygon();
			void clean_up();
			void set_vertex_data();
			void toggle_wire_frame_view(bool);

		private:
			GLuint VertexArrayObject; //VAO
			GLuint VertexBufferObject; //VBO
			GLuint ElementsBufferObject; //EBO
			GLuint ProgramID; //holds shader compilation values
			engine::shaders::shader shaderUtility;
			bool usingWireFrameView;
		};
	}
}

#endif // !RENDERER_H


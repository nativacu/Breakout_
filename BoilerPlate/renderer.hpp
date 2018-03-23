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
			renderer(int, int);
			void get_program_ID();
			void draw_polygon();
			void clean_up();
			void set_vertex_data();
			void toggle_wire_frame_view(bool);
			GLuint load_texture(const char * texture_path);
			// And this
			void set_texture_resolution(void);

		private:
			GLuint VertexArrayObject; //VAO
			GLuint VertexBufferObject; //VBO
			GLuint ElementsBufferObject; //EBO
			GLuint ProgramID; //holds shader compilation values
			engine::shaders::shader shaderUtility;
			bool usingWireFrameView;

			//Added this
			GLuint mTextures[16];
			int mScreenWidth;
			int mScreenHeight;
		};
	}
}

#endif // !RENDERER_H


#include "shaderUtility.hpp"

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
			void set_texture1(GLuint a);
			// And this
			void set_texture_resolution(void);

		private:
			GLuint mVertexArrayObject; //VAO
			GLuint mVertexBufferObject; //VBO
			GLuint mElementsBufferObject; //EBO
			GLuint mProgramID; //holds shader compilation values
			engine::utilities::shaderUtility mShaderUtility;
			bool mUsingWireFrameView;

			//Added this
			GLuint mTextures[16];
			GLuint texture1;
			int mScreenWidth;
			int mScreenHeight;
		};
	}
}

#endif // !RENDERER_H


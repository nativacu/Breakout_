#include "shaderUtility.hpp"
#include "matrix4.hpp" 

#pragma once
#ifndef RENDERER_H
#define RENDERER_H

const int MAX_TEXTURE_COUNT = 16;

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
			void set_vertex_data(float* pVertices, engine::math::matrix4* pModelMatrix);
			void toggle_wire_frame_view(bool);
			void add_texture(const char * texture_path, bool isUsingAlpha);
			GLuint load_texture(const char * texture_path, bool isUsingAlpha);
			void set_texture1(GLuint a);
			
			// And this
			void set_texture_resolution(void);

		private:
			GLuint mVertexArrayObject; //VAO
			GLuint mVertexBufferObject; //VBO
			GLuint mElementsBufferObject; //EBO
			GLuint mProgramID; //holds shader complation values
			engine::utilities::shaderUtility mShaderUtility;
			bool mUsingWireFrameView;
			GLuint mTexture;

			//Texture container
			GLuint mTextures[MAX_TEXTURE_COUNT];
			int mTextureCount = 0;

			//Added this
			int mScreenWidth;
			int mScreenHeight;
		};
	}
}

#endif // !RENDERER_H


#include "shaderUtility.hpp"
#include "matrix4.hpp" 
#include "gameObject.hpp"

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
			void render_object(engine::core::gameObject& pObject);
			void set_vertex_data(float* pVertices, engine::math::matrix4* pModelMatrix);
			void render_texture(float* pVertices, float pIndices, float pTextureCount);
			void toggle_wire_frame_view(bool);
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

			//Added this
			int mScreenWidth;
			int mScreenHeight;
		};
	}
}

#endif // !RENDERER_H


#ifndef BUKU_H
#define BUKU_H

#include "Object.h"

class Buku :
	public Object
{
public:
	Buku(glm::vec3 pos) : Object(pos) {}
	Buku(glm::vec3 pos, float init_degree) : Object(pos, init_degree) {}

protected:
	Buffers getVertexBufferData() { return { v_buffer, sizeof(v_buffer) }; };

private:
	float v_buffer[96] = {
		// sampul belakang
		-0.6f, -0.25f,   0.9f, 	// [0] front bot left
		 0.6f, -0.25f,   0.9f,	// [1] front bot right
		-0.6f, -0.20f,  0.9f,	// [2] front top left
		 0.6f, -0.20f,  0.9f,	// [3] front top right
		-0.6f, -0.25f,  -0.9f,	// [4] back bot left
		 0.6f, -0.25f,  -0.9f,	// [5] back bot right
		-0.6f, -0.20f, -0.9f,	// [6] back top left
		 0.6f, -0.20f, -0.9f,	// [7] back top right

		// sampul tengah
		-0.65f, -0.25f,   0.9f,	// [0] front bot left
		-0.6f,  -0.25f,   0.9f,	// [1] front bot right
		-0.65f,  0.25f,   0.9f,	// [2] front top left
		-0.6f,   0.25f,   0.9f,	// [3] front top right
		-0.65f, -0.25f,  -0.9f,	// [4] back bot left
		-0.6f,  -0.25f,  -0.9f,	// [5] back bot right
		-0.65f,  0.25f,  -0.9f,	// [6] back top left
		-0.6f,   0.25f,  -0.9f,	// [7] back top right

		// isi buku
		-0.6f,  -0.20f,  0.85f,	// [0] front bot left
		 0.55f, -0.20f,  0.85f,	// [1] front bot right
		-0.6f,   0.20f,  0.85f,	// [2] front top left
		 0.55f,  0.20f,  0.85f,	// [3] front top right
		-0.6f,  -0.20f, -0.85f,	// [4] back bot left
		 0.55f, -0.20f, -0.85f,	// [5] back bot right
		-0.6f,   0.20f, -0.85f,	// [6] back top left
		 0.55f,  0.20f, -0.85f,	// [7] back top right

		 // sampul depan
		-0.6f,  0.20f,  0.9f,	// [0] front bot left
		 0.6f,  0.20f,  0.9f,	// [1] front bot right
		-0.6f,  0.25f,   0.9f,	// [2] front top left
		 0.6f,  0.25f,   0.9f,	// [3] front top right
		-0.6f,  0.20f, -0.9f,	// [4] back bot left
		 0.6f,  0.20f, -0.9f,	// [5] back bot right
		-0.6f,  0.25f,  -0.9f,	// [6] back top left
		 0.6f,  0.25f,  -0.9f,	// [7] back top 
	};
};

#endif

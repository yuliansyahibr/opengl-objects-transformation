#ifndef MEJA_H
#define MEJA_H

#include "Object.h"

class Meja :
	public Object
{
public:
	Buffers getVertexBufferData2();
	Meja(glm::vec3 pos) : Object(pos) {}
	Meja(glm::vec3 pos, float init_degree) : Object(pos, init_degree) {}

protected:
	Buffers getVertexBufferData();

private:
	float v_buffer[120] = {
		// kaki depan kiri
		-0.8f, -0.8f,  0.4f,	// [0] front bot left
		-0.7f, -0.8f,  0.4f,	// [1] front bot right
		-0.8f,  0.1f,  0.4f,	// [2] front top left
		-0.7f,  0.1f,  0.4f,	// [3] front top right
		-0.8f, -0.8f, -0.7f,	// [4] back bot left
		-0.7f, -0.8f, -0.7f,	// [5] back bot right
		-0.8f,  0.1f, -0.7f,	// [6] back top left
		-0.7f,  0.1f, -0.7f,	// [7] back top right
		// kaki depan kanan +8
		 0.7f, -0.8f,  0.4f,	// [0] front bot left
		 0.8f, -0.8f,  0.4f,	// [1] front bot right
		 0.7f,  0.1f,  0.4f,	// [2] front top left
		 0.8f,  0.1f,  0.4f,	// [3] front top right
		 0.7f, -0.8f, -0.7f,	// [4] back bot left
		 0.8f, -0.8f, -0.7f,	// [5] back bot right
		 0.7f,  0.1f, -0.7f,	// [6] back top left
		 0.8f,  0.1f, -0.7f,	// [7] back top right

		 // kaki belakang
		-0.8f, -0.8f, -0.7f,	// [0] front bot left
		 0.8f, -0.8f, -0.7f,	// [1] front bot right
		-0.8f,  0.1f, -0.7f,	// [2] front top left
		 0.8f,  0.1f, -0.7f,	// [3] front top right
		-0.8f, -0.8f, -0.8f,	// [4] back bot left
		 0.8f, -0.8f, -0.8f,	// [5] back bot right
		-0.8f,  0.1f, -0.8f,	// [6] back top left
		 0.8f,  0.1f, -0.8f,	// [7] back top right

		 // atas
		-0.9f,  0.1f,  0.4f,	// [0] front bot left
		 0.9f,  0.1f,  0.4f,	// [1] front bot right
		-0.9f,  0.3f,  0.4f,	// [2] front top left
		 0.9f,  0.3f,  0.4f,	// [3] front top right
		-0.9f,  0.1f, -0.9f,	// [4] back bot left
		 0.9f,  0.1f, -0.9f,	// [5] back bot right
		-0.9f,  0.3f, -0.9f,	// [6] back top left
		 0.9f,  0.3f, -0.9f,	// [7] back top right

		 // laci
		 0.2f, -0.65f,  0.4f,	// [0] front bot left
		 0.7f, -0.65f,  0.4f,	// [1] front bot right
		 0.2f,  0.1f,   0.4f,	// [2] front top left
		 0.7f,  0.1f,   0.4f,	// [3] front top right
		 0.2f, -0.65f, -0.7f,	// [4] back bot left
		 0.7f, -0.65f, -0.7f,	// [5] back bot right
		 0.2f,  0.1f,  -0.7f,	// [6] back top left
		 0.7f,  0.1f,  -0.7f,	// [7] back top right
	};
};

#endif

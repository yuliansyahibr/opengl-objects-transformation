#ifndef BOX_H
#define BOX_H

#include "Object.h"

class Box :
	public Object
{
public:
	Box(glm::vec3 pos) : Object(pos) {}
	Box(glm::vec3 pos, float init_degree) : Object(pos, init_degree) {}

protected:
	Buffers getVertexBufferData() { return { v_buffer, sizeof(v_buffer) }; };

private:
	float v_buffer[144] = {
		// sisi  kiri
		-0.8f, -0.8f,  0.4f,	// [0] front bot left
		-0.78f, -0.8f,  0.4f,	// [1] front bot right
		-0.8f,  0.1f,  0.4f,	// [2] front top left
		-0.78f,  0.1f,  0.4f,	// [3] front top right
		-0.8f, -0.8f, -0.7f,	// [4] back bot left
		-0.78f, -0.8f, -0.7f,	// [5] back bot right
		-0.8f,  0.1f, -0.7f,	// [6] back top left
		-0.78f,  0.1f, -0.7f,	// [7] back top right
		// sisi kanan +8
		 0.78f, -0.8f,  0.4f,	// [0] front bot left
		 0.8f, -0.8f,  0.4f,	// [1] front bot right
		 0.78f,  0.1f,  0.4f,	// [2] front top left
		 0.8f,  0.1f,  0.4f,	// [3] front top right
		 0.78f, -0.8f, -0.7f,	// [4] back bot left
		 0.8f, -0.8f, -0.7f,	// [5] back bot right
		 0.78f,  0.1f, -0.7f,	// [6] back top left
		 0.8f,  0.1f, -0.7f,	// [7] back top right
		 // sisi depan +8
		-0.8f, -0.8f,  0.4f,	// [0] front bot left
		 0.8f, -0.8f,  0.4f,	// [1] front bot right
		-0.8f,  0.1f,  0.4f,	// [2] front top left
		 0.8f,  0.1f,  0.4f,	// [3] front top right
		-0.8f, -0.8f,  0.38f,	// [4] back bot left
		 0.8f, -0.8f,  0.38f,	// [5] back bot right
		-0.8f,  0.1f,  0.38f,	// [6] back top left
		 0.8f,  0.1f,  0.38f,	// [7] back top right
		// sisi belakang
		-0.8f, -0.8f, -0.68f,	// [0] front bot left
		 0.8f, -0.8f, -0.68f,	// [1] front bot right
		-0.8f,  0.1f, -0.68f,	// [2] front top left
		 0.8f,  0.1f, -0.68f,	// [3] front top right
		-0.8f, -0.8f, -0.7f,	// [4] back bot left
		 0.8f, -0.8f, -0.7f,	// [5] back bot right
		-0.8f,  0.1f, -0.7f,	// [6] back top left
		 0.8f,  0.1f, -0.7f,	// [7] back top right

		 // bawah
		-0.8f, -0.8f,   0.4f,	// [0] front bot left
		 0.8f, -0.8f,   0.4f,	// [1] front bot right
		-0.8f, -0.78f,  0.4f,	// [2] front top left
		 0.8f, -0.78f,  0.4f,	// [3] front top right
		-0.8f, -0.8f,  -0.7f,	// [4] back bot left
		 0.8f, -0.8f,  -0.7f,	// [5] back bot right
		-0.8f, -0.78f, -0.7f,	// [6] back top left
		 0.8f, -0.78f, -0.7f,	// [7] back top right

		 // kanan
		 0.78f, -0.65f,  0.4f,	// [0] front bot left
		 0.80f, -0.65f,  0.4f,	// [1] front bot right
		 0.78f,  0.1f,   0.4f,	// [2] front top left
		 0.80f,  0.1f,   0.4f,	// [3] front top right
		 0.78f, -0.65f, -0.7f,	// [4] back bot left
		 0.80f, -0.65f, -0.7f,	// [5] back bot right
		 0.78f,  0.1f,  -0.7f,	// [6] back top left
		 0.80f,  0.1f,  -0.7f	// [7] back top right

		  // kiri
		 //0.2f, -0.65f,  0.4f,	// [0] front bot left
		 //0.7f, -0.65f,  0.4f,	// [1] front bot right
		 //0.2f,  0.1f,   0.4f,	// [2] front top left
		 //0.7f,  0.1f,   0.4f,	// [3] front top right
		 //0.2f, -0.65f, -0.7f,	// [4] back bot left
		 //0.7f, -0.65f, -0.7f,	// [5] back bot right
		 //0.2f,  0.1f,  -0.7f,	// [6] back top left
		 //0.7f,  0.1f,  -0.7f,	// [7] back top right
	};
};

#endif

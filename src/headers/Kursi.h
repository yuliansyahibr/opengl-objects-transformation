#ifndef KURSI_H
#define KURSI_H

#include "Object.h"

class Kursi :
	public Object
{
public:
	Kursi(glm::vec3 pos) : Object(pos) {}
	Kursi(glm::vec3 pos, float init_degree) : Object(pos, init_degree) {}

protected:
	Buffers getVertexBufferData() { return { v_buffer, sizeof(v_buffer) }; };

private:
	float v_buffer[288] = {
		// kaki depan kiri
		-0.36f,  -0.8f, 0.0f,		// [0] front bot left
		-0.28f,  -0.8f, 0.0f,		// [1] front bot right
		-0.36f,  -0.2f, 0.0f,		// [2] front top left
		-0.28f,  -0.2f, 0.0f,		// [3] front top right
		-0.36f,  -0.8f, -0.1f,		// [4] back bot left
		-0.28f,  -0.8f, -0.1f,		// [5] back bot right
		-0.36f,  -0.2f, -0.1f,		// [6] back top left
		-0.28f,  -0.2f, -0.1f,		// [7] back top right
		// kaki depan kanan +8
		 0.28f,  -0.8f, 0.0f,		// [0] front bot left
		 0.36f,  -0.8f, 0.0f,		// [1] front bot right
		 0.28f,  -0.2f, 0.0f,		// [2] front top left
		 0.36f,  -0.2f, 0.0f,		// [3] front top right
		 0.28f,  -0.8f, -0.1f,		// [4] back bot left
		 0.36f,  -0.8f, -0.1f,		// [5] back bot right
		 0.28f,  -0.2f, -0.1f,		// [6] back top left
		 0.36f,  -0.2f, -0.1f,		// [7] back top right
		 // kaki belakang kiri +	// 
		-0.36f,  -0.8f, -0.6f,		// [0] front bot left
		-0.28f,  -0.8f, -0.6f,		// [1] front bot right
		-0.36f,  -0.2f, -0.6f,		// [2] front top left
		-0.28f,  -0.2f, -0.6f,		// [3] front top right
		-0.36f,  -0.8f, -0.7f,		// [4] back bot left
		-0.28f,  -0.8f, -0.7f,		// [5] back bot right
		-0.36f,  -0.2f, -0.7f,		// [6] back top left
		-0.28f,  -0.2f, -0.7f,		// [7] back top right
		 // kaki belakang kanan		// 
		 0.28f, -0.8f, -0.6f,		// [0] front bot left
		 0.36f, -0.8f, -0.6f,		// [1] front bot right
		 0.28f, -0.2f, -0.6f,		// [2] front top left
		 0.36f, -0.2f, -0.6f,		// [3] front top right
		 0.28f, -0.8f, -0.7f,		// [4] back bot left
		 0.36f, -0.8f, -0.7f,		// [5] back bot right
		 0.28f, -0.2f, -0.7f,		// [6] back top left
		 0.36f, -0.2f, -0.7f,		// [7] back top right
									// 
		 // pijakan kiri			// 
		-0.36f,  -0.65f, -0.1f,		// [0] front bot left
		-0.28f,  -0.65f, -0.1f,		// [1] front bot right
		-0.36f,  -0.59f, -0.1f,		// [2] front top left
		-0.28f,  -0.59f, -0.1f,		// [3] front top right
		-0.36f,  -0.65f, -0.6f,		// [4] back bot left
		-0.28f,  -0.65f, -0.6f,		// [5] back bot right
		-0.36f,  -0.59f, -0.6f,		// [6] back top left
		-0.28f,  -0.59f, -0.6f,		// [7] back top right
		 // pijakan kanan			// 
		 0.28f, -0.65f, -0.1f,		// [0] front bot left
		 0.36f, -0.65f, -0.1f,		// [1] front bot right
		 0.28f, -0.59f, -0.1f,		// [2] front top left
		 0.36f, -0.59f, -0.1f,		// [3] front top right
		 0.28f, -0.65f, -0.6f,		// [4] back bot left
		 0.36f, -0.65f, -0.6f,		// [5] back bot right
		 0.28f, -0.59f, -0.6f,		// [6] back top left
		 0.36f, -0.59f, -0.6f,		// [7] back top right
									// 
		 // alas duduk +32			// 
		-0.36f, -0.2f,   0.0f,		// [0] front bot left
		 0.36f, -0.2f,   0.0f,		// [1] front bot right
		-0.36f, -0.1f,  0.0f,		// [2] front top left
		 0.36f, -0.1f,  0.0f,		// [3] front top right
		-0.36f, -0.2f,  -0.7f,		// [4] back bot left
		 0.36f, -0.2f,  -0.7f,		// [5] back bot right
		-0.36f, -0.1f, -0.7f,		// [6] back top left
		 0.36f, -0.1f, -0.7f,		// [7] back top right
		 // kaki atas kiri +40		// 
		-0.33f, -0.10f, -0.6f,		// [0] front bot left
		-0.25f, -0.10f, -0.6f,		// [1] front bot right
		-0.40f,  0.76f, -0.6f,		// [2] front top left
		-0.32f,  0.76f, -0.6f,		// [3] front top right
		-0.33f, -0.10f, -0.7f,		// [4] back bot left
		-0.25f, -0.10f, -0.7f,		// [5] back bot right
		-0.40f,  0.76f, -0.7f,		// [6] back top left
		-0.32f,  0.76f, -0.7f,		// [7] back top right
		 // kaki atas kanan +48		// 
		 0.25f, -0.10f, -0.6f,		// [0] front bot left
		 0.33f, -0.10f, -0.6f,		// [1] front bot right
		 0.32f,  0.76f, -0.6f,		// [2] front top left
		 0.40f,  0.76f, -0.6f,		// [3] front top right
		 0.25f, -0.10f, -0.7f,		// [4] back bot left
		 0.33f, -0.10f, -0.7f,		// [5] back bot right
		 0.32f,  0.76f, -0.7f,		// [6] back top left
		 0.40f,  0.76f, -0.7f,		// [7] back top right
		 // sandaran kursi 1
		-0.36f,   0.63f, -0.60f,	// [0] front bot left
		 0.36f,   0.63f, -0.60f,	// [1] front bot right
		-0.36f,   0.73f, -0.60f,	// [2] front top left
		 0.36f,   0.73f, -0.60f,	// [3] front top right
		-0.36f,   0.63f, -0.68f,	// [4] back bot left
		 0.36f,   0.63f, -0.68f,	// [5] back bot right
		-0.36f,   0.73f, -0.68f,	// [6] back top left
		 0.36f,   0.73f, -0.68f,	// [7] back top right
		 // sandaran kursi 2
		-0.35f,   0.43f, -0.60f,	// [0] front bot left
		 0.35f,   0.43f, -0.60f,	// [1] front bot right
		-0.35f,   0.53f, -0.60f,	// [2] front top left
		 0.35f,   0.53f, -0.60f,	// [3] front top right
		-0.35f,   0.43f, -0.68f,	// [4] back bot left
		 0.35f,   0.43f, -0.68f,	// [5] back bot right
		-0.35f,   0.53f, -0.68f,	// [6] back top left
		 0.35f,   0.53f, -0.68f,	// [7] back top right
		 // sandaran kursi 3
		-0.34f,   0.23f, -0.60f,	// [0] front bot left
		 0.34f,   0.23f, -0.60f,	// [1] front bot right
		-0.34f,   0.33f, -0.60f,	// [2] front top left
		 0.34f,   0.33f, -0.60f,	// [3] front top right
		-0.34f,   0.23f, -0.68f,	// [4] back bot left
		 0.34f,   0.23f, -0.68f,	// [5] back bot right
		-0.34f,   0.33f, -0.68f,	// [6] back top left
		 0.34f,   0.33f, -0.68f,	// [7] back top right
	};
};

#endif

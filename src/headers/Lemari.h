#ifndef LEMARI_H
#define LEMARI_H

#include "Object.h"

class Lemari :
	public Object
{
public:
	Lemari(glm::vec3 pos) : Object(pos) {}
	Lemari(glm::vec3 pos, float init_degree) : Object(pos, init_degree) {}

protected:
	Buffers getVertexBufferData() { return { v_buffer, sizeof(v_buffer) }; };

private:
	float v_buffer[144] = {
		// alas bawah
		-0.7f, -0.8f,  0.5f,		// [0] front bot left
		 0.7f, -0.8f,  0.5f,		// [1] front bot right
		-0.7f, -0.7f,  0.5f,		// [2] front top left
		 0.7f, -0.7f,  0.5f,		// [3] front top right
		-0.7f, -0.8f, -0.5f,		// [4] back bot left
		 0.7f, -0.8f, -0.5f,		// [5] back bot right
		-0.7f, -0.7f, -0.5f,		// [6] back top left
		 0.7f, -0.7f, -0.5f,		// [7] back top right

		// dinding kiri
		-0.65f, -0.7f,  0.45f,		// [0] front bot left
		-0.6f, -0.7f,   0.45f,		// [1] front bot right
		-0.65f,  0.7f,  0.45f,		// [2] front top left
		-0.6f,  0.7f,   0.45f,		// [3] front top right
		-0.65f, -0.7f, -0.45f,		// [4] back bot left
		-0.6f, -0.7f,  -0.45f,		// [5] back bot right
		-0.65f,  0.7f, -0.45f,		// [6] back top left
		-0.6f,  0.7f,  -0.45f,		// [7] back top 

		// dinding belakang
		-0.65f, -0.7f, -0.35f,		// [0] front bot left
		 0.65f, -0.7f, -0.35f,		// [1] front bot right
		-0.65f,  0.7f, -0.35f,		// [2] front top left
		 0.65f,  0.7f, -0.35f,		// [3] front top right
		-0.65f, -0.7f, -0.4f,		// [4] back bot left
		 0.65f, -0.7f, -0.4f,		// [5] back bot right
		-0.65f,  0.7f, -0.4f,		// [6] back top left
		 0.65f,  0.7f, -0.4f,		// [7] back top right

		 // dinding kanan
		 0.6f, -0.7f,   0.45f,		// [0] front bot left
		 0.65f, -0.7f,  0.45f,		// [1] front bot right
		 0.6f,  0.7f,   0.45f,		// [2] front top left
		 0.65f,  0.7f,  0.45f,		// [3] front top right
		 0.6f, -0.7f,  -0.45f,		// [4] back bot left
		 0.65f, -0.7f, -0.45f,		// [5] back bot right
		 0.6f,  0.7f,  -0.45f,		// [6] back top left
		 0.65f,  0.7f, -0.45f,		// [7] back top right

		 // bag atas
		-0.7f,  0.7f,  0.5f,		// [0] front bot left
		 0.7f,  0.7f,  0.5f,		// [1] front bot right
		-0.7f,  0.8f,  0.5f,		// [2] front top left
		 0.7f,  0.8f,  0.5f,		// [3] front top right
		-0.7f,  0.7f, -0.5f,		// [4] back bot left
		 0.7f,  0.7f, -0.5f,		// [5] back bot right
		-0.7f,  0.8f, -0.5f,		// [6] back top left
		 0.7f,  0.8f, -0.5f,		// [7] back top 

		 // pintu kiri
		//-0.65f, -0.7f,  0.38f,		// [0] front bot left
		//-0.045f, -0.7f,  0.38f,		// [1] front bot right
		//-0.65f,  0.7f,  0.38f,		// [2] front top left
		//-0.045f,  0.7f,  0.38f,		// [3] front top right
		//-0.65f, -0.7f,  0.30f,		// [4] back bot left
		//-0.045f, -0.7f,  0.30f,		// [5] back bot right
		//-0.65f,  0.7f,  0.30f,		// [6] back top left
		//-0.045f,  0.7f,  0.30f,		// [7] back top right

		// pembatas pintu
		-0.045f, -0.7f,  0.42f,		// [0] front bot left
		 0.045f, -0.7f,  0.42f,		// [1] front bot right
		-0.045f,  0.7f,  0.42f,		// [2] front top left
		 0.045f,  0.7f,  0.42f,		// [3] front top right
		-0.045f, -0.7f, -0.40f,		// [4] back bot left
		 0.045f, -0.7f, -0.40f,		// [5] back bot right
		-0.045f,  0.7f, -0.40f,		// [6] back top left
		 0.045f,  0.7f, -0.40f,		// [7] back top right

		// pintu kanan
		 //0.65f, -0.7f,  0.38f,		// [0] front bot left
		 //0.045f, -0.7f,  0.38f,		// [1] front bot right
		 //0.65f,  0.7f,  0.38f,		// [2] front top left
		 //0.045f,  0.7f,  0.38f,		// [3] front top right
		 //0.65f, -0.7f,  0.30f,		// [4] back bot left
		 //0.045f, -0.7f,  0.30f,		// [5] back bot right
		 //0.65f,  0.7f,  0.30f,		// [6] back top left
		 //0.045f,  0.7f,  0.30f		// [7] back top right
	};
};

#endif

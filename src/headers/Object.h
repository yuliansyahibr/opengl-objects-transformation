#ifndef OBJECT_H
#define OBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

// settings
const unsigned int SCREEN_WIDTH = 1200;
const unsigned int SCREEN_HEIGHT = 640;

struct Buffers {
	float* data;
	int sizeofdata;
};


class Object
{
public:
	//
	const int withTexture = 2;
	const int withColor = 0;
	int vertex_stride;
	//
	// jumlah kubus
	int N_Cuboids;
	// indexes
	int N_Indices;
	// n kubus * sisi kubus * 2 * triangle vert * texture coord
	int N_Vertices;

	Buffers verts;
	glm::vec3 position;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	Object() : Object(glm::vec3(0.0f)) {}
	Object(glm::vec3 pos) : Object(glm::vec3(0.0f), 0) {}
	Object(glm::vec3 pos, float initdegree);
	~Object();
	virtual void init();
	virtual Buffers getVertexBufferData();
	virtual Buffers getTextureBufferData();
	virtual Buffers getVertices();
	virtual void transform();
	virtual void update(GLFWwindow* window);
	virtual void setSize(float size);
private:

protected:
	const int indices[36] = {
		// cube
		0, 1, 2, // depan
		1, 2, 3,
		4, 0, 6, // kiri
		0, 6, 2,
		4, 5, 6, // belakang
		5, 6, 7,
		1, 5, 3, // kanan
		5, 3, 7,
		4, 5, 0, // bawah
		5, 0, 1,
		2, 3, 6, // atas
		3, 6, 7
	};
	float tex_buffer[12] = {
		 0.0f, 0.0f,
		 1.0f, 0.0f,
		 0.0f, 1.0f,

		 1.0f, 0.0f,
		 0.0f, 1.0f,
		 1.0f, 1.0f
	};
	Buffers vertex_buffer;
	Buffers texture_buffer;
	Buffers vertices;
	float init_size;
	float size;
	float pos_degree;
	float rotateX;
	float rotateY;
	float rotateZ;
	float degree;
	bool isrotating;
	float translateX;
	float translateY;
	float translateZ;

	//int getNCuboids();
	//int getNIndices();
	//int getNVertices();
	void genVertices(float* vertices, float* vbuffer, float* tbuffer);
	void transmodel();
	void transview();
	void transprojection();
	void setRotation(float* axis, float offset);
};

#endif
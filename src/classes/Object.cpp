#include <Object.h>
#include <iostream>

Object::Object(glm::vec3 pos, float init_degree)
{
	N_Cuboids = 0;
	N_Indices = 0;
	N_Vertices = 0;

	verts = { nullptr, 0 };
	position = pos;
	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	init_size = 1.0f;
	size = 1.0f;
	rotateX = 0.0f;
	rotateY = 0.0f;
	rotateZ = 0.0f;
	pos_degree = init_degree;
	degree = 0;
	isrotating = 0;
	translateX = 0.0f;
	translateY = 0.0f;
	translateZ = 0.0f;
	vertex_buffer = { nullptr, 0 };
	texture_buffer = { nullptr, 0 };
	vertices = { nullptr, 0 };
}

Object::~Object()
{
	delete vertices.data;
}

void Object::init()
{
	vertex_stride = 3 + withColor + withTexture;
	vertex_buffer = getVertexBufferData();
	texture_buffer = getTextureBufferData();
	N_Cuboids = ((vertex_buffer.sizeofdata / sizeof(float)) / 3) / 8;
	// indexes
	N_Indices = sizeof(indices) / sizeof(int);
	// n kubus * sisi kubus * 2 * triangle vert * texture coord
	N_Vertices = N_Cuboids * N_Indices * vertex_stride;
	vertices.data = new float[N_Vertices];
	vertices.sizeofdata = N_Vertices*sizeof(float);
	//std::cout << "+ " << texture_buffer.data[0] << std::endl;
	genVertices(vertices.data, vertex_buffer.data, texture_buffer.data);
}

Buffers Object::getVertexBufferData() 
{
	return {nullptr, 0};
}

Buffers Object::getTextureBufferData()
{
	return { tex_buffer, sizeof(tex_buffer) };
}

Buffers Object::getVertices()
{
	return vertices;
}

void Object::transform()
{
	transmodel();
	//transview();
	//transprojection();
}

void Object::setRotation(float* axis, float offset) 
{
	*axis += offset;
}

void Object::update(GLFWwindow* window)
{
	float rot = 0.4f;
	isrotating = false;
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			setRotation(&rotateZ, rot);
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			setRotation(&rotateZ, -rot);
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			setRotation(&rotateX, rot);
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			setRotation(&rotateX, -rot);
		}
	}
	else if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
		if(size < 4.0f)
			size += 0.006f;
	}
	else if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
		if(size > 0.1f)
			size -= 0.006f;
	}
	else {
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			translateZ -= 0.015f;
		}
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			translateZ += 0.015f;
		}
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			translateX += 0.015f;
		}
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			translateX -= 0.015f;
		}
	}

}

void Object::setSize(float s)
{
	size = s;
}

void Object::genVertices(float* vertices, float* vbuffer, float* tbuffer) {

	//float vertices[N_Vertices];
	int iVert = 0;
	for (int i = 0; i < N_Cuboids; i++)
	{
		int iPos = 0;
		int iTex = 0;
		for (int j = 0; j < N_Indices; j++)
		{
			iPos = ((i * 8) + indices[j]) * 3;
			iTex = (j % 6) * 2;
			// triangle vertex
			vertices[iVert++] = vbuffer[iPos++];
			vertices[iVert++] = vbuffer[iPos++];
			vertices[iVert++] = vbuffer[iPos++];
			// texture cord
			vertices[iVert++] = tbuffer[iTex++];
			vertices[iVert++] = tbuffer[iTex++];
		}
	}
}

void Object::transmodel()
{
	glm::mat4 base = glm::mat4(1.0f);
	model = glm::scale(model, glm::vec3(init_size));
	model = glm::translate(base, position);
	model = glm::translate(model, glm::vec3(translateX, translateY, translateZ));
	model = glm::rotate(model, glm::radians(pos_degree), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotateX), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotateZ), glm::vec3(0.0f, 0.0f, 1.0f));
	//model = glm::rotate(model, glm::radians(degree), glm::vec3(1.0f, 0.0f, 0.0f));

	model = glm::scale(model, glm::vec3(size));
}

void Object::transview()
{
	glm::mat4 base = glm::mat4(1.0f);
	view = glm::translate(base, glm::vec3(0.0f, 0.0f, -5.0f));
}

void Object::transprojection()
{
	projection = glm::perspective(glm::radians(45.0f), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
}



#include <VAO.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

VAO::VAO(Shader* inshader, Object* inobj) {
	shader = inshader;
	object = inobj;
	glGenVertexArrays(1, &ID);
	degree = 0;
}

void VAO::createBufferArray() {

	Buffers vertices = object->getVertices();
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindVertexArray(ID);
	// VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.sizeofdata, vertices.data, GL_STATIC_DRAW);

	// position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// colors
	/*glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);*/
	//// texture
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(2);
}

void VAO::createTexture(std::string img_path)
{
	const char* path = img_path.c_str();
	glBindVertexArray(ID);
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	// set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// load image, create texture and generate mipmaps
	int width, height, nrChannels;
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data)
	{
		GLenum format = GL_BGR;
		if (nrChannels == 1)
			format = GL_RED;
		else if (nrChannels == 3)
			format = GL_RGB;
		else if (nrChannels == 4)
			format = GL_RGBA;
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void VAO::update(GLFWwindow* window)
{
	object->update(window);
}

void VAO::render(glm::mat4 projection, glm::mat4 view)
{
	// bind Texture
	glBindTexture(GL_TEXTURE_2D, texture1);

	// render the triangle
	shader->use();

	object->transform();

	// retrieve the matrix uniform locations
	unsigned int modelLoc = glGetUniformLocation(shader->ID, "model");
	unsigned int viewLoc = glGetUniformLocation(shader->ID, "view");
	// pass them to the shaders (3 different ways)
	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(object->model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &(view[0][0]));
	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	shader->setMat4("projection", projection);

	/*GLuint transformLoc = glGetUniformLocation(ourShader.ID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));*/

	glBindVertexArray(ID);
	glDrawArrays(GL_TRIANGLES, 0, object->N_Vertices);
	//glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0)
}

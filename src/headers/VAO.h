#ifndef VAO_H
#define VAO_H

#include <Shader.h>
#include <Object.h>
#include <string>

class VAO
{
public:
	unsigned int ID;
	Shader* shader;
	Object* object;
	unsigned int texture1;

	float degree;

	VAO(Shader* inshader, Object* inobj);
	void createBufferArray();
	void createTexture(std::string img_path);
	void update(GLFWwindow* window);
	void render(glm::mat4 projection, glm::mat4 view);

private:


};

#endif


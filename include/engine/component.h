/*
 MIT License
 
 Copyright (c) 2017 SAE Institute Switzerland AG
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 */

#ifndef MMGGA_COMPONENT_H
#define MMGGA_COMPONENT_H
//Externals includes
#include <SFML/System.hpp>
#include <engine/game_object.h>

namespace mmgga
{
class Transform;

/**
 * \brief A GameObject Component that can be anything
 */
	
class Component
{
public:
	/**
	 * \brief Constructor of Component takes the parent GameObject as reference
	 * \param parentGameObject The parent GameObject
	 */
	Component(GameObject& parentGameObject);
	/**
	* \brief Update the Component
	* \param dt Delta time since last frame
	*/
	virtual void Update(sf::Time dt) = 0;

protected:
	GameObject& gameObject;
	Transform* transform = nullptr;
};

class Transform : public Component
{
public:
	using Component::Component;

	static Transform* LoadTransform(json componentJson, GameObject& parentGameObject);
	/**
	* \brief Update the Component
	* \param dt Delta time since last frame
	*/
	void Update(sf::Time dt) override;
	/**
	* \brief Get the Euler Angle
	* \return the Euler Angle
	*/
	float GetEulerAngle();
	/**
	* \brief Set the Euler Angle
	* \param Euler Angle
	*/
	void SetEulerAngle(float eulerAngle);
	/**
	* \brief Get the position
	* \return the position
	*/
	sf::Vector2f GetPosition();
	/**
	* \brief Set the position
	* \param position
	*/
	void SetPosition(sf::Vector2f position);
	/**
	* \brief Get the Scale
	* \return the Scale
	*/
	sf::Vector2f GetScale();
	/**
	* \brief Set the Scale
	* \param Scale
	*/
	void SetScale(sf::Vector2f scale);

	json SaveTransform();

private:
	sf::Vector2f position = sf::Vector2f(0.f, 0.f);
	sf::Vector2f scale = sf::Vector2f(1.f,1.f);
	float eulerAngle = 0.f;

};
}
#endif

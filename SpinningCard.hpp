// faux-3D card spin effect

// hx::Misc::SpinningCard

// by Hapax (http://github.com/hapaxia)

// Requires:
//   C++11
//   SFML (http://sfml-dev.org)

#ifndef HX_MISC_SPINNINGCARD_HPP
#define HX_MISC_SPINNINGCARD_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace hx
{
	namespace Misc
	{

// SpinningCard (v1.0.0)
class SpinningCard : public sf::Drawable, public sf::Transformable
{
public:
	// pass the sprite that it mimics when constructing the card
	SpinningCard(const sf::Sprite& sprite);

	// rotate around the y axis (in degrees)
	void spin(float angleInDegrees);

	// rotate around the y axis (in radians)
	void spinRadians(float angleInRadians);

	// rotate around the x axis (in degrees)
	void spinVertically(float angleInDegrees);

	// rotate around the x axis (in radians)
	void spinVerticallyRadians(float angleInRadians);

	// set depth of fake perspective
	void setDepth(float depth);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::VertexArray m_vertices;
	const sf::Texture* m_pTexture;
	sf::FloatRect m_initial;
	const float m_pi;
	float m_depth;
};

	} // namespace Misc
} // namespace hx

#endif // HX_MISC_SPINNINGCARD_HPP
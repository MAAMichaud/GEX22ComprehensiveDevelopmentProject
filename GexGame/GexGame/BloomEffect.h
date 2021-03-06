/**
* author  Marc-Andre Michaud
*
*
* @section DESCRIPTION
*  Gex Game
*  Based SFML Game Development Textbook
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*/
#pragma once

#include "PostEffect.h"

#include <array>
#include <map>
#include <memory>

#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/System/Vector2.hpp>



class BloomEffect : public PostEffect
{
public:

	enum class Shaders
	{
		BrightnessPass,
		DownSamplePass,
		GaussianBlurPass,
		AddPass,
	};


public:
				BloomEffect();

	void		apply(const sf::RenderTexture& input, sf::RenderTarget& output) override;


private:
	typedef std::array<sf::RenderTexture, 2> RenderTextureArray;


private:
	void				prepareTextures(sf::Vector2u size);

	void				filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				blurMultipass(RenderTextureArray& renderTextures);
	void				blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
	void				downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
	void				add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& output);


private:
	std::map<Shaders, std::unique_ptr<sf::Shader>>	shaders;

	sf::RenderTexture								brightnessTexture;
	RenderTextureArray								firstPassTexture;
	RenderTextureArray								secondPassTexture;
};

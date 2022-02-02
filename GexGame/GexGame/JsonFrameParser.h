/**
@file
@author  D Burchill <david.burchill@nbcc.ca>
@version 1.0 *Modified by Marc-Andre Michaud <marcandre.a.michaud@gmail.com>

@section LICENSE

This software is based on the material accompanying the book "SFML Game Development" see License.txt
These additions and modifications are my sole work for prog 1266

@section DESCRIPTION

this class is used to parse the json output in a texture atlas produced by texture 
packer with the "json array" output format. 
The constructor takes a path to the atlas
The getFramesFor(animation) returns the textureRects for the frames in that animation
*/
#pragma once

#include "json.hpp"

#include <vector>

#include <SFML/Graphics/Rect.hpp>



using nlohmann::json;



struct Frame {

	Frame(int l, int t, int w, int h, int ox, int oy) 
		: intRect(l, t, w, h)
		, offset(ox, oy)
	{}
	sf::IntRect intRect;
	std::pair<int, int> offset;

};



class JsonFrameParser
{
public:
									/**
									* Construct a jason frame parser object
									*
									* @param[in] path path to texture atlas
									*/
									JsonFrameParser(std::string path);

									/**
									* Return set of texture Rectangles for the named
									* animation. 
									* 
									* @param animationName the name of the animation, must match 
									*		 the begining of the name string for the animation in the 
									*		 json file.
									*
									* @return vector of Frames that make up the animation 
									*/
	std::vector<Frame>				getFramesFor(std::string animationName) const;

private:
	json              json_;
};
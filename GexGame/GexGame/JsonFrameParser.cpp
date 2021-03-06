//
//  JsonFrameParser.cpp
//  jsoner
//
//  Created by David Burchill on 2018-10-28.
//  Copyright © 2018 David Burchill. All rights reserved.
//

#include "JsonFrameParser.h"

#include <fstream>



using json = nlohmann::json;



JsonFrameParser::JsonFrameParser(std::string path)
{
	std::ifstream ifs(path);
	json_ = json::parse(ifs);
}



Frame  JsonFrameParser::getFrame(std::string animationName) const
{
	json k = json_["frames"];


	for (auto i : k)
	{

		std::string tmpStr = i["filename"]; // animation name is the first part of "filename" string
		if (tmpStr.compare(0, animationName.size(), animationName) == 0)
		{
			if (i["rotated"])
			{
				return Frame({ i["frame"]["x"],
					i["frame"]["y"],
					i["frame"]["w"],
					i["frame"]["h"] },
					{ i["spriteSourceSize"]["x"],
					i["spriteSourceSize"]["y"] },
					i["rotated"]
				);
			}
			else
			{
				return Frame({ i["frame"]["x"],
					i["frame"]["y"],
					i["frame"]["w"],
					i["frame"]["h"] },
					{ i["spriteSourceSize"]["x"],
					i["spriteSourceSize"]["y"] },
					i["rotated"]
				);
			}
		}
	}
}



std::vector<Frame>  JsonFrameParser::getFramesFor(std::string animationName) const
{
	std::vector<Frame> data; // frame textRecs for animaionName in atlas

	json k = json_["frames"];

	for (auto i : k)
	{

		std::string tmpStr = i["filename"]; // animation name is the first part of "filename" string
		if (tmpStr.compare(0, animationName.size(), animationName) == 0)
		{
			data.push_back(Frame({ i["frame"]["x"],
				i["frame"]["y"],
				i["frame"]["w"],
				i["frame"]["h"] },
				{ i["spriteSourceSize"]["x"],
				i["spriteSourceSize"]["y"] },
				i["rotated"]
			));
		}
	}

	return data;
}

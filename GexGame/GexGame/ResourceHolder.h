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
#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>



template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	void				load(Identifier id, const std::string& filename);
	template <typename Parameter>
	void				load(Identifier id, const std::string& filename, const Parameter& secondParam);

	Resource&			get(Identifier id);
	const Resource&		get(Identifier id) const;

private:
	void				insertResource(Identifier id, std::unique_ptr<Resource> resource);

private:
	std::map<Identifier, std::unique_ptr<Resource>> resourceMap;

};



template <typename Resource, typename Identifier>
void ResourceHolder<typename Resource, typename Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource)
{
	auto inserted{ resourceMap.insert(std::make_pair(id, std::move(resource))) };
	assert(inserted.second);
}



template <typename Resource, typename Identifier>
void ResourceHolder<typename Resource, typename Identifier>::load(Identifier id, const std::string& filename)
{
	auto resource{ std::make_unique<Resource>() };
	if (!resource->loadFromFile(filename))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	insertResource(id, std::move(resource));
}



template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<typename Resource, typename Identifier>::load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
	auto resource{ std::make_unique<Resource>() };
	if (!resource->loadFromFile(filename, secondParam))
	{
		throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
	}

	insertResource(id, std::move(resource));
}



template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found{ resourceMap.find(id) };
	assert(found != resourceMap.end());

	return *found->second;
}



template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found{ resourceMap.find(id) };
	assert(found != resourceMap.end());

	return *found->second;
}

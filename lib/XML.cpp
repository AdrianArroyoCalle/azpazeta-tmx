/* Starts reading the XML file */

#include "../tinyxml2/tinyxml2.h"

#include <iostream>

typedef struct {
	TiXmlProperties *properties, *property, *tileset, *layer, *data, *tile;
} AzpazetaTMX;

XML::XML(std::string file)
{
	TiXmlDocument doc(file);
	if(!doc.LoadFile())
	{
		std::cerr << "ERROR LOADING FILE" << std::endl;	
	}
	TiXmlProperties *property;
}
XML::~XML()
{
	
}

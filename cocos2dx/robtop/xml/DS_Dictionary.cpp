#include "DS_Dictionary.h"

// source: https://forum.cocosengine.org/t/c-c-plist-reader-parser/1256/4
// fun fact: the DS stands for DigitalSynapses, which is the guy who originally made this
using namespace std;
using namespace cocos2d;
using namespace pugi;

#include "DS_Dictionary_Extra.h"

#define DS_DEBUG_MODE 0

#define COMPAT_STR(str) (m_compatible ? str : (const char[2]){str[0], 0})

//Constructor
DS_Dictionary::DS_Dictionary()
{
    //Initializers
    dictTree.push_back(xml_node());

    //Create default format
    xml_node plistNode = doc.append_child("plist");
    plistNode.append_attribute("version") = "1.0";
    plistNode.append_child("dict");

    //Set root dictTree node
    dictTree.back() = doc.child("plist").child("dict");
}

DS_Dictionary::~DS_Dictionary() {}

CCDictionary* DS_Dictionary::getDictForKey(char const* key)
{
	// nahh like if im ever gonna decompile this
	return CCDictionary::create();
}

void DS_Dictionary::setDictForKey(char const* key, CCDictionary* dict)
{

}

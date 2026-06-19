#include "DS_Dictionary.h"

// source: https://forum.cocosengine.org/t/c-c-plist-reader-parser/1256/4
// other source: https://github.com/matcool/cocos2d-x-gd/blob/main/cocos2dx/robtop/xml/DS_Dictionary.cpp
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

//Private methods
string DS_Dictionary::cleanStringWhiteSpace(const string& _str)
{
	string cleanStr = _str;
	cleanStr.erase(remove_if(cleanStr.begin(), cleanStr.end(), static_cast<int(*)(int)>(isspace)), cleanStr.end());
	return cleanStr;
}

void DS_Dictionary::split(const string& src, const char* token, vector<string>& vect)
{
	int nend = 0;
	int nbegin = 0;
	while (nend != -1)
	{
		nend = src.find(token, nbegin);
		if (nend == -1)
			vect.push_back(src.substr(nbegin, src.length() - nbegin));
		else
			vect.push_back(src.substr(nbegin, nend - nbegin));
		nbegin = nend + strlen(token);
	}
}


bool DS_Dictionary::stepIntoSubDictWithKey(const char* key)
{
	/*for (xml_node node = dictTree.back().child(COMPAT_STR("key")); node; node = node.next_sibling(COMPAT_STR("key")))
	{
		if (node.child_value() == string(key) && node.next_sibling() == node.next_sibling(COMPAT_STR("dict")))
		{
			dictTree.push_back(node.next_sibling());
			return true;
		}
	}

	if (DS_DEBUG_MODE){ printf("%s \n", string("DS_ENGINE:> :ERROR: FAILED TO STEP INTO XML DICTIONARY WITH KEY: ").append(key).c_str()); }*/
	return false;
}

void DS_Dictionary::stepOutOfSubDict()
{
	if (dictTree.size() > 1)
	{
		dictTree.pop_back();
	}
}

CCDictionary* DS_Dictionary::getDictForKey(char const* key) {
	if (key == nullptr || this->stepIntoSubDictWithKey(key)) {
	

		if (key) {
			stepOutOfSubDict();
		}

	}
	else {
		return CCDictionary::create();
	}
}

void DS_Dictionary::setDictForKey(char const* key, CCDictionary* dict)
{

}

CCArray* DS_Dictionary::getArrayForKey(char const* key) {
	return CCArray::create();
}

bool DS_Dictionary::saveRootSubDictToFile(char const* file)
{
	return true;
}
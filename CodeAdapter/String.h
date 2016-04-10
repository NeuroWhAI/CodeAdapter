#ifndef __CA__STRING_H__
#define __CA__STRING_H__


#include <string>

#include "Definition.h"
#include "CAType.h"




BEGIN_NAMESPACE_CA_UTILITY


class String
{
public:
	String();
	String(String&& rhs);
	String(const std::string& str);
	String(const std::wstring& wstr);
	virtual ~String();


protected:
	std::string m_str;
	std::wstring m_wstr;


public:
	const char* getStr() const;
	void getStr(std::string* pOut) const;
	
	const wchar_t* getWStr() const;
	void getStr(std::wstring* pOut) const;


public:
	void setStr(const std::string& str);
	void setStr(const std::wstring& wstr);


public:
	operator std::string() const;
	operator std::wstring() const;

	String& operator= (const std::string& right);
	String& operator= (const std::wstring& right);

	bool operator== (const String& right) const;
	bool operator== (const std::string& right) const;
	bool operator== (const std::wstring& right) const;
	bool operator!= (const String& right) const;
	bool operator!= (const std::string& right) const;
	bool operator!= (const std::wstring& right) const;
};


END_NAMESPACE_CA_UTILITY


bool operator== (const std::string& left,
	const CodeAdapter::Utility::String& right);
bool operator== (const std::wstring& left,
	const CodeAdapter::Utility::String& right);
bool operator!= (const std::string& left,
	const CodeAdapter::Utility::String& right);
bool operator!= (const std::wstring& left,
	const CodeAdapter::Utility::String& right);


#endif
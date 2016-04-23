#ifndef __CA__STRING_H__
#define __CA__STRING_H__


#include <string>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class String
{
public:
	String();
	String(const String& other);
	String(String&& rhs);
	String(const char str[]);
	String(const std::string& str);
	String(const wchar_t wstr[]);
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
	explicit operator std::string() const;
	explicit operator std::wstring() const;

	String& operator= (const String& right);

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
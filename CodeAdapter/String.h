#ifndef __CA__STRING_H__
#define __CA__STRING_H__


#include <string>

#include "BasicDeclaration.h"




BEGIN_NAMESPACE_CA_UTILITY


class String
{
public:
	class Hasher
	{
	public:
		size_t operator() (const String& str) const
		{
			return std::hash<std::wstring>()(static_cast<std::wstring>(str));
		}
	};


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


protected:
	void updateStr();


public:
	const char* getStr() const;
	void getStr(std::string* pOut) const;
	
	const wchar_t* getWStr() const;
	void getStr(std::wstring* pOut) const;


public:
	void setStr(const std::string& str);
	void setStr(const std::wstring& wstr);

	void addStr(const std::string& str);
	void addStr(const std::wstring& wstr);

	void addChar(char ch);
	void addChar(wchar_t wch);

	void InsertStr(const std::string& str, i32 index);
	void InsertStr(const std::wstring& wstr, i32 index);

	void InsertChar(char ch, i32 index);
	void InsertChar(wchar_t wch, i32 index);

	void eraseAt(i32 index);
	void eraseRange(i32 begin, i32 count);
	void eraseToEnd(i32 begin);


public:
	i32 getLength() const;


public:
	explicit operator std::string() const;
	explicit operator std::wstring() const;

	String& operator= (const String& right);
	String operator+ (const String& right) const;
	String& operator+= (const String& right);

	bool operator== (const String& right) const;
	bool operator== (const std::string& right) const;
	bool operator== (const std::wstring& right) const;
	bool operator!= (const String& right) const;
	bool operator!= (const std::string& right) const;
	bool operator!= (const std::wstring& right) const;
};


END_NAMESPACE_CA_UTILITY


CodeAdapter::Utility::String operator+ (const std::string& left,
	const CodeAdapter::Utility::String& right);
CodeAdapter::Utility::String operator+ (const std::wstring& left,
	const CodeAdapter::Utility::String& right);

bool operator== (const std::string& left,
	const CodeAdapter::Utility::String& right);
bool operator== (const std::wstring& left,
	const CodeAdapter::Utility::String& right);
bool operator!= (const std::string& left,
	const CodeAdapter::Utility::String& right);
bool operator!= (const std::wstring& left,
	const CodeAdapter::Utility::String& right);


#endif
#include "String.h"




BEGIN_NAMESPACE_CA_UTILITY


String::String()
{

}


String::String(const String& other)
	: m_str(other.m_str)
	, m_wstr(other.m_wstr)
{

}


String::String(String&& rhs)
	: m_str(std::move(rhs.m_str))
	, m_wstr(std::move(rhs.m_wstr))
{

}


String::String(const char str[])
{
	setStr(str);
}


String::String(const std::string& str)
{
	setStr(str);
}


String::String(const wchar_t wstr[])
{
	setStr(wstr);
}


String::String(const std::wstring& wstr)
{
	setStr(wstr);
}


String::~String()
{

}

//###########################################################################

const char* String::getStr() const
{
	return m_str.c_str();
}


void String::getStr(std::string* pOut) const
{
	*pOut = m_str;
}

//--------------------------------------------------------------------------

const wchar_t* String::getWStr() const
{
	return m_wstr.c_str();
}


void String::getStr(std::wstring* pOut) const
{
	*pOut = m_wstr;
}

//###########################################################################

void String::setStr(const std::string& str)
{
	m_str = str;

	m_wstr.assign(str.begin(), str.end());
}


void String::setStr(const std::wstring& wstr)
{
	m_wstr = wstr;

	m_str.assign(wstr.begin(), wstr.end());
}

//###########################################################################

String::operator std::string() const
{
	return m_str;
}


String::operator std::wstring() const
{
	return m_wstr;
}

//--------------------------------------------------------------------------

String& String::operator= (const String& right)
{
	m_str = right.m_str;
	m_wstr = right.m_wstr;
	return *this;
}

//--------------------------------------------------------------------------

bool String::operator== (const String& right) const
{
	return (m_wstr == right.m_wstr);
}


bool String::operator== (const std::string& right) const
{
	return (m_str == right);
}


bool String::operator== (const std::wstring& right) const
{
	return (m_wstr == right);
}


bool String::operator!= (const String& right) const
{
	return (m_wstr != right.m_wstr);
}


bool String::operator!= (const std::string& right) const
{
	return (m_str != right);
}


bool String::operator!= (const std::wstring& right) const
{
	return (m_wstr != right);
}


END_NAMESPACE_CA_UTILITY


bool operator== (const std::string& left,
	const CodeAdapter::Utility::String& right)
{
	return (right == left);
}


bool operator== (const std::wstring& left,
	const CodeAdapter::Utility::String& right)
{
	return (right == left);
}


bool operator!= (const std::string& left,
	const CodeAdapter::Utility::String& right)
{
	return (right != left);
}


bool operator!= (const std::wstring& left,
	const CodeAdapter::Utility::String& right)
{
	return (right != left);
}


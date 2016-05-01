#ifndef __DEFINITION_H__
#define __DEFINITION_H__


#define BEGIN_NAMESPACE_CA namespace CodeAdapter {
#define END_NAMESPACE_CA }

#define BEGIN_NAMESPACE_CA_DRAWING BEGIN_NAMESPACE_CA namespace Drawing {
#define END_NAMESPACE_CA_DRAWING } END_NAMESPACE_CA

#define BEGIN_NAMESPACE_CA_AUDIO BEGIN_NAMESPACE_CA namespace Audio {
#define END_NAMESPACE_CA_AUDIO } END_NAMESPACE_CA

#define BEGIN_NAMESPACE_CA_SYSTEM BEGIN_NAMESPACE_CA namespace System {
#define END_NAMESPACE_CA_SYSTEM } END_NAMESPACE_CA

#define BEGIN_NAMESPACE_CA_NETWORK BEGIN_NAMESPACE_CA namespace Network {
#define END_NAMESPACE_CA_NETWORK } END_NAMESPACE_CA

#define BEGIN_NAMESPACE_CA_UTILITY BEGIN_NAMESPACE_CA namespace Utility {
#define END_NAMESPACE_CA_UTILITY } END_NAMESPACE_CA

#define BEGIN_NAMESPACE_CA_UI BEGIN_NAMESPACE_CA namespace UI {
#define END_NAMESPACE_CA_UI } END_NAMESPACE_CA


#define USING_CA(item) using item = ::CodeAdapter::item
#define USING_CA_DRAWING(item) using item = ::CodeAdapter::Drawing::item
#define USING_CA_AUDIO(item) using item = ::CodeAdapter::Audio::item
#define USING_CA_SYSTEM(item) using item = ::CodeAdapter::System::item
#define USING_CA_NETWORK(item) using item = ::CodeAdapter::Network::item
#define USING_CA_UTILITY(item) using item = ::CodeAdapter::Utility::item
#define USING_CA_UI(item) using item = ::CodeAdapter::UI::item

#define USING_CA_T(item, type) template <typename type> using item = ::CodeAdapter::item<type>
#define USING_CA_DRAWING_T(item, type) template <typename type> using item = ::CodeAdapter::Drawing::item<type>
#define USING_CA_AUDIO_T(item, type) template <typename type> using item = ::CodeAdapter::Audio::item<type>
#define USING_CA_SYSTEM_T(item, type) template <typename type> using item = ::CodeAdapter::System::item<type>
#define USING_CA_NETWORK_T(item, type) template <typename type> using item = ::CodeAdapter::Network::item<type>
#define USING_CA_UTILITY_T(item, type) template <typename type> using item = ::CodeAdapter::Utility::item<type>
#define USING_CA_UI_T(item, type) template <typename type> using item = ::CodeAdapter::UI::item<type>


#endif
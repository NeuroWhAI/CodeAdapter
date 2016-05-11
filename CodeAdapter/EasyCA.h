#ifndef __CA__EASY_CA_H__
#define __CA__EASY_CA_H__


#include <memory>

#include "CodeAdapter.h"




using namespace CodeAdapter;
namespace ca = CodeAdapter;
namespace caDraw = ca::Drawing;
namespace caAudio = ca::Audio;
namespace caSys = ca::System;
namespace caNet = ca::Network;
namespace caUtil = ca::Utility;
namespace caUI = ca::UI;


template <typename T>
void initializeCA();


template <typename T>
std::shared_ptr<T> canew();

template <typename T, typename... Args>
std::shared_ptr<T> canew(Args&&... args);


extern caUtil::SingletonWrapper<ca::Factory> caFactory;
extern caUtil::SingletonWrapper<caSys::Touch> caTouch;
extern caUtil::SingletonWrapper<caSys::Keyboard> caKeyboard;


#include "EasyCA.inl"


#endif
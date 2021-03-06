#ifndef __BASIC_DECLARAION_H__
#define __BASIC_DECLARAION_H__


#include <memory>


// Code Adapter ------------------------------------------------------------
#include "Definition.h"
#include "CAType.h"


// Macro -------------------------------------------------------------------
#define PtrClass(name) class name; using name##Ptr = std::shared_ptr<name>;


// Drawing -----------------------------------------------------------------
BEGIN_NAMESPACE_CA_DRAWING


// * Interface
class Drawable;
class Updatable;

// * Basic Element
template <typename T>
class PointT;
using Point = PointT<i32>;
using PointF = PointT<f32>;

template <typename T>
class SizeT;
using Size = SizeT<i32>;
using SizeF = SizeT<f32>;

template <typename T>
class VectorT;
using Vector = VectorT<i32>;
using VectorF = VectorT<f32>;

template <typename T>
class RectangleT;
using Rectangle = RectangleT<i32>;
using RectangleF = RectangleT<f32>;

template <typename T>
class LineT;
using Line = LineT<i32>;
using LineF = LineT<f32>;

template <typename T>
class ColorT;
using Color = ColorT<i32>;
using ColorF = ColorT<f32>;

class Transform;

// * GUI
PtrClass(Window);
PtrClass(Panel);

// * Paint
class Graphics;
PtrClass(Artist);
PtrClass(TextArtist);
PtrClass(RectangleArtist);
PtrClass(EllipseArtist);
PtrClass(LineArtist);
PtrClass(TextureArtist);
PtrClass(DrawableRectangle);
PtrClass(DrawableEllipse);
PtrClass(DrawableLine);
PtrClass(DrawableText);
PtrClass(DrawableTexture);
PtrClass(Font);
PtrClass(Texture);


END_NAMESPACE_CA_DRAWING


// System ------------------------------------------------------------------
BEGIN_NAMESPACE_CA_SYSTEM


PtrClass(Touch);
enum class Keys;
PtrClass(Keyboard);
class WindowEvent;


END_NAMESPACE_CA_SYSTEM


// Audio -------------------------------------------------------------------
BEGIN_NAMESPACE_CA_AUDIO


PtrClass(Sound);


END_NAMESPACE_CA_AUDIO


// Network -----------------------------------------------------------------
BEGIN_NAMESPACE_CA_NETWORK


//#include ...


END_NAMESPACE_CA_NETWORK


// Utility -----------------------------------------------------------------
BEGIN_NAMESPACE_CA_UTILITY


class String;

template <typename T>
class SharedObject;

class Sharable;
class UsingSharable;

template <typename T>
class SingletonWrapper;

template <typename... ArgTypes>
class Event;

PtrClass(Scene);
PtrClass(SceneManager);
PtrClass(ResourcePool);


END_NAMESPACE_CA_UTILITY


// UI ----------------------------------------------------------------------
BEGIN_NAMESPACE_CA_UI


PtrClass(Control);
PtrClass(Label);
PtrClass(Button);
PtrClass(ScrollBar);
PtrClass(VerticalScrollBar);
PtrClass(HorizontalScrollBar);
PtrClass(TextBox);
PtrClass(CheckBox);
PtrClass(ProgressBar);
PtrClass(RadioButton);
PtrClass(RadioButtonGroup);
PtrClass(ListBox);


END_NAMESPACE_CA_UI


// Clear -------------------------------------------------------------------
#undef PtrClass


#endif
#ifndef __BASIC_DECLARAION_H__
#define __BASIC_DECLARAION_H__


// Code Adapter ------------------------------------------------------------
#include "Definition.h"
#include "CAType.h"


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
class Window;
class Panel;

// * Paint
class Graphics;
class Artist;
class TextArtist;
class RectangleArtist;
class EllipseArtist;
class LineArtist;
class TextureArtist;
class DrawableRectangle;
class DrawableEllipse;
class DrawableLine;
class DrawableText;
class DrawableTexture;
class Font;
class Texture;


END_NAMESPACE_CA_DRAWING


// System ------------------------------------------------------------------
BEGIN_NAMESPACE_CA_SYSTEM


class Touch;
enum class Keys;
class Keyboard;
class WindowEvent;


END_NAMESPACE_CA_SYSTEM


// Audio -------------------------------------------------------------------
BEGIN_NAMESPACE_CA_AUDIO


//#include ...


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

class Scene;
class SceneManager;
class ResourcePool;


END_NAMESPACE_CA_UTILITY


// UI -----------------------------------------------------------------
BEGIN_NAMESPACE_CA_UI


class Control;
class Label;
class Button;
class ScrollBar;
class VerticalScrollBar;
class HorizontalScrollBar;
class TextBox;
class CheckBox;


END_NAMESPACE_CA_UI


#endif
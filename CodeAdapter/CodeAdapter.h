#ifndef __CODE_ADAPTER_H__
#define __CODE_ADAPTER_H__


// Code Adapter ------------------------------------------------------------
#include "Definition.h"
#include "CAType.h"
#include "Factory.h"


// Drawing -----------------------------------------------------------------
// * Interface
#include "Drawable.h"
#include "Updatable.h"

// * Basic Element
#include "Point.h"
#include "Size.h"
#include "Vector.h"
#include "Rectangle.h"
#include "Line.h"
#include "Color.h"
#include "Transform.h"
#include "TextAligns.h"

// * GUI
#include "Window.h"
#include "Panel.h"

// * Paint
#include "Graphics.h"
#include "Artist.h"
#include "TextArtist.h"
#include "RectangleArtist.h"
#include "EllipseArtist.h"
#include "LineArtist.h"
#include "TextureArtist.h"
#include "DrawableRectangle.h"
#include "DrawableEllipse.h"
#include "DrawableLine.h"
#include "DrawableText.h"
#include "DrawableTexture.h"
#include "Font.h"
#include "Texture.h"


// System ------------------------------------------------------------------
#include "Touch.h"
#include "Keys.h"
#include "Keyboard.h"
#include "WindowEvent.h"


// Audio -------------------------------------------------------------------
//#include ...


// Network -----------------------------------------------------------------
//#include ...


// Utility -----------------------------------------------------------------
#include "String.h"
#include "SharedObject.h"
#include "Sharable.h"
#include "UsingSharable.h"
#include "SingletonWrapper.h"
#include "Event.h"


// UI -----------------------------------------------------------------
#include "Control.h"
#include "ControlEvent.h"
#include "Label.h"
#include "Button.h"
#include "ScrollBar.h"
#include "VerticalScrollBar.h"
#include "HorizontalScrollBar.h"
#include "TextBox.h"


#endif
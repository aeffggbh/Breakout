#include "UIManager.h"
#include "sl.h"


namespace UIManager
{
	static int mainFont;
	static int titleFont1;
	static int titleFont2;
	
	bool IsMouseOnButton(Button button)
	{
		if (slGetMouseX() > button.shape.pos.x &&
			slGetMouseY() > button.shape.pos.y &&
			slGetMouseX() < (button.shape.pos.x + button.shape.width) &&
			slGetMouseY() < (button.shape.pos.y + button.shape.height))
		{
			return true;
		}
		return false;
	}

	void DrawButtonText(Button button)
	{
		SetForeColor(button.textShown.currentColor);
		slSetFont(mainFont, button.textShown.fontSize);
		double posX = button.shape.pos.x + button.shape.width / 2;
		double posY = button.shape.pos.y + button.shape.height / 2 - button.textShown.fontSize * 2/5;
		slText(posX, posY, button.textShown.content.data());
	}

	void DrawButtonRect(Button button)
	{
		SetForeColor(button.currentColor);
		slRectangleFill(button.shape.pos.x+button.shape.width/2, button.shape.pos.y + button.shape.height/2, button.shape.width, button.shape.height);
	}

	void PrintText(Text myText, int align)
	{
		SetForeColor(myText.currentColor);
		slSetFont(mainFont, myText.fontSize);
		slSetTextAlign(align);
		slText(myText.location.x, myText.location.y, myText.content.data());
	}
	
	void PrintText(Text myText)
	{
		SetForeColor(myText.currentColor);
		slSetFont(mainFont, myText.fontSize);
		slSetTextAlign(SL_ALIGN_CENTER);
		slText(myText.location.x, myText.location.y, myText.content.data());
	}

	static int GetFont(Fonts font)
	{
		switch (font)
		{
		case Fonts::mainFont:
			return mainFont;
			break;
		case Fonts::titleFont1:
			return titleFont1;
			break;
		case Fonts::titleFont2:
			return titleFont2;
			break;
		default:
			return mainFont;
			break;
		}
	}

	void PrintText(Text myText, int align, Fonts font)
	{
		int fontUsed = GetFont(font);
		
		SetForeColor(myText.currentColor);
		slSetFont(fontUsed, myText.fontSize);
		slSetTextAlign(align);
		slText(myText.location.x, myText.location.y, myText.content.data());
	}
	
	void InitFonts()
	{
		mainFont = slLoadFont("res/fonts/RubikMonoOne-Regular.ttf");
		titleFont1 = slLoadFont("res/fonts/eddie.ttf");
		titleFont2 = slLoadFont("res/fonts/DonGraffiti.otf");
	}

	Text GetText(float x, float y, int fontSize, string content, ColorManager::Colors color)
	{
		Text myText;

		myText.currentColor = color;
		myText.content = content;
		myText.fontSize = fontSize;
		myText.location.x = x;
		myText.location.y = y;

		return myText;
	}

	Text GetText(float x, float y, int fontSize, string content, ColorManager::Colors color1, ColorManager::Colors color2)
	{
		Text myText;

		myText.fontSize = fontSize;
		myText.alt1Color = color1;
		myText.alt2Color = color2;
		myText.currentColor = myText.alt1Color;
		myText.content = content;
		myText.location.x = x;
		myText.location.y = y;

		return myText;
	}

	Button GetButton(float x, float y, int width, int height, string content, int fontSize, ColorManager::Colors mainColor, ColorManager::Colors highlightColor)
	{
		Button myButton;
		myButton.defaultColor = mainColor;
		myButton.currentColor = myButton.defaultColor;
		myButton.highlightColor = highlightColor;
		myButton.shape.width = width;
		myButton.shape.height = height;
		myButton.shape.pos.x = x;
		myButton.shape.pos.y = y;
		myButton.textShown.content = content;
		myButton.textShown.fontSize = fontSize;
		myButton.textShown.currentColor = ColorManager::WHITE;
		return myButton;
	}

	double GetTextWidth(string content, int fontSize, Fonts font)
	{
		double width = 0;
		int fontUsed = GetFont(font);
		slSetFont(fontUsed, fontSize);

		width = slGetTextWidth(content.data());

		return width;
	}
	
	double GetTextWidth(Text text, Fonts font)
	{
		double width = 0;
		int fontUsed = GetFont(font);
		slSetFont(fontUsed, text.fontSize);

		width = slGetTextWidth(text.content.data());

		return width;
	}
	
	double GetTextHeight(string content, int fontSize, Fonts font)
	{
		int fontUsed = GetFont(font);
		slSetFont(fontUsed, fontSize);

		return slGetTextHeight(content.data());
	}

	double GetTextHeight(Text text, Fonts font)
	{
		int fontUsed = GetFont(font);
		slSetFont(fontUsed, text.fontSize);

		return slGetTextHeight(text.content.data());
	}


}


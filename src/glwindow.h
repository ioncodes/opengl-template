#pragma once
#include <windows.h>

class GlWindow
{
public:
	HDC hDC() const
	{
		return m_hDC;
	}
	HWND hWnd() const
	{
		return m_hWnd;
	}
	HGLRC hGLRC() const
	{
		return m_hGLRC;
	}
	HINSTANCE hInstance() const
	{
		return m_hInstance;
	}
	void ResizeWindow(UINT uWidth, UINT uHeight);
	void Destroy();
	void Loop();
	bool Init();
	void Update();
	void Show();
	const wchar_t* className() const
	{
		return m_className;
	}
	const wchar_t* windowTitle() const
	{
		return m_windowTitle;
	}
	GlWindow(wchar_t *className, wchar_t *windowTitle);
private:
	HDC m_hDC;
	HWND m_hWnd;
	HGLRC m_hGLRC;
	HINSTANCE m_hInstance;
	const wchar_t *m_className;
	const wchar_t *m_windowTitle;
};
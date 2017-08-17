#include "glwindow.h"
#include <GL/gl.h>

GlWindow::GlWindow(wchar_t *className, wchar_t *windowTitle)
{
	m_className = className;
	m_windowTitle = windowTitle;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

bool GlWindow::Init()
{
	ShowCursor(TRUE);
	m_hInstance = GetModuleHandle(NULL);
	if (m_hInstance == NULL)
	{
		return false;
	}

	WNDCLASS wc;

	wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_className;

	if (RegisterClass(&wc) == 0)
	{
		return false;
	}

	m_hWnd = CreateWindow(
	             m_className,
	             m_windowTitle,
	             WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
	             CW_USEDEFAULT, CW_USEDEFAULT,
	             CW_USEDEFAULT, CW_USEDEFAULT,
	             NULL,
	             NULL,
	             m_hInstance,
	             NULL
	         );

	PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,                             // version number
		PFD_DRAW_TO_WINDOW |           // support window
		PFD_SUPPORT_OPENGL |           // support OpenGL
		PFD_DOUBLEBUFFER,              // double buffered
		PFD_TYPE_RGBA,                 // RGBA type
		32,                            // 32-bit color depth
		0, 0, 0, 0, 0, 0,              // color bits ignored
		0,                             // no alpha buffer
		0,                             // shift bit ignored
		0,                             // no accumulation buffer
		0, 0, 0, 0,                    // accumulation bits ignored
		32,                            // 32-bit z buffer
		0,                             // no stencil buffer
		0,                             // no auxiliary buffer
		PFD_MAIN_PLANE,                // main layer
		0,                             // reserved
		0, 0, 0,                       // layer masks ignored
	};

	m_hDC = GetDC(m_hWnd);
	SetPixelFormat(m_hDC, ChoosePixelFormat(m_hDC, &pfd), &pfd);
	m_hGLRC = wglCreateContext(m_hDC);
	wglMakeCurrent(m_hDC, m_hGLRC);

	return true;
}

void GlWindow::Destroy()
{
	if (m_hGLRC != NULL)
	{
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(m_hGLRC);
	}

	if (m_hDC != NULL)
	{
		ReleaseDC(m_hWnd, m_hDC);
	}

	if (m_hWnd != NULL)
	{
		DestroyWindow(m_hWnd);
	}

	WNDCLASS wc;
	if (GetClassInfo(m_hInstance, m_className, &wc) != 0)
	{
		UnregisterClass(m_className, m_hInstance);
	}
}

void GlWindow::ResizeWindow(UINT uWidth, UINT uHeight)
{
	RECT rcClient, rcWindow;

	GetClientRect(m_hWnd, &rcClient);
	GetWindowRect(m_hWnd, &rcWindow);

	MoveWindow(m_hWnd,
	           rcWindow.left,
	           rcWindow.top,
	           uWidth + (rcWindow.right - rcWindow.left) - rcClient.right,
	           uHeight + (rcWindow.bottom - rcWindow.top) - rcClient.bottom,
	           FALSE);
}

void GlWindow::Loop()
{
	MSG msg;
	bool done = false;

	while (!done)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
		{
			if (msg.message == WM_QUIT)
			{
				done = true;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		Update();
		SwapBuffers(m_hDC);

		// TODO: add delta time
	}
}

// TODO: Make this a callback event
void GlWindow::Update()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.392f, 0.584f, 0.929f, 0.0f);
	glColor3us((unsigned short)GetTickCount(), 0, 0);
	glRects(-1, -1, 1, 1);
}

void GlWindow::Show()
{
	ShowWindow(m_hWnd, SW_SHOW);
}
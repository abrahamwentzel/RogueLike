#include "Game.h"
#include <stdio.h>
#include <bx/bx.h>
#include <bgfx/platform.h>
#include <GLFW/glfw3.h>
#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
#include <GLFW/glfw3native.h>

static void glfw_errorCallback(int error, const char *description)
{
	fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

static void glfw_keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_F1 && action == GLFW_RELEASE)
		s_showStats = !s_showStats;
}

Game::Game()
{
	// Create a GLFW window without an OpenGL context.
	glfwSetErrorCallback(glfw_errorCallback);
    glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	m_window = glfwCreateWindow(1024, 768, "RogueLike", nullptr, nullptr);
	glfwSetKeyCallback(m_window, glfw_keyCallback);
	// Call bgfx::renderFrame before bgfx::init to signal to bgfx not to create a render thread.
	// Most graphics APIs must be used on the same thread that created the window.
	bgfx::renderFrame();
	// Initialize bgfx using the native window handle and window resolution.
	bgfx::Init init;
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(m_window);
#elif BX_PLATFORM_OSX
	init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	init.platformData.nwh = glfwGetWin32Window(window);
#endif
	glfwGetWindowSize(m_window, &m_width, &m_height);
	init.resolution.width = (uint32_t)m_width;
	init.resolution.height = (uint32_t)m_height;
	init.resolution.reset = BGFX_RESET_VSYNC;
    bgfx::init(init);
	// Set view 0 to the same dimensions as the window and to clear the color buffer.
	bgfx::setViewClear(m_kClearView, BGFX_CLEAR_COLOR);
	bgfx::setViewRect(m_kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
}

Game::~Game()
{
	bgfx::shutdown();
	glfwTerminate();
}

void Game::run()
{
    while (!glfwWindowShouldClose(m_window)) 
    {
        this->update();
        this->render();
	}
}



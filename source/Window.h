// These are forward declerations.
struct GLFWwindow;
typedef struct _XDisplay Display;

class GameWindow {

public:
    
    GameWindow();
    ~GameWindow();

    GameWindow& update();

    // Setters.
    GameWindow& set_width(int width);
    GameWindow& set_height(int width);

    // Getters.
    int get_width();
    int get_height();

    // Query GLFW and update the size data.
    GameWindow& update_size();

    // Checks if the window should close.
    bool should_close();

    // Native Linux stuff.
    // Not important.
    Display* get_native_display_type();
    void* get_native_window_handle();

private:

    // Handle (pointer) to the GLFW window.
    GLFWwindow* m_handle = nullptr;

    // Resolution.
    int m_width = 0;
    int m_height = 0;

};

// Will need this if we want to make the native GLFW functions cross platform.

/*
#if BX_PLATFORM_LINUX
#define GLFW_EXPOSE_NATIVE_X11
#elif BX_PLATFORM_WINDOWS
#define GLFW_EXPOSE_NATIVE_WIN32
#elif BX_PLATFORM_OSX
#define GLFW_EXPOSE_NATIVE_COCOA
#endif
*/

/*
#if BX_PLATFORM_LINUX || BX_PLATFORM_BSD
	init.platformData.ndt = glfwGetX11Display();
	init.platformData.nwh = (void*)(uintptr_t)glfwGetX11Window(m_window);
#elif BX_PLATFORM_OSX
	init.platformData.nwh = glfwGetCocoaWindow(window);
#elif BX_PLATFORM_WINDOWS
	init.platformData.nwh = glfwGetWin32Window(window);
#endif
*/

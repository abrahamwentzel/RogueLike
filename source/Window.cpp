#include "Window.h"
#include "bgfx/bgfx.h"
#include <GLFW/glfw3.h>
#include <bgfx/platform.h>
#include <bx/bx.h>
#include <stdio.h>
#define GLFW_EXPOSE_NATIVE_X11
#include <GLFW/glfw3native.h>

static void glfw_errorCallback(int error, const char *description) {
  fprintf(stderr, "GLFW error %d: %s\n", error, description);
}

static void glfw_keyCallback(GLFWwindow *window, int key, int scancode,
                             int action, int mods) {
  /* if (key == GLFW_KEY_F1 && action == GLFW_RELEASE) */
  /* s_showStats = !s_showStats; */
}

GameWindow::GameWindow() {
  // Create a native Linux (X11) window using glfw.
  glfwSetErrorCallback(glfw_errorCallback);
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  m_handle = glfwCreateWindow(1280, 720, "RogueLike", nullptr, nullptr);
  glfwSetKeyCallback(m_handle, glfw_keyCallback);
  update_size();
}

GameWindow::~GameWindow() { glfwTerminate(); }

GameWindow &GameWindow::update_size() {
  glfwGetWindowSize(m_handle, &m_width, &m_height);
  return *this;
}

int GameWindow::get_width() { return m_width; }

int GameWindow::get_height() { return m_width; }

bool GameWindow::should_close() { return glfwWindowShouldClose(m_handle); }

Display *GameWindow::get_native_display_type() { return glfwGetX11Display(); }

void *GameWindow::get_native_window_handle() {
  return (void *)(uintptr_t)glfwGetX11Window(m_handle);
}

GameWindow &GameWindow::update() {
  glfwPollEvents();
  return update_size();
}

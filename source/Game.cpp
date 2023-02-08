#include "Game.h"
#include "Window.h"
#include <bgfx/platform.h>

Game::Game()
{
  // Create the window.
  m_window = std::make_unique<GameWindow>();

  // Init BGFX.
  // Maybe move to seperate class? @Abraham.
  bgfx::renderFrame();
  bgfx::Init init;
  init.platformData.ndt  = m_window->get_native_display_type();
  init.platformData.nwh  = m_window->get_native_window_handle();
  init.resolution.width  = (uint32_t)m_window->get_width();
  init.resolution.height = (uint32_t)m_window->get_height();
  init.resolution.reset  = BGFX_RESET_VSYNC;
  bgfx::init(init);
  bgfx::setViewClear(m_kClearView, BGFX_CLEAR_COLOR);
  bgfx::setViewRect(m_kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
}

Game::~Game()
{
  // Shutdown BGFX.
  bgfx::shutdown();
}

void Game::run()
{
  while (!m_window->should_close())
  {
    // Update the game.
    update();
    // Render everything in the game.
    render();
  }
}

#include "../assets/logo.h"
#include "GLFW/glfw3.h"
#include "Game.h"
#include "Window.h"
#include "bgfx/bgfx.h"
#include "bx/bx.h"

void Game::render()
{
  // Get window data.
  int width  = m_window->get_width();
  int height = m_window->get_height();

  // Ensure window is cleared.
  bgfx::touch(m_kClearView);

  // Use debug font to print information about this example.
  bgfx::dbgTextClear();

  bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(width / 2 / 8), 20) - 20,
                     bx::max<uint16_t>(uint16_t(height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
  bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
  bgfx::dbgTextPrintf(0, 1, 0x0f,
                      "Color can be changed with ANSI "
                      "\x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b["
                      "14;me\x1b[0m code too.");
  bgfx::dbgTextPrintf(80, 1, 0x0f,
                      "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; "
                      "5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
  bgfx::dbgTextPrintf(80, 2, 0x0f,
                      "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    "
                      "\x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
  const bgfx::Stats* stats = bgfx::getStats();
  bgfx::dbgTextPrintf(0, 2, 0x0f,
                      "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.",
                      stats->width, stats->height, stats->textWidth, stats->textHeight);
  // Enable stats or debug text.
  bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
  // Advance to next frame. Process submitted rendering primitives.
  bgfx::frame();
}

void Game::update()
{
  // Get the window size before it updates.
  int old_width  = m_window->get_width();
  int old_height = m_window->get_height();

  // GLWM events.
  m_window->update();

  // Now get the window size after it updated.
  int width  = m_window->get_width();
  int height = m_window->get_height();

  // GLFW Resize.
  if (width != old_width || height != old_height)
  {
    bgfx::reset((uint32_t)width, (uint32_t)height, BGFX_RESET_VSYNC);
    bgfx::setViewRect(m_kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
  }
}

#include "Game.h"
#include "bgfx/bgfx.h"
#include "bx/bx.h"
#include "GLFW/glfw3.h"
#include "../assets/logo.h"

void Game::render()
{
    // Ensure window is cleared.
	bgfx::touch(m_kClearView);
        
	// Use debug font to print information about this example.
	bgfx::dbgTextClear();

	bgfx::dbgTextImage(bx::max<uint16_t>(uint16_t(m_width / 2 / 8), 20) - 20, bx::max<uint16_t>(uint16_t(m_height / 2 / 16), 6) - 6, 40, 12, s_logo, 160);
	bgfx::dbgTextPrintf(0, 0, 0x0f, "Press F1 to toggle stats.");
	bgfx::dbgTextPrintf(0, 1, 0x0f, "Color can be changed with ANSI \x1b[9;me\x1b[10;ms\x1b[11;mc\x1b[12;ma\x1b[13;mp\x1b[14;me\x1b[0m code too.");
	bgfx::dbgTextPrintf(80, 1, 0x0f, "\x1b[;0m    \x1b[;1m    \x1b[; 2m    \x1b[; 3m    \x1b[; 4m    \x1b[; 5m    \x1b[; 6m    \x1b[; 7m    \x1b[0m");
	bgfx::dbgTextPrintf(80, 2, 0x0f, "\x1b[;8m    \x1b[;9m    \x1b[;10m    \x1b[;11m    \x1b[;12m    \x1b[;13m    \x1b[;14m    \x1b[;15m    \x1b[0m");
	const bgfx::Stats* stats = bgfx::getStats();
	bgfx::dbgTextPrintf(0, 2, 0x0f, "Backbuffer %dW x %dH in pixels, debug text %dW x %dH in characters.", stats->width, stats->height, stats->textWidth, stats->textHeight);
	// Enable stats or debug text.
	bgfx::setDebug(s_showStats ? BGFX_DEBUG_STATS : BGFX_DEBUG_TEXT);
	// Advance to next frame. Process submitted rendering primitives.
	bgfx::frame();
}

void Game::update()
{
    // GLWM events.
	glfwPollEvents();

    // GLFW Resize.
	int oldWidth = m_width, oldHeight = m_height;
	glfwGetWindowSize(m_window, &m_width, &m_height);
	if (m_width != oldWidth || m_height != oldHeight) {
		bgfx::reset((uint32_t)m_width, (uint32_t)m_height, BGFX_RESET_VSYNC);
		bgfx::setViewRect(m_kClearView, 0, 0, bgfx::BackbufferRatio::Equal);
	}
}
#include "bgfx/bgfx.h"
#include <memory>

static bool s_showStats = false;

class GameWindow;
struct GLFWwindow;

class Game
{

  public:
	Game();
	~Game();

	void run();
	void update();
	void render();

  private:
	std::unique_ptr<GameWindow> m_window;
	const bgfx::ViewId m_kClearView = 0;
};

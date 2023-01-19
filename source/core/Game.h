struct GLFWwindow;
#include "bgfx/bgfx.h"

static bool s_showStats = false;

class Game {

public:

    Game();
    ~Game();
    
    void run();
    void update();
    void render();

private:

    GLFWwindow* m_window = nullptr;
	const bgfx::ViewId m_kClearView = 0;
    int m_width = 0;
    int m_height = 0;

    // Entities.

};

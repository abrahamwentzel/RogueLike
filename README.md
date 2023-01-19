# RogueLike

Roguelike game written in C++.  Using [bgfx](https://github.com/bkaradzic/bgfx) to render graphics.

## Building

```Bash
cd third-party/bgfx
make linux-release64 # Or other platform.
cd ../../
mkdir build
cd build
cmake ../
cmake --build .
```

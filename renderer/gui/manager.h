#ifndef KASUMI_MANAGER_H
#define KASUMI_MANAGER_H

#include "scene/scene.h"
#include "scene/undo.h"
#include "simulate.h"

#include <memory>
#include <map>

namespace Kasumi
{
class Manager
{
public:
    void render(const ScenePtr& scene, float &start_x, float &start_y);
    auto quit() -> bool;

private:
    friend class Renderer;
    void key(int key, int scancode, int action, int mods);
    void mouse_button(int button, int action, int mods);
    void mouse_scroll(double x_offset, double y_offset);
    void mouse_cursor(double x_pos, double y_pos);

private:
    std::map<std::string, std::shared_ptr<Gui>> _gui;

public:
    Manager();
    Manager(const Manager &) = delete;
    Manager(Manager &&) = delete;
    ~Manager() = default;
    auto operator=(const Manager &) -> Manager & = delete;
    auto operator=(Manager &&) -> Manager & = default;
};
using ManagerPtr = std::shared_ptr<Manager>;
}
#endif //KASUMI_MANAGER_H

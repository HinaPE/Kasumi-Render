#ifndef KASUMI_SCENE_H
#define KASUMI_SCENE_H

#include "camera.h"
#include "scene_object.h"

#include <map>
#include <memory>
#include <functional>

namespace Kasumi::Workbench
{
class Scene
{
public:
    template<typename T>
    auto add(T &&underlying) -> unsigned int;
    auto add(SceneObjectPtr &&ptr) -> unsigned int;
    void erase(unsigned int id);
    void restore(unsigned int id);
    void render();
    void for_each_item(const std::function<void(SceneObjectPtr &)> &func);

public:
    Scene() = default;
    Scene(const Scene &) = delete;
    Scene(Scene &&) = delete;
    ~Scene() = default;
    auto operator=(const Scene &) -> Scene & = delete;
    auto operator=(Scene &&) -> Scene & = delete;

private:
    std::map<unsigned int, SceneObjectPtr> _scene_objects;
    std::map<unsigned int, SceneObjectPtr> _scene_objects_erased;
    std::map<unsigned int, CameraPtr> _scene_cameras;
};
using ScenePtr = std::shared_ptr<Scene>;

template<typename T>
auto Kasumi::Workbench::Scene::add(T &&underlying) -> unsigned int { return add(std::move(std::make_shared<SceneObject>(std::forward<T>(underlying)))); }
}
#endif //KASUMI_SCENE_H

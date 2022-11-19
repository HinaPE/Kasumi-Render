#ifndef KASUMI_SCENE_H
#define KASUMI_SCENE_H

#include "camera.h"
#include "scene_object.h"

#include <map>
#include <memory>
#include <functional>
#include <limits>

namespace Kasumi::Workbench
{
class Scene
{
public:
    auto read_scene(const std::string &path) -> std::string /** return: error message **/;
    auto write_to_file(const std::string &path) -> std::string /** return: error message **/;

public:
    auto add_model(const std::string &model_path, unsigned int shader_id = 0 /** use default shader **/) -> unsigned int;
    auto add_shader(const std::string &vertex_shader, const std::string &fragment_shader, const std::string &geometry_shader = "") -> unsigned int;
    auto add_camera() -> unsigned int;
    void erase(unsigned int id);
    void restore(unsigned int id);
    void render();
    void clear();
    void for_each_item(const std::function<void(SceneObjectPtr &)> &func);

public:
    Scene();
    Scene(const Scene &) = delete;
    Scene(Scene &&) = delete;
    ~Scene() = default;
    auto operator=(const Scene &) -> Scene & = delete;
    auto operator=(Scene &&) -> Scene & = delete;

public:
    struct Opt
    {
        unsigned int current_object_id = std::numeric_limits<unsigned int>::max();
        unsigned int default_camera_id = std::numeric_limits<unsigned int>::max();
        unsigned int default_shader_id = std::numeric_limits<unsigned int>::max();
    } opt;
    auto get_current_object() const -> SceneObjectPtr;
    auto get_current_camera() const -> CameraPtr;

private:
    std::map<unsigned int, SceneObjectPtr> _scene_objects;
    std::map<unsigned int, SceneObjectPtr> _scene_objects_erased;
    std::map<unsigned int, CameraPtr> _scene_cameras;
    std::map<unsigned int, ShaderPtr> _scene_shaders;
};
using ScenePtr = std::shared_ptr<Scene>;
}
#endif //KASUMI_SCENE_H

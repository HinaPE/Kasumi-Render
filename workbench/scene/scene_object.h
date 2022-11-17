#ifndef KASUMI_SCENE_OBJECT_H
#define KASUMI_SCENE_OBJECT_H

#include "pose.h"
#include "model.h"
#include <variant>
#include <memory>

namespace Kasumi::Workbench
{
class SceneObject
{
public:
    void render();

public:
    template<typename T>
    explicit SceneObject(T &&underlying) : _underlying(std::forward<T>(underlying)) {}
    SceneObject(const SceneObject &) = delete;
    SceneObject(SceneObject &&) = delete;
    ~SceneObject() = default;
    auto operator=(const SceneObject &) -> SceneObject & = delete;
    auto operator=(SceneObject &&) -> SceneObject & = delete;

private:
    Pose pose;
    std::variant<Model, TexturedMesh> _underlying;
};
using SceneObjectPtr = std::shared_ptr<SceneObject>;
}
#endif //KASUMI_SCENE_OBJECT_H

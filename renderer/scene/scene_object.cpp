#include "scene_object.h"
#include "imgui.h"

void Kasumi::SceneObject::render() { std::visit([&](auto &renderable) { renderable->render(); }, _underlying); }
void Kasumi::SceneObject::use_shader(const Kasumi::ShaderPtr &shader) { std::visit([&](auto &renderable) { renderable->use_shader(shader); }, _underlying); }
void Kasumi::SceneObject::update_mvp(const Kasumi::mMatrix4x4 &view, const Kasumi::mMatrix4x4 &projection)
{
    std::visit([&](auto &renderable)
               {
                   auto shader = renderable->get_shader();
                   shader->use();
                   auto model = _pose.get_model_matrix();
                   shader->uniform("projection", projection);
                   shader->uniform("view", view);
                   shader->uniform("model", model);
               }, _underlying);
}
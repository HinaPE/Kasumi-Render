#include "particles.h"
void Kasumi::ParticlesObject::_draw()
{
	if (_mesh == nullptr)
		return;

	_mesh->render(*_shader);
}
void Kasumi::ParticlesObject::_rebuild_()
{
	if (!Object3D::_opt.dirty)
		return;

	if (!_opt.inited)
	{
		if (!_opt.texture_path.empty())
			_mesh = std::make_shared<InstancedMesh>(std::make_shared<Mesh>(_opt.mesh_name, _opt.texture_path));
		else
			_mesh = std::make_shared<InstancedMesh>(std::make_shared<Mesh>(_opt.mesh_name, _opt.color));
		_opt.inited = true;
	}

	for (auto &pose: _opt.poses)
		_mesh->_opt.instance_matrices.push_back(pose.get_model_matrix());
	_mesh->_opt.dirty = true;

	Object3D::_rebuild_();
}

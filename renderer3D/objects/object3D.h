#ifndef KASUMI_OBJECT3D_H
#define KASUMI_OBJECT3D_H

#include "api.h"
#include "pose.h"

namespace Kasumi
{
class Object3D : public INSPECTOR
{
public:
	static unsigned int ID_GLOBAL;
	const unsigned int ID;
	std::string NAME = "Untitled";
	struct Opt
	{
		bool dirty = true;
		Pose pose;
	} _opt;
	Object3D() : ID(ID_GLOBAL++) {}
	virtual void sync_opt() { _opt.dirty = false; }

	void INSPECT() override;
};
using Object3DPtr = std::shared_ptr<Object3D>;

class ObjectMesh3D : public Object3D, public Renderable, public VALID_CHECKER
{
public:
	void switch_wireframe() const { _mesh->_opt.render_wireframe = !_mesh->_opt.render_wireframe; }

public:
	struct Opt
	{
		std::string mesh_name = "cube";
		std::string texture_path; // Default: not
		mVector3 color = HinaPE::Color::RED;
	} _opt;
	ObjectMesh3D() { _shader = Shader::DefaultMeshShader; }
	void sync_opt() override;

protected:
	void _draw() final;
	void _update_uniform() final;

	void INSPECT() override;
	void VALID_CHECK() const override;

	MeshPtr _mesh;
};
using ObjectMesh3DPtr = std::shared_ptr<ObjectMesh3D>;
} // namespace Kasumi
#endif //KASUMI_OBJECT3D_H
#ifndef KASUMI_CUP_H
#define KASUMI_CUP_H

#include "object3D.h"
namespace Kasumi
{
class CupObject final : public ObjectMesh3D
{
public:
	struct Opt
	{
	} _opt;
	CupObject() { ObjectMesh3D::_opt.mesh_name = "cup"; }
	void sync_opt() final
	{
		if (!Object3D::_opt.dirty)
			return;

		ObjectMesh3D::sync_opt();
	}
};
using CupObjectPtr = std::shared_ptr<CupObject>;

} // namespace Kasumi
#endif //KASUMI_CUP_H
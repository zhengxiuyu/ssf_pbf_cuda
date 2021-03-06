#pragma once
#include "../../pbf/pbf_type.h"

namespace pbf {

class pbf_sphere_init_cond
{
public:
	pbf_sphere_init_cond(scalar_t space);
	~pbf_sphere_init_cond() {};
	// space : desired particles space
	void getDomainParticlePhaseHost(dom_dim* pos, dom_dim* vel, uint32_t* particle_num) const;
	void getDomainParticlePhaseHost(std::vector<dom_dim>& pos, std::vector<dom_dim>& vel) const;
	// space : desired particles space
	void getDomainParticlePhaseDevice(dom_dim* pos, dom_dim* vel, uint32_t* particle_num) const;
	void getBoundaryHost(
		std::vector<glm::vec4>& h_inner_spheres,	// float4(center, radius)
		std::vector<glm::vec4>& h_outer_spheres,	// float4(center, radius)
		std::vector<dom_dim>& h_points_on_planes,
		std::vector<dom_dim>& h_normals_on_planes);
	void getParameter(pbf_parameter& param);
	void getExternalForce(pbf_external& external);
	std::pair<dom_dim, dom_dim> getDomainRange() const;

private:
	pbf_parameter param;
	pbf_external external;
	dom_dim domain_origin;
	dom_dim domain_end;
	dom_dim fluid_origin;
	dom_dim fluid_end;
};

} // end of pbf ns

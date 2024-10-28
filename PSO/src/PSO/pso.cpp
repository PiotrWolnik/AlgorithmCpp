#include "pso.hpp"

Particle::Particle(size_t dimensions)
    : position(dimensions),
    velocity(dimensions), 
    best_position(dimensions), 
    best_value(std::numeric_limits<double>::max()) 
{
}

PSO::PSO()
    : num_particles(100), 
    max_iterations(100), 
    w(0.7), 
    c1(1.5),
    c2(1.5)
{
}

void PSO::updateParameters(size_t num_particles, unsigned int max_iterations, double w, double c1, double c2) 
{
    this->num_particles = num_particles;
    this->max_iterations = max_iterations;
    this->w = w;
    this->c1 = c1;
    this->c2 = c2;
}

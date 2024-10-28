#ifndef PSO_HPP
#define PSO_HPP

#include <vector>
#include <functional>

struct Particle {
    Particle(size_t dimensions);
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> best_position;
    double best_value;
};

class PSO {
private:
    size_t num_particles;
    unsigned int max_iterations;
    double w;
    double c1;
    double c2;

    void initialize_particles();
    void update_particle(Particle& particle);

public:
    PSO();
    ~PSO();

    void updateParameters(size_t num_particles, unsigned int max_iterations, double w, double c1, double c2);
};

#endif // PSO_HPP

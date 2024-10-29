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
    unsigned int max_iterations;
    double w;
    double c1;
    double c2;
    size_t num_particles;
    std::vector<Particle> particles;
    size_t dimensions;
    std::vector<double> target_position;
    std::vector<std::function<double(const std::vector<double>&)>> equations;

    void initialize_particles();
    void update_particle(Particle& particle);
    double objective_function(const std::vector<double>& position);

public:
    PSO(const std::vector<std::function<double(const std::vector<double>&)>>& _equations,
         const std::vector<double>& _target_position);
    ~PSO();

    void updateParameters(size_t num_particles, unsigned int max_iterations, double w, double c1, double c2);
};

#endif // PSO_HPP

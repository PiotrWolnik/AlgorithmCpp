#ifndef PSO_HPP
#define PSO_HPP

#include <vector>
#include <functional>
#include <limits>
#include <random>

using EquationVector = std::vector<std::function<double(const std::vector<double>&)>>;

struct Particle {
    Particle(size_t dimension);
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> bestPosition;
    double bestValue;
};

class PSO {
private:
    unsigned int N_max;
    double w;
    double c1;
    double c2;
    size_t particleCount;
    std::vector<Particle> particles;
    size_t dimension;
    std::vector<double> targetPosition;
    EquationVector equations;
    std::vector<std::pair<double, double>> positionLimits;

    void initializeParticles();
    void updateParticle(Particle& particle);
    double objectiveFunction(const std::vector<double>& position);

public:
    PSO(const EquationVector& equations,
        const std::vector<double>& targetPosition,
        const std::vector<std::pair<double, double>>& positionLimits = {});
    ~PSO() = default;

    void updateParameters(size_t particleCount, unsigned int N_max, double w, double c1, double c2);
    void setPositionLimits(const std::vector<std::pair<double, double>>& limits);
};

#endif // PSO_HPP

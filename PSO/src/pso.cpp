#include "pso.hpp"

Particle::Particle(size_t dimension)
    : position(dimension),
    velocity(dimension), 
    bestPosition(dimension), 
    bestValue(std::numeric_limits<double>::max()) 
{
}

PSO::PSO(const EquationVector& equations,
         const std::vector<double>& targetPosition,
         const std::vector<std::pair<double, double>>& limits)
    : particleCount(100), 
    N_max(100),
    w(0.7),
    c1(1.5),
    c2(1.5),
    targetPosition(targetPosition),
    dimension(equations.size()),
    particles(particleCount, Particle(equations.size())),
    equations(equations)
{
    setPositionLimits(limits);
    initializeParticles();
}

void PSO::initializeParticles()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    for (auto& particle : particles) 
    {
        for (size_t i = 0; i < dimension; ++i) 
        {
            std::uniform_real_distribution<double> posDist(positionLimits[i].first, positionLimits[i].second);
            particle.position[i] = posDist(gen);
            particle.bestPosition[i] = particle.position[i];

            std::uniform_real_distribution<double> velDist(-1.0, 1.0);
            particle.velocity[i] = velDist(gen);
        }
        particle.bestValue = objectiveFunction(particle.position);
    }
}

void PSO::updateParticle(Particle& particle)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);

    for (size_t i = 0; i < dimension; ++i) 
    {
        double r1 = dist(gen);
        double r2 = dist(gen);

        particle.velocity[i] = w * particle.velocity[i]
                             + c1 * r1 * (particle.bestPosition[i] - particle.position[i])
                             + c2 * r2 * (targetPosition[i] - particle.position[i]);
                             
        particle.position[i] += particle.velocity[i];

        if (particle.position[i] < positionLimits[i].first) 
        {
            particle.position[i] = positionLimits[i].first;
        }
        else if (particle.position[i] > positionLimits[i].second) 
        {
            particle.position[i] = positionLimits[i].second;
        }
    }
}

double PSO::objectiveFunction(const std::vector<double>& position)
{
    double distance = 0.0;
    for (size_t i = 0; i < dimension; ++i)
    {
        double value = equations[i](position);
        double diff = targetPosition[i] - value;
        distance += diff * diff;
    }
    return std::sqrt(distance);
}

void PSO::updateParameters(size_t particleCount, unsigned int N_max, double w, double c1, double c2) 
{
    this->particleCount = particleCount;
    this->N_max = N_max;
    this->w = w;
    this->c1 = c1;
    this->c2 = c2;
}

void PSO::setPositionLimits(const std::vector<std::pair<double, double>>& limits)
{
    if (limits.size() == dimension) {
        positionLimits = limits;
    }
    else if (limits.size() == 1) {
        positionLimits.assign(dimension, limits[0]);
    }
    else {
        positionLimits.assign(dimension, {-10.0, 10.0});
    }
}

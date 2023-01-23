# kovian
A single-header library for finite state space Markov chain simulations.

## Usage
See the files `sample.cpp` and `sample1.kov` for an example simulation.

The transition matrix can be loaded from a file (by filename) or given explicitly as a properly-sized `std::array<double>` (see the typedef `kovian::TransitionMatrix` and its alias `kovian::aliases::TM`).

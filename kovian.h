// kovian is a single-header library for finite state space Markov chain simulations.

#pragma once
#ifndef KOVIAN_H
#define KOVIAN_H

#include <array>      // for std::array
#include <random>     // for generating discrete random variables
#include <chrono>     // for seeding using system clock
#include <functional> // for std::function

namespace kovian {
	template<size_t N>
	using TransitionMatrix = std::array<double, N*N>;
	
	// Defines a Markov chain with N nodes indexed 0, 1, ... N-1.
	template<size_t N>
	class MarkovChain {
	public:
		// Constructor takes a probability transition matrix. The rows of P do not have to sum to 1 (they will be normalized).
		MarkovChain(const TransitionMatrix<N> &P) {
			// Seed RNG using current time
			rng.seed( std::chrono::system_clock::now().time_since_epoch().count() );
			// Construct the onestep transition kernel from the passed matrix in array form
			for(size_t k = 0; k < N; ++k)
				onestep[k] = std::discrete_distribution<size_t>(P.begin() + k*N, P.begin() + (k+1)*N);
		}
		
		// Advances the Markov chain by one step and returns the new state.
		size_t advance() { return state = onestep[state](rng); }
		// Get the current state.
		const size_t current() const { return state; }
		// Set the initial state of the system.
		void setState(size_t x) {
			if(x >= N) throw std::runtime_error("Tried to assign state " + std::to_string(x) + " to Markov chain with only " + std::to_string(N) + " states.");
			state = x;
		}
	private:
		size_t state;
		std::default_random_engine rng;
		// one-step transition probabilities
		std::array<std::discrete_distribution<size_t>, N> onestep;
	};
	
	//template<typename T, size_t N>
	//using Labelling = std::function()
	
	template<typename T>
	using CostFunction = std::function<double(const T&)>;
}

#endif

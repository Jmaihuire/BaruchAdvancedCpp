// Level7_Section7.7_Exercise1.cpp 
// Fiona Ross 
// Concepts
#include <cmath>
#include <iostream>
#include <memory>
#include <random>
#include "OptionData.h"  
#include "SDE.h"
#include "SDEAbstract.h"  
#include "StopWatch.h"    

// Concept was c++20 and needed to change language 
// essentially just copied & pasted example...ran out of time 

// Extend the model in part 2) to support GBM with Poisson jumps as well as to PDEs which have convection, diffusion, reaction 
// and homogeneous terms. How would you model PDEs that have no convection terms?
    // --> In truth I had so little time that I focused on the coding vs. the PDE meaning. 
    // --> Having never taken a finance class I do not think I can really answer this 
    // --> I tried to do research into this but did not come up with much  

// Let’s say we wish to model multifactor SDEs, for example multi-asset, Heston etc. 
// Can you model these SDEs using parameter packs and variadic parameters?
//  -- > Yes from the best of my knowledge we could do parameter packs and
//  --> variadic parameters and probably just inserted in the parameter templates? 

// Test the new code.
// I unfortunately don't have new code but I saw in the forum that you could re-structure classes so don't have to re-write classes
// It seemed like this would involve disabling & enabling member functions at compile time 

int main()

{
  std::cout << "1 factor MC with explicit Euler\n";

  OptionData myOption{65.0, 0.25, 0.08, 0.3, 0.0, -1};

  // THIS IS KEY CHANGE TO THIS SECTION
  // *********************************************************** The SDE class
  // used to be hardcoded into this file, but can now be used as a template
  // parameter in the SDEAbstract class. This is advantageous compared to the
  // hard-coded solution because SDEAbstract can take any SDE type that includes
  // a diffusion and drift function. The concepts force the compiler to check the
  // template types for these functions. (See additional notes about this in
  // SDEAbstract.h)
  SDEAbstract<SDE, double> sde(myOption);
  // I unfortunately am not fluent in financial modeling (although I know this
  // is probably a trivial example for a finance student)
  // so I do not know exactly how to extend this model for the additional PDE
  // concepts. I understand there is some documentation included on this topic
  // in the provided documents, however I do not have the time at the moment to
  // learn the finance related content.
  //
  // As for variadic parameters, we probably can use parameter packs and
  // variadic parameters within this same framework. Although I do not implement
  // them here, I can see how since we are using a template based approach,
  // parameter packs could be used in the template definition to support
  // multiple SDE types to track multiple assets.
  //
  // Sorry for not having more original content in this exercise, but I am low
  // on time and think I at least have a taste of C++ concepts
  //**********************************************************************************************

  // Initial value of SDE

  double S_0 = 60;

  // Variables for underlying stock

  double x;

  double VOld = S_0;

  double VNew;

  long NT = 100;

  std::cout << "Number of time steps: ";

  std::cin >> NT;

  // V2 mediator stuff

  long NSIM = 50000;

  std::cout << "Number of simulations: ";

  std::cin >> NSIM;

  double M = static_cast<double>(NSIM);

  double dt = myOption.T / static_cast<double>(NT);

  double sqrdt = std::sqrt(dt);

  // Normal random number

  double dW;

  double price = 0.0;  // Option price

  double payoffT;

  double avgPayoffT = 0.0;

  double squaredPayoff = 0.0;

  double sumPriceT = 0.0;

  // #include <random>

  // Normal (0,1) rng

  std::default_random_engine dre;

  std::normal_distribution<double> nor(0.0, 1.0);

  // Create a random number

  dW = nor(dre);

  StopWatch sw;

  sw.StartStopWatch();

  for (long i = 1; i <= M; ++i)

  {
    // Calculate a path at each iteration

    if ((i / 100'000) * 100'000 == i)

    {
      // Give status after each 10000th iteration

      std::cout << i << ", ";
    }

    VOld = S_0;

    x = 0.0;

    for (long index = 0; index <= NT; ++index)

    {
      // Create a random number

      dW = nor(dre);

      // The FDM (in this case explicit Euler)

      VNew = VOld + (dt * sde.drift(x, VOld)) +
             (sqrdt * sde.diffusion(x, VOld) * dW);

      VOld = VNew;

      x += dt;
    }

    // Assemble quantities (postprocessing)

    payoffT = myOption.myPayOffFunction(VNew);
    sumPriceT += payoffT;
    avgPayoffT += payoffT / M;
    avgPayoffT *= avgPayoffT;

    squaredPayoff += (payoffT * payoffT);
  }

  // Finally, discounting the average price

  price = std::exp(-myOption.r * myOption.T) * sumPriceT / M;

  std::cout << "Price, after discounting: "

            << price << ", " << std::endl;

  double SD = std::sqrt((squaredPayoff / M) - sumPriceT * sumPriceT / (M * M));

  std::cout << "Standard Deviation: " << SD << ", " << std::endl;

  double SE = SD / std::sqrt(M);

  std::cout << "Standard Error: " << SE << ", " << std::endl;

  sw.StopStopWatch();

  std::cout << "Elapsed time in seconds: " << sw.GetTime() << '\n';

  return 0;
}

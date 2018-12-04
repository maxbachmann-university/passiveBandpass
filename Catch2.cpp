/** @file */
/*! \mainpage TFE17-2 Test
 *
 * \section Introduction
 *
 * This Project is part of a series by Christian Ege in the informatics lesson of the DHBW Ravensburg Campus Friedrichshafen.
 * The tasks are worked out together in a team up to 3 People. In this Case Felix Bandle, Maximilian Bachmann and Florian Vetter worked together for the solution.
 * The deadline for the project is set on the 30. october 2018.
 *
 * 
 * 
 * \section Catch2
 * 
 * This header file is used for testing our code.
 * 
 * Catch2 stands for C++ Automated Test Cases in a Header and is a multi-paradigm test framework for C++. 
 * which also supports Objective-C (and maybe C). 
 * It is primarily distributed as a single header file, although certain extensions may require additional headers.
 * 
 * Source: https://github.com/catchorg/Catch2
 *  
 */

 //Includes

#include "Filter/LCLowPass.hpp"
#include "Filter/LRLowPass.hpp"
#include "Filter/RCLowPass.hpp"
#include <memory>
#include <math.h>

#define eps 1.19e-7f

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"




SCENARIO( "calculate Frequency", "[LowPass]" ) {
    GIVEN("A vector with some items"){
        double resistor = 5.9;
        double capacitor = 10.3;
        double inductor = 0.5;

        std::unique_ptr<LowPass> lcLowPass = std::make_unique<LCLowPass>(inductor, capacitor);
        std::unique_ptr<LowPass> lrLowPass = std::make_unique<LRLowPass>(inductor, resistor);
        std::unique_ptr<LowPass> rcLowPass = std::make_unique<RCLowPass>(resistor, capacitor);

        WHEN("Frequency is calculated") {
            double lcFrequency = lcLowPass->Frequency();
            double lrFrequency = lrLowPass->Frequency();
            double rcFrequency = rcLowPass->Frequency();

            THEN( "They are the same but not in the same position" ) {
                REQUIRE( fabs(lcFrequency - 0.07013204731) <= eps * fabs(lcFrequency) );
                REQUIRE( fabs(lrFrequency - 1.878028328) <= eps * fabs(lrFrequency) );
                REQUIRE( fabs(rcFrequency - 2.618972241e-3) <= eps * fabs(rcFrequency) );
            }
        }

    }
}

SCENARIO( "calculate Frequency", "[HighPass]" ) {
    GIVEN("A vector with some items"){
        double resistor = 5.9;
        double capacitor = 10.3;
        double inductor = 0.5;

        std::unique_ptr<LowPass> lcLowPass = std::make_unique<LCLowPass>(inductor, capacitor);
        std::unique_ptr<LowPass> lrLowPass = std::make_unique<LRLowPass>(inductor, resistor);
        std::unique_ptr<LowPass> rcLowPass = std::make_unique<RCLowPass>(resistor, capacitor);

        WHEN("Frequency is calculated") {
            double lcFrequency = lcLowPass->Frequency();
            double lrFrequency = lrLowPass->Frequency();
            double rcFrequency = rcLowPass->Frequency();

            THEN( "They are the same but not in the same position" ) {
                REQUIRE( fabs(lcFrequency - 0.07013204731) <= eps * fabs(lcFrequency) );
                REQUIRE( fabs(lrFrequency - 1.878028328) <= eps * fabs(lrFrequency) );
                REQUIRE( fabs(rcFrequency - 2.618972241e-3) <= eps * fabs(rcFrequency) );
            }
        }

    }
}


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

#include "Filter/CLHighPass.hpp"
#include "Filter/RLHighPass.hpp"
#include "Filter/CRHighPass.hpp"

#include "Filter/Bandpass.hpp"

#include <memory>
#include <math.h>

#define eps 1.19e-7f

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"




SCENARIO( "calculate Frequency for LowPass", "[LowPass]" ) {
    GIVEN("Some Low Pass Filters"){
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

SCENARIO( "+ operator for LowPass", "[LowPass]" ) {
    GIVEN("Some Low Pass and High Pass Filters"){
        double resistor = 5.9;
        double capacitor = 10.3;
        double inductor = 0.5;

        std::shared_ptr<LowPass> lcLowPass = std::make_shared<LCLowPass>(inductor, capacitor);

        std::shared_ptr<HighPass> clHighPass = std::make_shared<CLHighPass>(inductor, capacitor);
        
        std::unique_ptr<Bandpass> bandpass = lcLowPass + clHighPass;
        std::unique_ptr<Bandpass> bandpass2 = clHighPass + lcLowPass;

        double TopCap = bandpass->returnTopCap();

        //std::unique_ptr<Bandpass> bandpass = std::make_unique<Bandpass>(std::move(lcLowPass), std::move(clHighPass));

        WHEN("Frequency is calculated") {

            THEN( "They are the same but not in the same position" ) {
            }
        }

    }
}

SCENARIO( "calculate Frequency for HighPass", "[HighPass]" ) {
    GIVEN("Some High Pass Filters"){
        double resistor = 5.9;
        double capacitor = 10.3;
        double inductor = 0.5;

        std::unique_ptr<HighPass> clHighPass = std::make_unique<CLHighPass>(inductor, capacitor);
        std::unique_ptr<HighPass> rlHighPass = std::make_unique<RLHighPass>(inductor, resistor);
        std::unique_ptr<HighPass> crHighPass = std::make_unique<CRHighPass>(resistor, capacitor);

        WHEN("Frequency is calculated") {
            double clFrequency = clHighPass->Frequency();
            double rlFrequency = rlHighPass->Frequency();
            double crFrequency = crHighPass->Frequency();

            THEN( "They are the same but not in the same position" ) {
                REQUIRE( fabs(clFrequency - 0.07013204731) <= eps * fabs(clFrequency) );
                REQUIRE( fabs(rlFrequency - 1.878028328) <= eps * fabs(rlFrequency) );
                REQUIRE( fabs(crFrequency - 2.618972241e-3) <= eps * fabs(crFrequency) );
            }
        }

    }
}


/** @file */
/*! \mainpage TFE17-2 Test
 *
 * \section Introduction
 *
 * This Project is part of a series by Christian Ege in the informatics lesson of the DHBW Ravensburg Campus Friedrichshafen.
 * The tasks are worked out together in a team up to 3 People. In this Case Felix Bandle, Maximilian Bachmann and Florian Vetter worked together for the solution.
 * The deadline for the project is set on the 09. december 2018.
 *
 * \section Task3
 * 
 * In this task we had to describe a Bandpass with c++ and class relations. The goal was to be able to create a Bandpass with several items.
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

#include "Components/Component.hpp"
#include "Components/Inductor.hpp"
#include "Components/Resistor.hpp"
#include "Components/Capacitor.hpp"

#include "Filter/LCLowPass.hpp"
#include "Filter/LRLowPass.hpp"
#include "Filter/RCLowPass.hpp"

#include "Filter/CLHighPass.hpp"
#include "Filter/RLHighPass.hpp"
#include "Filter/CRHighPass.hpp"

#include "Filter/Bandpass.hpp"
#include "Filter/combinedHighPass.hpp"
#include "Filter/combinedLowPass.hpp"


#include <memory>
#include <math.h>
#include <limits>
#include <vector>

#define eps 1.19e-7f

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


template<typename TO, typename FROM>
std::unique_ptr<TO> static_unique_pointer_cast (std::unique_ptr<FROM>&& old){
    return std::unique_ptr<TO>{static_cast<TO*>(old.release())};
}

SCENARIO( "calculate resistor networks", "[Resistor]" ) {
    GIVEN("Some resistors"){
        std::shared_ptr<Resistor> R1 = std::make_shared<Resistor>(5);
        std::shared_ptr<Resistor> R2 = std::make_shared<Resistor>(10);
        std::shared_ptr<Resistor> R3 = std::make_shared<Resistor>(10);

        Resistor R4(5);
        Resistor R5(10);
        Resistor R6(10);

        REQUIRE(R1->getValue() == 5);
        REQUIRE(R2->getValue() == 10);
        REQUIRE(R3->getValue() == 10);
        REQUIRE(R4.getValue() == 5);
        REQUIRE(R5.getValue() == 10);
        REQUIRE(R6.getValue() == 10);


        WHEN("series connection using &&") {
            std::shared_ptr<Resistor> Rout1 = R1 && R2;
            Resistor Rout2 = R4 && R5;

            THEN( "They both have the value 15" ) {
                REQUIRE(fabs(Rout1->getValue() - 15) 
                   <= eps * fabs(Rout1->getValue()) );
                REQUIRE(fabs(Rout2.getValue() - 15) 
                   <= eps * fabs(Rout2.getValue()) );
            }
        }

        WHEN("parallel connection using ||") {
            std::shared_ptr<Resistor> Rout1 = R2 || R3;
            Resistor Rout2 = R5 || R6;

            THEN( "They both have the value 5" ) {
                REQUIRE(fabs(Rout1->getValue() - 5) 
                   <= eps * fabs(Rout1->getValue()) );
                REQUIRE(fabs(Rout2.getValue() - 5) 
                   <= eps * fabs(Rout2.getValue()) );
            }
        }

        WHEN("series connection then parallel") {
            std::shared_ptr<Resistor> Rout1 = R1 && R2 || R3;
            Resistor Rout2 = R4 && R5 || R6;

            THEN( "They both have the value 6" ) {
                REQUIRE(fabs(Rout1->getValue() - 6) 
                   <= eps * fabs(Rout1->getValue()) );
                REQUIRE(fabs(Rout2.getValue() - 6) 
                   <= eps * fabs(Rout2.getValue()) );
            }
        }

        WHEN("parallel connection then series") {
            std::shared_ptr<Resistor> Rout1 = R1 && (R2 || R3);
            Resistor Rout2 = R4 && (R5 || R6);

            THEN( "They both have the value 10" ) {
                REQUIRE(fabs(Rout1->getValue() - 10) 
                   <= eps * fabs(Rout1->getValue()) );
                REQUIRE(fabs(Rout2.getValue() - 10) 
                   <= eps * fabs(Rout2.getValue()) );
            }
        }

        WHEN("R is comparedusing ==") {
            bool out1 = R1 == R2;
            bool out2 = R2 == R3;
            bool out3 = R4 == R5;
            bool out4 = R5 == R6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == false);
                REQUIRE(out2 == true);
                REQUIRE(out3 == false);
                REQUIRE(out4 == true);
            }
        }

        WHEN("R is comparedusing !=") {
            bool out1 = R1 != R2;
            bool out2 = R2 != R3;
            bool out3 = R4 != R5;
            bool out4 = R5 != R6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == true);
                REQUIRE(out2 == false);
                REQUIRE(out3 == true);
                REQUIRE(out4 == false);
            }
        }

        WHEN("Two resistors are divided") {
            double out1 = R2 / R3;
            double out2 = R5 / R6;

            THEN( "They are both 1" ) {
                REQUIRE(out1 == 1);
                REQUIRE(out2 == 1);
            }
        }
    }
}


SCENARIO( "calculate inductor networks", "[Inductor]" ) {
    GIVEN("Some inductors"){
        std::shared_ptr<Inductor> L1 = std::make_shared<Inductor>(5);
        std::shared_ptr<Inductor> L2 = std::make_shared<Inductor>(10);
        std::shared_ptr<Inductor> L3 = std::make_shared<Inductor>(10);

        Inductor L4(5);
        Inductor L5(10);
        Inductor L6(10);

        REQUIRE(L1->getValue() == 5);
        REQUIRE(L2->getValue() == 10);
        REQUIRE(L3->getValue() == 10);
        REQUIRE(L4.getValue() == 5);
        REQUIRE(L5.getValue() == 10);
        REQUIRE(L6.getValue() == 10);


        WHEN("series connection using &&") {
            std::shared_ptr<Inductor> Lout1 = L1 && L2;
            Inductor Lout2 = L4 && L5;

            THEN( "They both have the value 15" ) {
                REQUIRE(fabs(Lout1->getValue() - 15) 
                   <= eps * fabs(Lout1->getValue()) );
                REQUIRE(fabs(Lout2.getValue() - 15) 
                   <= eps * fabs(Lout2.getValue()) );
            }
        }

        WHEN("parallel connection using ||") {
            std::shared_ptr<Inductor> Lout1 = L2 || L3;
            Inductor Lout2 = L5 || L6;

            THEN( "They both have the value 5" ) {
                REQUIRE(fabs(Lout1->getValue() - 5) 
                   <= eps * fabs(Lout1->getValue()) );
                REQUIRE(fabs(Lout2.getValue() - 5) 
                   <= eps * fabs(Lout2.getValue()) );
            }
        }

        WHEN("series connection then parallel") {
            std::shared_ptr<Inductor> Lout1 = L1 && L2 || L3;
            Inductor Lout2 = L4 && L5 || L6;

            THEN( "They both have the value 6" ) {
                REQUIRE(fabs(Lout1->getValue() - 6) 
                   <= eps * fabs(Lout1->getValue()) );
                REQUIRE(fabs(Lout2.getValue() - 6) 
                   <= eps * fabs(Lout2.getValue()) );
            }
        }

        WHEN("parallel connection then series") {
            std::shared_ptr<Inductor> Lout1 = L1 && (L2 || L3);
            Inductor Lout2 = L4 && (L5 || L6);

            THEN( "They both have the value 10" ) {
                REQUIRE(fabs(Lout1->getValue() - 10) 
                   <= eps * fabs(Lout1->getValue()) );
                REQUIRE(fabs(Lout2.getValue() - 10) 
                   <= eps * fabs(Lout2.getValue()) );
            }
        }

        WHEN("L is compared using ==") {
            bool out1 = L1 == L2;
            bool out2 = L2 == L3;
            bool out3 = L4 == L5;
            bool out4 = L5 == L6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == false);
                REQUIRE(out2 == true);
                REQUIRE(out3 == false);
                REQUIRE(out4 == true);
            }
        }

        WHEN("L is comparedusing !=") {
            bool out1 = L1 != L2;
            bool out2 = L2 != L3;
            bool out3 = L4 != L5;
            bool out4 = L5 != L6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == true);
                REQUIRE(out2 == false);
                REQUIRE(out3 == true);
                REQUIRE(out4 == false);
            }
        }

        WHEN("Two inductors are divided") {
            double out1 = L2 / L3;
            double out2 = L5 / L6;

            THEN( "They are both 1" ) {
                REQUIRE(out1 == 1);
                REQUIRE(out2 == 1);
            }
        }
    }
}

SCENARIO( "calculate capacitor networks", "[Capacitor]" ) {
    GIVEN("Some capacitors"){
        std::shared_ptr<Capacitor> C1 = std::make_shared<Capacitor>(5);
        std::shared_ptr<Capacitor> C2 = std::make_shared<Capacitor>(10);
        std::shared_ptr<Capacitor> C3 = std::make_shared<Capacitor>(10);

        Capacitor C4(5);
        Capacitor C5(10);
        Capacitor C6(10);

        REQUIRE(C1->getValue() == 5);
        REQUIRE(C2->getValue() == 10);
        REQUIRE(C3->getValue() == 10);
        REQUIRE(C4.getValue() == 5);
        REQUIRE(C5.getValue() == 10);
        REQUIRE(C6.getValue() == 10);


        WHEN("series connection using &&") {
            std::shared_ptr<Capacitor> Cout1 = C2 && C3;
            Capacitor Cout2 = C5 && C6;

            THEN( "They both have the value 5" ) {
                REQUIRE(fabs(Cout1->getValue() - 5) 
                   <= eps * fabs(Cout1->getValue()) );
                REQUIRE(fabs(Cout2.getValue() - 5) 
                   <= eps * fabs(Cout2.getValue()) );
            }
        }

        WHEN("parallel connection using ||") {
            std::shared_ptr<Capacitor> Cout1 = C1 || C2;
            Capacitor Cout2 = C4 || C5;

            THEN( "They both have the value 15" ) {
                REQUIRE(fabs(Cout1->getValue() - 15) 
                   <= eps * fabs(Cout1->getValue()) );
                REQUIRE(fabs(Cout2.getValue() - 15) 
                   <= eps * fabs(Cout2.getValue()) );
            }
        }

        WHEN("parallel connection then series") {
            std::shared_ptr<Capacitor> Cout1 = C2 && (C3 || C1);
            Capacitor Cout2 = C5 && (C6 || C4);

            THEN( "They both have the value 6" ) {
                REQUIRE(fabs(Cout1->getValue() - 6) 
                   <= eps * fabs(Cout1->getValue()) );
                REQUIRE(fabs(Cout2.getValue() - 6) 
                   <= eps * fabs(Cout2.getValue()) );
            }
        }

        WHEN("series connection then parallel") {
            std::shared_ptr<Capacitor> Cout1 = C2 && C3 || C1;
            Capacitor Cout2 = C5 && C6 || C4;

            THEN( "They both have the value 10" ) {
                REQUIRE(fabs(Cout1->getValue() - 10) 
                   <= eps * fabs(Cout1->getValue()) );
                REQUIRE(fabs(Cout2.getValue() - 10) 
                   <= eps * fabs(Cout2.getValue()) );
            }
        }

        WHEN("C is comparedusing ==") {
            bool out1 = C1 == C2;
            bool out2 = C2 == C3;
            bool out3 = C4 == C5;
            bool out4 = C5 == C6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == false);
                REQUIRE(out2 == true);
                REQUIRE(out3 == false);
                REQUIRE(out4 == true);
            }
        }

        WHEN("C is comparedusing !=") {
            bool out1 = C1 != C2;
            bool out2 = C2 != C3;
            bool out3 = C4 != C5;
            bool out4 = C5 != C6;

            THEN( "They all have their corresponding bool value" ) {
                REQUIRE(out1 == true);
                REQUIRE(out2 == false);
                REQUIRE(out3 == true);
                REQUIRE(out4 == false);
            }
        }

        WHEN("Two capacitors are divided") 
        {
            double out1 = C2 / C3;
            double out2 = C5 / C6;

            THEN( "They are both 1" ) 
            {
                REQUIRE(out1 == 1);
                REQUIRE(out2 == 1);
            }
        }
    }
}

SCENARIO( "create some combined Filters", "[PassFilter]" )
{
    GIVEN("Some PassFilters")
    {
        double conductor = 5;
        double inductor = 10;
        double resistor = 20;


        auto crHighPass = std::make_shared<CRHighPass>(conductor, resistor);
        auto clHighPass = std::make_shared<CLHighPass>(conductor, inductor);
        auto rlHighPass = std::make_shared<RLHighPass>(resistor, inductor);

        auto rcLowPass = std::make_shared<RCLowPass>(resistor, conductor);
        auto lcLowPass = std::make_shared<LCLowPass>(inductor, conductor);
        auto lrLowPass = std::make_shared<LRLowPass>(inductor, resistor);

        REQUIRE(fabs(crHighPass->Frequency() - 1.591549431e-3f) 
                   <= eps * fabs(crHighPass->Frequency()) );
        REQUIRE(fabs(clHighPass->Frequency() - 0.0225079079f) 
                   <= eps * fabs(clHighPass->Frequency()) );
        REQUIRE(fabs(rlHighPass->Frequency() - 0.3183098862f) 
                   <= eps * fabs(rlHighPass->Frequency()) );

        REQUIRE(fabs(rcLowPass->Frequency() - 1.591549431e-3f) 
                   <= eps * fabs(rcLowPass->Frequency()) );
        REQUIRE(fabs(lcLowPass->Frequency() - 0.0225079079f) 
                   <= eps * fabs(lcLowPass->Frequency()) );
        REQUIRE(fabs(lrLowPass->Frequency() - 0.3183098862f) 
                   <= eps * fabs(lrLowPass->Frequency()) );


        WHEN("Two PassFilters (High + Low) are connected in series") 
        {
            auto bandpass1 =
                static_unique_pointer_cast<Bandpass>(crHighPass + rcLowPass);
            auto bandpass2 = 
                static_unique_pointer_cast<Bandpass>(clHighPass + lcLowPass);
            auto bandpass3 = 
                static_unique_pointer_cast<Bandpass>(lrLowPass + rlHighPass);

            double Performance;
            bool calcPerformance = bandpass1->returnPerformance(Performance);

            THEN( "They have the sam top/bottom frequency as the single Filters") 
            {
                REQUIRE(crHighPass->Frequency() == bandpass1->returnBottomCap());
                REQUIRE(rcLowPass->Frequency() == bandpass1->returnTopCap());

                REQUIRE(clHighPass->Frequency() == bandpass2->returnBottomCap());
                REQUIRE(lcLowPass->Frequency() == bandpass2->returnTopCap());

                REQUIRE(rlHighPass->Frequency() == bandpass3->returnBottomCap());
                REQUIRE(lrLowPass->Frequency() == bandpass3->returnTopCap());

                REQUIRE(bandpass1->returnBandwidth() == 0);
                REQUIRE(bandpass1->returnResonanceFrequency() == crHighPass->Frequency());
                REQUIRE(Performance == std::numeric_limits<double>::max());
                REQUIRE(calcPerformance == 0);
            }
        }

        WHEN("Two PassFilters (same) are connected in series") 
        {
            auto CombinedLowPass =
                static_unique_pointer_cast<combinedLowPass>(rcLowPass + rcLowPass);
            auto CombinedHighPass = 
                static_unique_pointer_cast<combinedHighPass>(clHighPass + clHighPass);

            std::vector<double> frequencies1 = CombinedLowPass->Frequencies();
            std::vector<double> frequencies2 = CombinedHighPass->Frequencies();


            THEN( "They have the sam top/bottom frequency as the single Filters") 
            {
                REQUIRE(rcLowPass->Frequency() == frequencies1[0]);
                REQUIRE(rcLowPass->Frequency() == frequencies1[1]);
                REQUIRE(clHighPass->Frequency() == frequencies2[0]);
                REQUIRE(clHighPass->Frequency() == frequencies2[1]);
            }
        }
    }
}


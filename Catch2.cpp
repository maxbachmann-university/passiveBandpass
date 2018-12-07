/** @file */
/*! \mainpage TFE17-2 Test
 *
 * \section Introduction
 *
 * This Project is part of a series by Christian Ege in the informatics lesson of the DHBW Ravensburg Campus Friedrichshafen.
 * The tasks are worked out together in a team up to 3 People. In this Case Felix Bandle, Maximilian Bachmann and Florian Vetter worked together for the solution.
 * The deadline for the project is set on the 09. december 2018.
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

//#include "Filter/PassFilter.hpp"

#include <memory>
#include <math.h>

#define eps 1.19e-7f

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


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

        WHEN("Two capacitors are divided") {
            double out1 = C2 / C3;
            double out2 = C5 / C6;

            THEN( "They are both 1" ) {
                REQUIRE(out1 == 1);
                REQUIRE(out2 == 1);
            }
        }
    }
}


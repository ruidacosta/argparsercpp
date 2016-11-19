//
//  main.cpp
//  ArgParseCpp
//
//  Created by Rui Costa on 13/11/2016.
//
//

#include <iostream>
#include <termcap.h>
#include "argparsercpp.h"

int main(int argc, const char * argv[]) {
    
    // make a new ArgumentParser
    ArgParser parser("Isto é um programa de test.", "Subcommand feature not available yet.");
//    ArgParser parser;
    
    // add some arguments to search for
    parser.addArgument("-a", "this is an a");
    parser.addArgument("-b", "this is a b");
    parser.addArgument("-c", "--cactus", "this is a cactus", 1);
    parser.addArgument("-o", "--optional", "this is an o");
    parser.addArgument("-r", "--required", "this is a r", 1, false);
    parser.addArgument("--five", "this is a five",5);
    parser.addArgument("--atleast", "this is an atleast", '+');
    parser.addArgument("--any", "this is an any", '*');
    parser.addFinalArgument("output", "this is an output");
    
    // parse arguments
    parser.parse(argc, argv);
    
    // get arguments parsed
    std::string required;
    if (!parser.retrieve("required", required))
        required = "<undefined>";
    
    std::vector<std::string> fives;
    if (!(parser.retrieve("five", fives)))
        fives = {"not","defined"};
    
    for (auto it = fives.begin(); it != fives.end(); it++)
    {
        std::cout << "fives ->" << *it << std::endl;
    }
    std::cout << "required ->" << required << std::endl;
    
    return 0;
}

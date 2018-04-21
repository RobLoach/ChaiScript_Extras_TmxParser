#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include <sstream>
#include "catch.hpp"

#include <chaiscript/chaiscript.hpp>

/**
 * Load the HTTP library.
 */
#include "../include/chaiscript/extras/tmxparser.hpp"

TEST_CASE( "TmxParser functions work", "[http]" ) {
  // Build the library.
  auto tmxparserlib = chaiscript::extras::http::bootstrap();
  
  // Create the ChaiScript environment.
  chaiscript::ChaiScript chai;

  // Add the library to the ChaiScript instance.
  chai.add(tmxparserlib);

  // Run all the tests.
  chai.eval(R""(
    var map = TmxMap()

    map.ParseFile("tests/Resources/map.tmx")
  )"");

  int width = chai.eval<int>("map.GetWidth()");
  CHECK(width == 10);
}

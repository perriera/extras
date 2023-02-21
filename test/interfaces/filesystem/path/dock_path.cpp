/**
 * @brief the "MIT/X Consortium License", (adapted for EXPARX.COM)
 *
 * Copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 * Permission is hereby  granted,  free of charge,  to  any  person
 * obtaining a copy of this software and  associated  documentation
 * files   (the  "Software"),  to deal  in   the  Software  without
 * restriction, including  without  limitation the rights  to  use,
 * copy,  modify, merge,  publish,  distribute,  sublicense, and/or
 * sell copies of the  Software, and to permit persons  to whom the
 * Software  is  furnished to  do  so,  subject  to  the  following
 * conditions:
 *
 * (See LICENSE.md for complete details)
 *
 */

#include <extras/docking/DockIt.hpp>
#include <extras/filesystem/path/interface.hpp>
#include <iostream>
#include <fstream>

#include "../../../vendor/catch.hpp"
#include "../../../vendor/fakeit.hpp"

//
// https://github.com/eranpeer/FakeIt/wiki/Quickstart
//

using namespace extras;
using namespace fakeit;

// Filename _current_path_filename() /*const*/ {
//   // fs::current_path().filename();
//   throw "not implelmented yet";
// }

// Filename _path(const Filename& before) /*const*/ {
//   // fs::current_path().filename();
//   throw "not implelmented yet";
// }

// Filename _path_filename(const Filename& before) /*const*/ {
//   // fs::path(item).filename();
//   throw "not implelmented yet";
// }

// Filename _directory_iterator(const Directory& src) /*const*/ {
//   // fs::directory_iterator(_src)
//   throw "not implelmented yet";
// }


/**
 *
 * @brief Mock FakeIt AlwaysDo demonstration
 *
 */
SCENARIO("Dock extras::fs::path::Interface", "[extras::fs::path::Interface]")
{

	/**
	 * @brief 
	 * 
	 */
	auto correct_answer = "/home/perry/Downloads";
	Mold<fs::path::Interface> dock;
	fs::path::Interface &i = dock.get();
	When(Method(dock, current_path_filename))
		.AlwaysDo([&correct_answer]() {{ 
			system("pwd > /tmp/output.txt");
			std::ifstream in("/tmp/output.txt");
			std::string line;
			std::getline(in,line);
			return correct_answer; 
		} });
	When(Method(dock, actualPath))
		.AlwaysDo([&correct_answer](const Path &path) {{ 
					return correct_answer; 
		} });

	/**
	 * @brief 
	 * 
	 */
	REQUIRE(i.current_path_filename() == correct_answer);
	REQUIRE(i.actualPath("~/Downloads") == correct_answer);

	/**
	 * @brief Construct a new Verify object
	 * 
	 */
	Verify(Method(dock, actualPath));
}

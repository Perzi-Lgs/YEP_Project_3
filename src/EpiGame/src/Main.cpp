/*
** EpiGimp Copyright (C) 2020 Maxime Houis
** This program comes with ABSOLUTELY NO WARRANTY.
** This is free software, and you are welcome to redistribute it
** under certain conditions; see LICENSE for details.
*/

#include <iostream>

#include <Config/Definitions.hpp>

#include "EpiGameApp.hpp"

auto main(int ac, char **av) -> int
try {
    EpiGameApp app{ac, av};

    app.start(PROJECT_NAME);

    return SUCCESS_CODE;

} catch (const std::exception &e) {
    std::cerr << "Caught exception at main level: " << e.what() << '\n';
    return ERROR_CODE;

} catch (...) {
    std::cerr << "Caught unexpected exception at main level.\n";
    throw;
}

/**
 * @file Diagnostics.hpp
 * @author Perry Anderson (perry@exparx.com)
 * @brief DiagnosticsInterface
 * @version 0.1
 * @date 2021-11-30
 *
 * @copyright (C) November 22, 2021 EXPARX INCORPORATED
 *
 */

#ifndef _EXPARX_DIAGNOSTICS_HPP
#define _EXPARX_DIAGNOSTICS_HPP

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

#include <extras/exceptions.hpp>
#include <extras/interfaces.hpp>
#include <iostream>

namespace extras {

   /**
    * @brief DiagnosticsInterface
    *
    * This interface is intended for command line utilities
    * that wish to add a diagnostics option.
    *
    */

   using DiagnosticsLine = std::string;

   interface DiagnosticsInterface
   {
      virtual void diagnostics(DiagnosticsLine) const pure;
   };

} // namespace extras

#endif // _EXPARX_DIAGNOSTICS_HPP

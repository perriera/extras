#ifndef _EXPARX_STATUSLINE_HPP
#define _EXPARX_STATUSLINE_HPP

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

#include <extras/interfaces.hpp>
#include <extras/language/exceptions.hpp>
#include <iostream>

namespace extras {

  /**
   * @brief StatusLineInterface
   *
   */

  using StatusLineMsg = std::string;

  interface StatusLineInterface {
    virtual StatusLineMsg start(const StatusLineMsg& msg) const pure;
    virtual StatusLineMsg pass(const StatusLineMsg& msg) const pure;
    virtual StatusLineMsg fail(const StatusLineMsg& msg) const pure;
    virtual StatusLineMsg end(const StatusLineMsg& msg) const pure;
  };

  concrete class StatusLine implements StatusLineInterface {
   public:
    virtual StatusLineMsg start(const StatusLineMsg& msg) const override;
    virtual StatusLineMsg pass(const StatusLineMsg& msg) const override;
    virtual StatusLineMsg fail(const StatusLineMsg& msg) const override;
    virtual StatusLineMsg end(const StatusLineMsg& msg) const override;
  };

  /**
   * @brief start std::ostream& manipulator
   *
   */
  class start {
    friend std::ostream& operator<<(std::ostream& out, const start& obj) {
      out << StatusLine().start(obj._msg);
      return out;
    }

   public:
    start(const StatusLineMsg& msg) : _msg(msg) {}
    std::ostream& operator()(std::ostream& out) const {
      out << StatusLine().start(_msg);
      return out;
    }

   private:
    StatusLineMsg _msg;
  };

  /**
   * @brief pass std::ostream& manipulator
   *
   */
  class pass {
    friend std::ostream& operator<<(std::ostream& out, const pass& obj) {
      out << StatusLine().pass(obj._msg);
      return out;
    }

   public:
    pass(const StatusLineMsg& msg) : _msg(msg) {}
    std::ostream& operator()(std::ostream& out) const {
      out << StatusLine().pass(_msg);
      return out;
    }

   private:
    StatusLineMsg _msg;
  };

  /**
   * @brief fail std::ostream& manipulator
   *
   */
  class fail {
    friend std::ostream& operator<<(std::ostream& out, const fail& obj) {
      out << StatusLine().pass(obj._msg);
      return out;
    }

   public:
    fail(const StatusLineMsg& msg) : _msg(msg) {}
    std::ostream& operator()(std::ostream& out) const {
      out << StatusLine().fail(_msg);
      return out;
    }

   private:
    StatusLineMsg _msg;
  };

  /**
   * @brief start std::ostream& manipulator
   *
   */
  class end {
    friend std::ostream& operator<<(std::ostream& out, const end& obj) {
      out << StatusLine().end(obj._msg);
      return out;
    }

   public:
    end(const StatusLineMsg& msg) : _msg(msg) {}
    std::ostream& operator()(std::ostream& out) const {
      out << StatusLine().start(_msg);
      return out;
    }

   private:
    StatusLineMsg _msg;
  };

  /**
   * @brief PackedException
   *
   */
  concrete class StatusLineException extends AbstractCustomException {
   public:
    StatusLineException(std::string msg, const extras::WhereAmI& whereAmI)
        : AbstractCustomException(msg.c_str(), whereAmI) {}
    static void assertion(int status, const extras::WhereAmI& ref);
  };

}  // namespace extras

#endif  // _EXPARX_STATUSLINE_HPP

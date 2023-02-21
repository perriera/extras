// /**
//  * @file interface.hpp
//  * @author Owen Jones (ojones@yorku.ca), Perry Anderson (perryand@yorku.ca)
//  * @brief declation of sis::dbo::base::Interface
//  * @version 0.2
//  * @date 2022-10-31
//  *
//  * @copyright (C) Copyright 2022, York University
//  *
//  */

// #ifndef _SIS_ERROR_INTERFACE_HPP_
// #define _SIS_ERROR_INTERFACE_HPP_

// #include <iostream>
// #include <set>
// #include <extras/interfaces.hpp>

// namespace yorku_sis {

// 	namespace sis {

// 		/**
// 		 * @brief typedefs
// 		 *
// 		 */

// 		typedef enum { OK = 0 } ErrorStatusValueEnum;
// 		typedef enum { FACILITYMASK = 0xfffff000 }
// ErrorStatusMaskValueEnum; 		typedef enum { 			SEV_UNSPECIFIED = 0,
// SEV_INFORMATIONAL, 			SEV_WARNING, SEV_ERROR, SEV_FATAL 		}	SeverityLevel;
// 		typedef unsigned long ErrorStatus;

// 		namespace error {

// 			/**
// 			 * @brief namespace base
// 			 *
// 			 */

// 			interface Interface
// 			{

// 				// status value 0 is always "success"

// 				/**
// 				 * @brief isSuccess()
// 				 * @note value 0 is always "success"
// 				 * @return int
// 				 */
// 				virtual int isSuccess() const pure;

// 				/**
// 				 * @brief
// 				 *
// 				 * @return SeverityLevel
// 				 */
// 				virtual SeverityLevel severity() const pure;

// 				/**
// 				 * @brief severityText
// 				 *
// 				 * @return const std::string
// 				 */
// 				virtual const std::string severityText() const
// pure;

// 				/**
// 				 * @brief text
// 				 *
// 				 * @return const std::string
// 				 */

// 				virtual const std::string text() const pure;

// 				/**
// 				 * @brief value
// 				 *
// 				 * @return ErrorStatus
// 				 */
// 				virtual ErrorStatus value() const pure;

// 				/**
// 				 * @brief facility
// 				 *
// 				 * @return unsigned long
// 				 */
// 				virtual unsigned long facility() const pure;

// 			};

// 			/**
// 			 * @brief base::Exception
// 			 *
// 			 */

// 			concrete class Exception
// 				extends extras::AbstractCustomException {
// 			public:
// 				Exception(
// 					const std::string& msg,
// 					const extras::WhereAmI& whereAmI)
// 					: AbstractCustomException(msg.c_str(),
// 						whereAmI._file.c_str(),
// 						whereAmI._func.c_str(), whereAmI._line)
// {}
// 			};

// 		}
// 	} // end namespace
// }

// #endif // _SIS_ERROR_INTERFACE_HPP_

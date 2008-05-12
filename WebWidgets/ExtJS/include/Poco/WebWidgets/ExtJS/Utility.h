//
// Utility.h
//
// $Id: //poco/Main/WebWidgets/ExtJS/include/Poco/WebWidgets/ExtJS/Utility.h#8 $
//
// Library: ExtJS
// Package: Core
// Module:  Utility
//
// Definition of the Utility class.
//
// Copyright (c) 2007, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef ExtJS_Utility_INCLUDED
#define ExtJS_Utility_INCLUDED


#include "Poco/WebWidgets/ExtJS/ExtJS.h"
#include "Poco/WebWidgets/Form.h"
#include "Poco/WebWidgets/LookAndFeel.h"
#include <ostream>


namespace Poco {
namespace WebWidgets {

	class View;
	class Cell;
	class Renderable;

namespace ExtJS {


class ExtJS_API Utility
	/// Utility offers static helper functions
{
public:
	static void initialize(LookAndFeel::Ptr ptr);
		/// Initializes the LookAndFeel object to use ExtJS renderers

	static LookAndFeel& getDefaultRenderers();
		/// Returns the defaultrenderers;

	static const std::string& getTmpID();
		/// Gets the id of the tmp div element

	static Form::Ptr insideForm(const View* pChild);

	static Form::Ptr insideForm(const Cell* pChild);

public:
	static void writeRenderableProperties(const Renderable* pRend, std::ostream& ostr);
		/// Writes renderable properties (mostyl the id)

	static void writeCellProperties(const Cell* pCell, std::ostream& ostr, bool writeId = true);
		/// Writes cell properties except the value and the tooltip (tooltip is not supported by most ExtJS form fields)

	static void writeRenderableProperties(const std::string& id, std::ostream& ostr);
		/// Writes renderable properties (mostyl the id)

	static void writeCellProperties(const std::string& id, 
								const std::string& disabled, 
								const std::string& name, 
								const std::string& width,
								const std::string& height,
								std::ostream& ostr);
		/// Writes cell properties

	static std::string safe(const std::string& str);
		/// Escapes characters that could be dangerous in JS

	static std::string convertPocoDateToPHPDate(const std::string& dateTimeFmt);
		/// Converts a poco date time format string to its PHP/extjs equivalent

private:
	static void convertPocoDateToPHPDate(char in, std::string& result);
	static void convertPHPDateToPocoDate(char in, std::string& result);
	static void escapeCharForPHP(char in, std::string& result);
	static LookAndFeel::Ptr createDefault();

private:
	Utility();
	~Utility();
	Utility(const Utility&);
	Utility& operator0(const Utility&);
};


} } } // namespace Poco::WebWidgets::ExtJS


#endif // ExtJS_Utility_INCLUDED
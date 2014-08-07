/**
* @file      PrettyPrinter.cpp
* @copyright (c) 2014 by Petr Zemek (s3rvac@gmail.com) and contributors
* @license   BSD, see the @c LICENSE file for more details
* @brief     Implementation of the PrettyPrinter class.
*/

#include "PrettyPrinter.h"

#include "BInteger.h"

namespace bencoding {

/**
* @brief Constructs a printer.
*/
PrettyPrinter::PrettyPrinter() = default;

/**
* @brief Creates a new printer.
*/
std::unique_ptr<PrettyPrinter> PrettyPrinter::create() {
	return std::unique_ptr<PrettyPrinter>(new PrettyPrinter());
}

/**
* @brief Returns a pretty representation of @a data.
*/
std::string PrettyPrinter::getPrettyRepr(std::shared_ptr<BItem> data) {
	prettyRepr.clear();
	data->accept(this);
	return prettyRepr;
}

void PrettyPrinter::visit(BInteger *bInteger) {
	prettyRepr += std::to_string(bInteger->value());
}

} // namespace bencoding
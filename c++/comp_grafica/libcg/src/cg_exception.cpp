#include "cg_exception.h"

CGException::CGException(const QString& error_msg) : error_message(error_msg)
{
}

const QString& CGException::getErrorMessage() const
{
    return this->error_message;
}

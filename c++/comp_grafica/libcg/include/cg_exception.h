#ifndef CG_EXCEPTION_H
#define CG_EXCEPTION_H

#include<QString>

/**
 *  Class that defines exception on the cg library.
 */
class CGException
{
private:
    QString error_message;

public:
    /**
     *  \brief Exception constructor.
     *  Constructs a wireframe exception.
     *  @param error_msg - Message specifying the error that occured.
     */
    CGException(const QString& error_msg);

    /**
     *  Get error message.
     *  @return - the error message.
     */
    const QString& getErrorMessage() const;
};

#endif // CG_EXCEPTION_H

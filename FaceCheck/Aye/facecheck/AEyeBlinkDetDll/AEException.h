#ifndef __AEEXCEPTION_H__
#define __AEEXCEPTION_H__

#include <exception>
#include <string>

class AEException:public std::exception
{
public:
	 explicit AEException( const std::string& message ) throw();
	 virtual ~AEException() throw();
	 virtual const char* what() const throw(); //返回异常的描述信息
private:
	std::string message_;

};


#endif //__AEEXCEPTION_H__

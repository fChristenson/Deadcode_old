//
//  Error.hpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

#ifndef Error_hpp
#define Error_hpp

struct Error {
    const char* message;
    int lineNumber;
    Error(const char* message, int lineNumber) {
        this->message = message;
        this->lineNumber = lineNumber;
    }
};
#endif /* Error_hpp */

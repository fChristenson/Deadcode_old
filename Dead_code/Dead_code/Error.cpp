//
//  Error.cpp
//  Dead_code
//
//  Created by Fredrik Christenson on 30/08/16.
//  Copyright © 2016 Fredrik Christenson. All rights reserved.
//

struct Error {
    const char* message;
    int lineNumber;
    Error(const char* message, int lineNumber) {
        this->message = message;
        this->lineNumber = lineNumber;
    }
};
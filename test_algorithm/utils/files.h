//
// Created by ubuntu on 11/17/19.
//

#ifndef TEAT_FILES_H
#define TEAT_FILES_H

#include <fstream>

void readfile(file_path){
    fstream input;
    input.open(file_path, ios::in);

}

void writefile(file_path){
    fstream output;
    output.open(file_path, ios::out)
}

#endif //TEAT_FILES_H

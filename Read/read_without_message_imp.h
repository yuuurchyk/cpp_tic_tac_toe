#ifndef READ_WITHOUT_MESSAGE_IMP_H_
#define READ_WITHOUT_MESSAGE_IMP_H_

namespace Read{
    template<class T> T read_without_message(std::istream &input){
        while(true){
            std::string line; getline(input, line);
            std::stringstream line_strm(line);

            T result;
            char tmp;

            if
            (
                (line_strm >> result) &&
                line_strm.rdbuf()->in_avail() == 0
            )
                return result;
        }
    }
}

#endif
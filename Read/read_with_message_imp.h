#ifndef READ_WITH_MESSAGE_IMP_H_
#define READ_WITH_MESSAGE_IMP_H_

namespace TicTacToe{
    template<class T> T read_with_message(
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    ){
        output << prompt_msg;
        while(true){

            std::string line; getline(input, line);
            std::stringstream line_strm(line);

            T result;

            if
            (
                (line_strm >> result) &&
                line_strm.rdbuf()->in_avail() == 0
            )
                return result;
            else
                output << fail_msg;
        }
    }
}

#endif
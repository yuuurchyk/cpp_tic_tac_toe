#ifndef READ_PAIR_WITH_MESSAGE_IMP_H_
#define READ_PAIR_WITH_MESSAGE_IMP_H_

namespace Read{
    template<class F, class S> std::pair<F, S> read_pair_with_message
    (
        std::istream &input,
        std::ostream &output,
        std::string prompt_msg,
        std::string fail_msg
    )
    {
        output << prompt_msg;
        
        while(true){
            std::string line; getline(input, line);
            std::stringstream line_strm(line);

            F first;
            S second;

            if
            (
                (line_strm >> first >> second) &&
                line_strm.rdbuf()->in_avail() == 0
            )
                return std::make_pair(first, second);
            else
                output << fail_msg;
        }
    }
}

#endif
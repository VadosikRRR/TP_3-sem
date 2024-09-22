// У string нет в конце '\0'
struct string {
    string(char * p_new_text = "", int start_amount_of_memory = 64) : 
            used_amount_of_memory(0), 
            amount_of_memory(start_amount_of_memory) {
        
        p_text = new char[start_amount_of_memory];
        check_memory(length(p_new_text));
        copy_chars(p_text, p_new_text);
        used_amount_of_memory += length(p_new_text);
    }

    string operator+=(string add_text) {
        check_memory(add_text.used_amount_of_memory);
        copy_chars(p_text + used_amount_of_memory, add_text.p_text + add_text.used_amount_of_memory);
        used_amount_of_memory += add_text.used_amount_of_memory;
    }

    void find(string text) {
        
    }

    private:
        void check_memory(int add_memory) {
            if (add_memory + used_amount_of_memory > amount_of_memory) {
                double_memory();
            }
        }
//
        void double_memory() {
            char * tmp = p_text; 
            p_text = new char[2 * amount_of_memory];
            copy_chars(p_text, tmp, used_amount_of_memory);
            delete [] tmp;
        }

        int length(char * p_char_text) {
            int cnt = 0;
            while (p_char_text[cnt] !='\0') {
                cnt++;
            }

            return cnt;
        }

        void copy_chars(char * p_place_of_insertion, char * p_copy_char, int len_copy_char = -1) {
            for (int i = 0; p_copy_char[i] != '\0' && i != len_copy_char; i++) {
                p_place_of_insertion[i] = p_copy_char[i];
            }
        }

        int used_amount_of_memory;
        int amount_of_memory;
        char * p_text;
};

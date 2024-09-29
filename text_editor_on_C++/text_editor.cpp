#include <iostream>
using namespace std;

struct text_editor {
    explicit text_editor(int start_amount_of_memory = 1024) : files_name("") {
        is_correct_number(start_amount_of_memory);
        text = "";
    }

    // creates a new file named name_of_file
    void create(string name_of_file) {
        update_memory();
        files_name = name_of_file;
    }

    // loads file named name_of_file
    void load(string name_of_file) {

    }

    // adds new text in the end
    void add(string new_text) {
        is_there_file();
        text += new_text;
    }

    // moves cursor to position "position"
    void move(int position) {

    }

    // inserts the text to position "position"
    void insert(int position, string text) {

    } 

    // puts the text to now positions cursor
    void put(string text) {

    }
    
    // deletes the left symbol of cursor
    void del() {

    }

    // deletes the count_of_symbols left symbols of cursor
    void del(int count_of_symbols) {

    }

    // moves cursor to count_of_words word to left
    void movelw(int count_of_words) {

    }

    // moves cursor to count_of_words word to right
    void moverw(int count_of_words) {

    }

    // Translates the word under the cursor to uppercase
    void upcase() {

    }

    // Translates the word under the cursor to lowercase
    void lowcase() {

    }

    //replaces previous_text this new_text
    void replace(string previous_text, string new_text) {
        
    }

    // finds the text in all text
    void find(string text) {

    }

    // saves this file with name_of_file
    void save(string name_of_file) {

    }

    private:
        void update_memory() {
            text = "";
            files_name = "";
        }

        bool is_there_file() {
            return files_name != "";
        }

        bool is_free_memory() {

        }

        bool is_correct_number(int number) {
            return number > 0;
        }

        string files_name;
        string text;
};


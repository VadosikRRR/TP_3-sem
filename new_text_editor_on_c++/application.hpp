class Application {
public:
    void Add(Document*);
};

class Document {
public:
    Document(const char* name);
    void Open();
    void Paste();
};

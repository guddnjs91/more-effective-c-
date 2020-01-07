
class String {
public:
    String(const char *value = "");
    String& operator=(const String& rhs);

private:
    char *data;
};


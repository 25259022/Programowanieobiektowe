#include <string>
#include <regex>

using namespace std;

/// Cell decides about what type of data is stored in each.
/**
* consists of 2 virtual functions.
  * @param[in] setValue - Checks if cell type is compatible with provided data. if so writes it to cell
 * @param[out] getValue - returns correct type of stored data inside cell
 */

class Cell
        {
public:

    virtual string getValue() = 0;

    virtual void setValue(string value) = 0;
};


class IntCell : public Cell
        {
    int Value = 0;

public:
    string getValue()
    {
        return to_string(Value); //////
    };

    void setValue(string value)
    {
        regex test("^[\n][0-9]*$|^[0-9]*$");
        if (regex_match(value, test)) {
            Value = stoi(value);
        } else { cout << "Proba zapisu string do komorki int ERR"; }
    };

};


class StringCell : public Cell
        {
    string Value = "-";

public:
    string getValue()
    {
        return Value;
    };

    void setValue(string value)
    {
        Value = value;
    };

};
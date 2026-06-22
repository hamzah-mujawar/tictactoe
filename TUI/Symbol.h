#ifndef SYMBOL_H
#define SYMBOL_H

class Symbol
{
public:
    Symbol(char symbol);
    const char& getSymbol() const { return m_symbol; }

private:
    char m_symbol{};
};

#endif

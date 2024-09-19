#pragma once

#include <string>

namespace catching_std_exceptions {

class Animal
{
public:
  Animal(const std::string n)
    : m_name(n) {}

  Animal() = default;
  virtual ~Animal() {}
  virtual void breathe() const {}

protected:
  std::string m_name;
};

class Feline : public Animal
{
public:
  Feline(const std::string n)
    : Animal(n) {}

private:
  int speed;
};

}// namespace catching_std_exceptions
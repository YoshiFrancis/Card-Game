#include <iostream>

class Testing {

  public:
    Testing() {
      std::cout << "Hello World\n";
    }


    inline void sayHello() const { std::cout << "Hello World\n"; };
};

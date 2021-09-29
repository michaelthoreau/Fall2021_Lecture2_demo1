#include <mbed.h>

// prototype for assembly add
extern "C" uint32_t add_asm(uint32_t a, uint32_t b);

// add values in c style
uint32_t add_c(uint32_t a, uint32_t b) {
  uint32_t c = 7;
  return a+b+c;
}

// add by reference - load store operations used
uint32_t add_by_ref(uint32_t* a, uint32_t* b) {
  return (*a)*(*b);

}

int main() {

  uint32_t integer1 = 2;
  uint32_t integer2 = 3;


  while(1) {
    // add using c function
    uint32_t result = add_c(integer1, integer2);
    printf("result:  %d  \n", result);

    //add using assembly function
    uint32_t result_asm = add_asm(integer1, integer2);
    printf("result_asm:  %d  \n", result_asm);

    // add by reference
    uint32_t result_ref = add_by_ref(&integer1, &integer2);
    printf("result_ref:  %d  \n", result_ref);

  }
}
#include <stdio.h>

int main(void)
{
  unsigned int nu = 300000000; /* int 为32位 */
  short end = 200;             /* short为16位系统 */
  long big = 65537;
  long long verybig = 12345678908642;
  
  printf("un = %u and not %d\n", nu, nu);
  printf("end = %hd and %d\n", end, end);
  printf("big = %ld and not %hd\n", big, big);
  printf("verybig = %lld and not %ld\n", verybig, verybig);
  return 0;
}

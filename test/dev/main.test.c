#include <check.h>
#include <stdlib.h>

Suite* stringTestSuite();
Suite* commandBufferTestSuite();

int main() {
  int numberFailed;
  SRunner *sr;

  sr = srunner_create( stringTestSuite() );
  srunner_add_suite( sr, commandBufferTestSuite() );

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

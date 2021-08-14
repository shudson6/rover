#include <check.h>
#include <stdlib.h>

Suite* stringTestSuite();
Suite* commandBufferTestSuite();
Suite* commandTestSuite();

int main() {
  int numberFailed;
  SRunner *sr;

  sr = srunner_create( stringTestSuite() );
  srunner_add_suite( sr, commandBufferTestSuite() );
  srunner_add_suite( sr, commandTestSuite() );

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

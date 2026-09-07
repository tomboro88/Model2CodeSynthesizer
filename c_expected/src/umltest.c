/**
 * @file 
 * 
 * @brief The umltest package source file.
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "umltest.h"
#include <Tkind.h>
#include <TJunction.h>
#include <plogger.h>
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Non-private function prototypes.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void umltest_umltest_record(plogger_logger_t* const p_obj,\
                                   const char* const p_str);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @return 
 */
int
main(void)
{
    printf("Initialize my_ctest:\n");
    const plogger_logger_vt_t logger_funcs = {.p_record = umltest_umltest_record};
    plogger_logger_t local_logger = {.p_vtable = &logger_funcs};
    tkind_ctest_t my_ctest = {0};
    tkind_ctest_init(&my_ctest, &local_logger);
    tkind_cbase1_setuintprop(&my_ctest.cbase1, 123);
    tkind_cbase2_setfloatprop(&my_ctest.cbase2, 13.0f);
    printf("\nPolymorphism example:\n"
           "The result of getuintprop: %d\n"
           "The result of getfloatprop: %f\n",
           tkind_cbase1_getuintprop(&my_ctest.cbase1),
           tkind_cbase2_getfloatprop(&my_ctest.cbase2));
    printf("Send and process the a event in my_ctest:\n");
    tkind_ctest_a(&my_ctest);
    tkind_ctest_fetch_event(&my_ctest);
    tkind_ctest_dispatch_event(&my_ctest);
    tkind_ctest_release_event(&my_ctest);
    
    printf("\n\nInitialize my_jtest:\n");
    tjunction_jtest_t my_jtest = {0};
    tjunction_jtest_init(&my_jtest, &local_logger);
    printf("Send and process the a event in my_jtest:\n");
    tjunction_jtest_a(&my_jtest);
    tjunction_jtest_fetch_event(&my_jtest);
    tjunction_jtest_dispatch_event(&my_jtest);
    tjunction_jtest_release_event(&my_jtest);
    
    return EXIT_SUCCESS;
}

/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/**
 * @param [in,out] p_obj 
 * @param [in] p_str 
 */
static void
umltest_umltest_record(plogger_logger_t* const p_obj, const char* const p_str)
{
    (void) p_obj;
    (void) puts(p_str);
}

/*** end of file ***/
